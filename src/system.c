#include <system.h>

byte inportb (uint16 _port)
{
    	byte rv;
    	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    	return rv;
}

void outportb (uint16 _port, byte _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}
