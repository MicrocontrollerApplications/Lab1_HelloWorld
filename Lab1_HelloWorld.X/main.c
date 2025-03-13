/*
 * File:   main.c
 * Author: Sebastian Moosbauer
 *
 * Created on March 12, 2025, 10:04 PM
 */


#include <xc.h>

#include "Libraries/LCD/GLCD_library.h"

#include "GLCD_config.h"
#include "utils.h"

// function prototype. Used to publish the functions name. It can then
// be implement elsewhere. In case of this function it is implemented 
// below main(), to increase readability.
void __init(void);

// main code, i.e. the application itself
void main(void) {
    // Execute initialization of Microcontroller (will be explained soon!)
    __init();
    
    // Nop() means No Operation. Basically this is an empty line of code.
    // But you can set a breakpoint here.
    Nop();
    GLCD_Text2Out(1, 1, "MCON SoSe 25");
    Nop();
    
    // while(1) is an endless loop. It's a very common part of microcontroller
    // code, as it prevents the application from termination. Without it, the
    // application would terminate after one execution and the microcontroller
    // would restart. Not very useful...
    while(1){
        // Mhmm, what could be the purpose of this function?
        sleep(250);
        // What is this function doing? Try to hold down STRG and left click on
        // it, maybe that gives you some insights.
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

// Ignore below code for now. We'll come to initialization soon.
void __init(void){
    // Set Oscillator Frequency to 4MHz (you will use this setting a lot!)
    OSCCON = 0x50;
    // Enable LCD
    GLCD_Init();
    
    // Configure LEDs
    init_LEDs();
}
