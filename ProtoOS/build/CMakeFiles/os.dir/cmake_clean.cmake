file(REMOVE_RECURSE
  "CMakeFiles/os"
  "boot/bin/boot_kernel.bin"
  "boot/bin/os.img"
  "kernel/bin/kernel_padded.bin"
  "kernel/obj/kernel.o"
  "kernel/obj/kernel_entry.o"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/os.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
