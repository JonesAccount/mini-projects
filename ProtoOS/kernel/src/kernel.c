// kernel.c - minimal 32-bit kernel

int main(void) {
        char *video = (char *) 0xb8000;
        const char *msg = "ProtoOS";
        int offset = (10 * 80) * 2; // row and column

        int i = 0;
        while (msg[i] != 0) {
                video[offset + i * 2] = msg[i];
                video[offset + i * 2 + 1] = 0x04; // red on black
                i++;
        }

        while (1) {} // halt forever
}