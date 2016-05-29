#include <screen.h>
#include <keyboard.h>

kmain() {
    clean_screen();
    print("Enter something : ", 0x05);

    while (1) {

        print_char(getKeyPressed(), 0x04);
    }


}
