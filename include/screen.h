/* 
 * File:   screen.h
 * Author: celino
 *
 * Created on 29 mai 2016, 12:47
 */

#ifndef SCREEN_H
#define	SCREEN_H

#include <types.h>

#define SC_VIDEOMEM_START   0xb8000
#define SC_NBCOLS           80
#define SC_NBROWS           25

char*                       _sc_video_mem;
uint16                      _sc_cursor;

void clean_screen();

/*
 * Print a single character on the screen at speciefied position and color
 * This function is meant to be used only by screen.c
 */
void _sc_putchar_at(
        char        _c,
        uint16      _pos,
        byte        _color
        );


void _sc_jump_line();

/*
 * Print a single character on the screen at the current cursor position and on
 * a specifeied color
 * This function is meant to be public
 */
void print_char(
        char        _c,
        byte        _color
        );

/*
 * Print a C string (ie: ending with '\0') to the screen on a specified color
 */
void print(
        char*       _cstring,
        byte        _color
        );

#endif	/* SCREEN_H */

