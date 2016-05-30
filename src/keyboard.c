#include <keyboard.h>


char _kb_azerty_scancode[256] = {0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ')', '=', ' ',
    '\t', 'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '^', '$', '\n', ' ', 'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'ù', '*',
    ' ', '<', 'w', 'x', 'c', 'v', 'b', 'n', ',', ';', ':', '!', ' ', ' ', ' ', ' ', ' '};

byte _kb_get_input() {

    if (inportb(0x64) & 0x01) {
        return inportb(0x60);
    } else return 0x0;
}

char getKeyPressed() {
    byte key = _kb_get_input();
    return _kb_azerty_scancode[key];

    return 0;


}