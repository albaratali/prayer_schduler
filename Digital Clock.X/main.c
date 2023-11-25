/*
 * File:   main.c
 * Author: faizan
 *
 * Created on November 6, 2023, 10:29 PM
 */


#include "main.h"

#pragma config WDTE =OFF // watchdog timer disabled

unsigned char sec=0,min=0,hour=0;
int operation_flag= TURN_ON;

static void init_config(void) {
    // initialization of CLCD Module
    init_clcd();
    
    init_matrix_keypad();
    
    //Initialization of MKP module
    init_timer2();
    
    PEIE=1;
    GIE=1;
}

void main(void) {
    init_config(); // calling initializing function
    unsigned char key;
    static int reset_flag=MODE_RESET;
   
 
    while (1) {
        // write application code here
        key=read_matrix_keypad(STATE);
       
        switch(operation_flag)
        {
            case TURN_ON:
                turn_on();
                clear_screen();
                operation_flag= SET_TIME;
                break;
            case SET_TIME:
                set_time(key,reset_flag);
                reset_flag=RESET_NOTHING;
                break;
            case CLOCK_SCREEN:
                
                clock_screen();
                break;
        }
                
                    
    }

}

void clock_screen (void)
{
    clcd_print("TIME:",LINE2(0));
    //hour
    clcd_putch(hour/10 + '0',LINE2(6));
    clcd_putch(hour%10 + '0',LINE2(7));
    clcd_putch(':',LINE2(8));
    //min
    clcd_putch(min/10 + '0',LINE2(9));
    clcd_putch(min%10 + '0',LINE2(10));
    clcd_putch(':',LINE2(11));
    // sec
    clcd_putch(sec/10 + '0',LINE2(12));
    clcd_putch(sec%10 + '0',LINE2(13));
        
}
void set_time(unsigned char key,int reset_flag)
{
    static unsigned char key_count,blink_pos,blink,wait;
    
    if(reset_flag==MODE_RESET)
    {
    key_count=0;
    sec=0;
    min=0;
    hour=0;
    blink_pos=0;
    blink=0;
    key=ALL_RELEASED;
    clcd_print("SET TIME(H:M:S)",LINE1(0));
    clcd_print("TIME:",LINE2(0));
    clcd_print("*:CLEAR  #:ENTER",LINE4(0)); 
    }
    
    if((key!= '*') && (key != '#') && (key != ALL_RELEASED))
    {
        key_count++;
        if (key_count <= 2)
        {
            sec = sec*10 + key;
            blink_pos = 0;
        }
        else if ((key_count>2) && (key_count<=4))
        {
            min=min*10 +key;
            blink_pos=1;
        }
        else if ((key_count>4) && (key_count<=6))
        {
            hour=hour*10 +key;
            blink_pos=2;
        }    
    }
    else if (key=='*')//clear
    {
        if(blink_pos==0)
        {
            sec=0;
            key_count=0;
        }
        else if (blink_pos==1)
        {
            min=0;
            key_count=2;
        }
        else if (blink_pos==2)
        {
            hour=0;
            key_count=4;
        }
    }
    else if (key=='#')//Enter
    {
        clear_screen();
        operation_flag = CLOCK_SCREEN;
        TMR2ON =1;
    }
    
    if(wait++ ==15)//blink
    {
        wait=0;
        blink =! blink;
         
        //hour
        clcd_putch(hour/10 + '0',LINE2(6));
        clcd_putch(hour%10 + '0',LINE2(7));
        clcd_putch(':',LINE2(8));

        
        clcd_putch(min/10 + '0',LINE2(9));
        clcd_putch(min%10 + '0',LINE2(10));
        clcd_putch(':',LINE2(11));
        // sec
        clcd_putch(sec/10 + '0',LINE2(12));
        clcd_putch(sec%10 + '0',LINE2(13));
  
    }
    
    if(blink)
    {
        switch(blink_pos)
        {
            case 2:
                clcd_print("  ",LINE2(6));
            case 1:
                clcd_print("  ",LINE2(9));
            case 0:
                clcd_print("  ",LINE2(12));
        } 
    }
   
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
