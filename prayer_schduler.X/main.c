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
 
}

void main(void) {
    init_config(); // calling initializing function
   
    int operation_flag= TURN_ON;
    while (1) {
        // write application code here
       
        switch(operation_flag)
        {
            case TURN_ON:
                turn_on();
                clear_screen();
                operation_flag= SET_TIME;
                break;
            case SET_TIME:
                set_time();
                break;
        }
                
                    
    }

}

void set_time(void)
{
    clcd_print(" Time- ",LINE1(0));
}

void clear_screen(void)
{
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
}


void turn_on(void)
{
    unsigned char i;
    
    for(i=0;i<16;i++)
    {
        clcd_putch(BAR,LINE1(i));
        __delay_ms(50);
    }
    
    clcd_print("     TURN ON   ",LINE2(0));
    
    for(i=0;i<16;i++)
    {
        clcd_putch(BAR,LINE4(i));
        __delay_ms(50);
    }
    __delay_ms(100);
}
