/* 
 * File:   keyboard.h
 * Author: celino
 *
 * Created on 29 mai 2016, 17:18
 */

#ifndef KEYBOARD_H
#define	KEYBOARD_H

#include <system.h>

char _kb_azerty_scancode[256];

byte _kb_get_input();
char getKeyPressed();

#endif	/* KEYBOARD_H */

