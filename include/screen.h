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

void _sc_putchar_at(
        char        _c,
        uint16      _pos,
        byte        _color
        );

#endif	/* SCREEN_H */

