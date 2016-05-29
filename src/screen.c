#include <screen.h>

uint16 _sc_cursor      = 0;
char*  _sc_video_mem   = (char*) SC_VIDEOMEM_START;


void _sc_putchar_at(char _c, uint16 _pos, byte _color)
{
    _sc_video_mem[_pos*2]       = _c;
    _sc_video_mem[_pos*2+1]     = _color;
}