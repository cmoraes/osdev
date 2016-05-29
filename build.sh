nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c src/*.c --freestanding -I"include"
gcc -m32 -c kernel.c -o kc.o -ffreestanding -I"include"
ld -m elf_i386 -T link.ld -o kernel.bin *.o
qemu-system-i386 -kernel kernel.bin &
cp kernel.bin iso/boot/kernel.bin
grub-mkrescue -o iso.iso iso
