/*
 * File:   main.c
 * Author: basti
 *
 * Created on March 12, 2025, 10:04 PM
 */


#include <xc.h>

#include "GLCD_config.h"
#include "utils.h"

#include "Libraries/LCD/GLCD_library.h"

void __init(void);

void main(void) {
    __init();
    
    GLCD_Text2Out(1, 1, "MCON SoSe 25");
    
    // TODO (basti):
    /*
     * - add excercises for students, mainly C programming stuff
     * - add comments for clarification
     * - add excercise for simulator (stopping a for loop?)
     */
    while(1){
        sleep(250);
        toggle_LED(1);
        sleep(250);
        toggle_LED(2);
        sleep(250);
        toggle_LED(3);
        sleep(250);
        toggle_LED(4);
        sleep(250);
        toggle_LED(0);
    }
    
    return;
}

void __init(void){
    // Set Oscillator Frequency to 4MHz (you will use this setting a lot!)
    OSCCON = 0x50;
    // Enable LCD
    GLCD_Init();
    
    // Configure LEDs
    init_LEDs();
}
