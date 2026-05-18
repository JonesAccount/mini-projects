cmake_minimum_required(VERSION 3.10)
project(myos C ASM_NASM)

set(ASM nasm)
set(CC x86_64-elf-gcc)
set(LD x86_64-elf-ld)

# — Boot sector (flat binary) —
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/boot/bin/boot_kernel.bin
    COMMAND ${ASM} -f bin ${CMAKE_CURRENT_SOURCE_DIR}/boot/asm/boot_kernel.asm
            -o ${CMAKE_CURRENT_BINARY_DIR}/boot/bin/boot_kernel.bin
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/boot/asm/boot_kernel.asm
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# — Kernel entry (elf32) —
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/kernel/obj/kernel_entry.o
    COMMAND ${ASM} -f elf32 ${CMAKE_CURRENT_SOURCE_DIR}/kernel/src/kernel_entry.asm
            -o ${CMAKE_CURRENT_BINARY_DIR}/kernel/obj/kernel_entry.o
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/kernel/src/kernel_entry.asm
)

# — Kernel C code (elf32) —
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/kernel/obj/kernel.o
    COMMAND ${CC} -ffreestanding -m32 -Wno-main -c
            ${CMAKE_CURRENT_SOURCE_DIR}/kernel/src/kernel.c
            -o ${CMAKE_CURRENT_BINARY_DIR}/kernel/obj/kernel.o
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/kernel/src/kernel.c
)

# — Link kernel binary + pad to 15 sectors —
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/kernel/bin/kernel_padded.bin
    COMMAND ${LD} -m elf_i386 -Ttext 0x1000 --oformat binary
            ${CMAKE_CURRENT_BINARY_DIR}/kernel/obj/kernel_entry.o
            ${CMAKE_CURRENT_BINARY_DIR}/kernel/obj/kernel.o
            -o ${CMAKE_CURRENT_BINARY_DIR}/kernel/bin/kernel.bin
    COMMAND dd if=/dev/zero of=${CMAKE_CURRENT_BINARY_DIR}/kernel/bin/kernel_padded.bin
            bs=512 count=15 status=none
    COMMAND dd if=${CMAKE_CURRENT_BINARY_DIR}/kernel/bin/kernel.bin
            of=${CMAKE_CURRENT_BINARY_DIR}/kernel/bin/kernel_padded.bin conv=notrunc status=none
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/kernel/obj/kernel_entry.o
            ${CMAKE_CURRENT_BINARY_DIR}/kernel/obj/kernel.o
)

# — Combine boot sector + padded kernel → os.img —
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/boot/bin/os.img
    COMMAND cat ${CMAKE_CURRENT_BINARY_DIR}/boot/bin/boot_kernel.bin
            ${CMAKE_CURRENT_BINARY_DIR}/kernel/bin/kernel_padded.bin
            > ${CMAKE_CURRENT_BINARY_DIR}/boot/bin/os.img
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/boot/bin/boot_kernel.bin
            ${CMAKE_CURRENT_BINARY_DIR}/kernel/bin/kernel_padded.bin
)

# — The final target that builds everything —
add_custom_target(os ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/boot/bin/os.img
)