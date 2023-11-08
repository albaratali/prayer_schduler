#include <xc.h>
#include "main.h"

extern unsigned char sec,min,hour; // sec=15
void __interrupt() isr(void)
{
    static unsigned int count = 0;
    
    if (TMR2IF == 1)
    {    
        if (++count == 1250) // 1sec
        {
            count = 0;
            sec++;
            
            if (sec==60) 
            {
                min++;
                sec=0;
                
            }
            if(min==60)
            {
                hour++;
                min=0;
            }
            
     
        }
        
        TMR2IF = 0;
    }
}