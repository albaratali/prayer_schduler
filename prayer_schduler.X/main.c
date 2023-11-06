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
    
    while (1) {
        // write application code here
    }

}
