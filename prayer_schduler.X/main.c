/*
 * File:   main.c
 * Author: faizan
 *
 * Created on November 6, 2023, 10:29 PM
 */


#include "main.h"

#pragma config WDTE =OFF // watchdog timer disabled

static void init_config(void) {
    // initialization of CLCD Module
    init_clcd();
    
    //Initialization of MKP module
    init_matrix_keypad();
    
    init_timer2();
    
    PEIE=1;
    GIE=1;
    
}

void main(void) {
    init_config(); // calling initializing function
    unsigned char key;
    int operation_flag= TURN_ON;
    while (1) {
        // write application code here
        key=read_matrix_keypad(STATE);
        switch(operation_flag)
        {
            case TURN_ON:
                turn_on();
                break;
        }
                
                    
    }

}

void turn_on(void)
{
    unsigned char i;
    
    for(i=0;i<16;i++)
    {
        clcd_putch(BAR,LINE1(i));
        __delay_ms(100);
    }
    
    clcd_print("  TURN ON   ",LINE2(0));
    
    for(i=0;i<16;i++)
    {
        clcd_putch(BAR,LINE4(i));
        __delay_ms(100);
    }
    __delay_ms(100);
}
