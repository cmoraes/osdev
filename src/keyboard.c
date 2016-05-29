#include <keyboard.h>

byte _kb_get_input() {

    if (inportb(0x64) & 0x01) {
        return inportb(0x60);
    } else return 0x0;
}

char getKeyPressed() {
    byte key = _kb_get_input();
    
    switch(key)
    {
        case 1:
            return 27;
            break;
        case 16:
            return 'a';
            break;
        case 17:
            return 'z';
            break;
        case 18:
            return 'e';
            break;
        default:
            break;
    }

    // Digits:
    if (key < 11 && key > 0) {
        return 0x30 + key - 1;
    }
    if (key == 11) return 0x30;
    
    //Enter Key:
    if (key == 28) return '\n';
    
    

    return 0;
    

}