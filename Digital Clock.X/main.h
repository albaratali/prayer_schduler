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
#include "matrix_keypad_1.h"
#include "timers_1.h"

#define TURN_ON             0x01
#define SET_TIME            0x02
#define TIME_SCREEN         0x03
#define CLOCK_SCREEN        0x04
#define MODE_RESET          0x05
#define RESET_NOTHING       0x06

void turn_on(void);
void clear_screen(void);
void set_time(unsigned char key,int reset_flag);
void clock_screen (void);

#endif	/* MAIN_H */

