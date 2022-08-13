/*
*  MyMacros.h
*  The Arduino library identifies your unique collection of development boards.
*  Created by Debinix Team (C). Licensed under GPL-3.0.
*  Date: 2022-08-10.
*/

#pragma once

// #include <Board_Identify.h>

namespace MyMacros {

#if defined(ARDUINO)

    // UNIVERSAL macros
    #define BAUD_RATE   115200
    #define BLINK_DELAY 125

    #if defined(ARDUINO_D1MINI_G031F8)
        // Only new macros here
        #ifndef LED_BUILTIN
            #define LED_BUILTIN PB6
        #endif
        const int type = 0;
        const char* make = "Debinix Team";
        const char* model = "D1-mini G031Fx";
        const char* mcu = "STM32G031F8";
        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Controller: D1-mini G031F8"
            #warning "Matched defined(ARDUINO_D1MINI_G031F8)"
        #endif
    #else
        const int type = 0;
        const char* make = "Unknown";
        const char* model = "Unknown";
        const char* mcu = "Unknown";
        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Controller: Unknown Controller Model"
        #endif
    #endif

#else
    const int type = 0;
    const char* make = "Unknown";
    const char* model = "Unknown";
    const char* mcu = "Unknown";
#endif
}
