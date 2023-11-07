/* 
 * File:   main.h
 * Author: faizan
 *
 * Created on November 6, 2023, 10:38 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include "clcd.h"
#include "matrix_keypad.h"
#include "timers.h"

#define TURN_ON             0x01
#define SET_TIME            0x02
#define TIME_SCREEN         0x03

void turn_on(void);
void clear_screen(void);
void set_time(void);

#endif	/* MAIN_H */

