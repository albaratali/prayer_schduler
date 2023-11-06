/*
 * File:   main.c
 * Author: faizan
 *
 * Created on November 6, 2023, 10:29 PM
 */


#include <xc.h>

#pragma config WDTE =OFF // watchdog timer disabled

static void init_config(void) {
    // write your initialization code here
}

void main(void) {
    init_config(); // calling initializing function
    while (1) {
        // write application code here
    }

}
