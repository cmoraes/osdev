#include <screen.h>

uint16 _sc_cursor = 0;
char* _sc_video_mem = (char*) SC_VIDEOMEM_START;

void clean_screen() {
    int i;
    for (i = 0; i < 0xfa0; ++i)
        _sc_video_mem[i] = 0;
}

void _sc_putchar_at(char _c, uint16 _pos, byte _color) {
    _sc_video_mem[_pos * 2] = _c;
    _sc_video_mem[_pos * 2 + 1] = _color;
}

void print_char(char _c, byte _color) {

    switch (_c) {
        case 0:
            break;
        case '\n':
            _sc_jump_line();
            break;
        case '\t':
            print_char(' ',0);
            print_char(' ',0);                    
            print_char(' ',0);
            print_char(' ',0);
            break;
        default:
            _sc_putchar_at(_c, _sc_cursor, _color);
            _sc_cursor++;
            if (_sc_cursor > 2000) {
                _sc_cursor = 0; // go back to the start
                clean_screen();
            }
            break;
    }

}

void print(char* _cstring, byte _color)
{
    int i = 0;
    while(_cstring[i] != '\0' && i < 0xfffff)
    {
        print_char(_cstring[i],_color);
        ++i;
    }
    
}
void _sc_jump_line() {
    _sc_cursor = (_sc_cursor + SC_NBCOLS) - _sc_cursor % SC_NBCOLS;
    if (_sc_cursor > 2000) {
        _sc_cursor = 0; // go back to the start
        clean_screen();
    }
}