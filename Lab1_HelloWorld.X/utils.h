/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef UTILS_INCLUDE_H
#define	UTILS_INCLUDE_H

#define MILLION 1000 * 1000UL
#define _XTAL_FREQ 4*MILLION

void sleep_250_ms(void){
    // One iteration of this loop takes 12 instruction cycles, which equals 12µs 
    // for an Oscillator frequency of 4MHz. You will learn more about that 
    // very soon!
    for (unsigned int i = 0; i < 20832; ++i) {
        Nop();
    }
    Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
}

#include <xc.h> // include processor files - each processor file is guarded.  

#include "Libraries/LCD/GLCD_library.h"

/**
 * Initialize the relevant pins as Outputs to control the LEDs.
 * Initially LEDs are turned off.
 */
void init_LEDs(void) {
    ANSELB = 0;
    TRISB = 0b11000011;
    LATB = 0b00111100;
}

static unsigned char led_val = 0x02;

/**
 * Toggle LED number num. To toggle means to switch its state. On to off and
 * off to on.
 * @param num: number of LED to be toggled (see Lab Board LEDX, where X is num)
 */
void toggle_LED(unsigned char num) {
    if (num > 4 || num < 1) {
        GLCD_Clear();
        GLCD_Text2Out(0, 3, "!!!");
        GLCD_Text2Out(1, 0, "INCORRECT");
        GLCD_Text2Out(2, 3, "LED");
        return;
    }

    // XOR LATB register with required LED
    LATB ^= led_val << num;
}

#endif	/* XC_HEADER_TEMPLATE_H */

