/*
*  MyMacros.h
*  The Arduino library identifies your unique collection of development boards.
*  Created by Debinix Team (C). Licensed under GPL-3.0.
*  Date: 2022-08-13.
*/

#include <Board_Identify.h>

#pragma once

#include "macrofn.h"    // Add your macro function constructs.
struct board;

// My Universal applied macros
#define BAUD_RATE   9600
#define BLINK_DELAY 125

//--------------------------------------------------------------------------------
// Some Arduino boards without existing variables i.e. already defind in Board Identify.
//--------------------------------------------------------------------------------
    #if defined(ARDUINO_AVR_UNO)

        // Only macros here

        struct board
        {
            int type = BoardIdentify::type;
            const char *make = BoardIdentify::make;
            const char *model = BoardIdentify::model;
            const char *mcu = BoardIdentify::mcu;
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Matched defined(ARDUINO_AVR_UNO)"
        #endif

// ARDUINO SAMD

    #elif defined(ARDUINO_SAMD_MKRWAN1300)

        // Only macros here

        struct board
        {
            int type = BoardIdentify::type;
            const char *make = BoardIdentify::make;
            const char *model = BoardIdentify::model;
            const char *mcu = BoardIdentify::mcu;
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Matched defined(ARDUINO_SAMD_MKRWAN1300)"
        #endif

// ESP8266

    #elif defined(ARDUINO_ESP8266_WEMOS_D1MINI)

        // Only macros here

        struct board
        {
            int type = BoardIdentify::type;
            const char *make = BoardIdentify::make;
            const char *model = BoardIdentify::model;
            const char *mcu = BoardIdentify::mcu;
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Matched defined(ARDUINO_ESP8266_WEMOS_D1MINI)"
        #endif

// ESP32

    #elif defined(ARDUINO_ESP32_DEV)

        // Only macros here

        struct board
        {
            int type = BoardIdentify::type;
            const char *make = BoardIdentify::make;
            const char *model = BoardIdentify::model;
            const char *mcu = BoardIdentify::mcu;
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Matched defined(ARDUINO_ESP32_DEV)"
        #endif

    #elif defined(ARDUINO_ESP32_THING)

        // Only macros here

        struct board
        {
            int type = BoardIdentify::type;
            const char *make = BoardIdentify::make;
            const char *model = BoardIdentify::model;
            const char *mcu = BoardIdentify::mcu;
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Matched defined(ARDUINO_ESP32_THING)"
        #endif

//---------------------------------------------------------------
// Board in your possesion with its namespaced defined variables.
//---------------------------------------------------------------
    #elif defined(ARDUINO_TINYPICO)

        // Only macros here

        struct board
        {
            int type = 0;
            const char *make = "Unexpected Maker";
            const char *model = "TinyPICO";
            const char *mcu = "ESP32";
        };
        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Controller: ESP32 TinyPICO"
            #warning "Matched defined(ARDUINO_TINYPICO)"
        #endif

// STM32 F411CEU6 - Black Pill

    #elif defined(ARDUINO_BLACKPILL_F411CE)

        // Only macros here
        #ifndef LED_BUILTIN
            #define LED_BUILTIN PC13
        #endif

        struct board
        {
            int type = 0;
            const char *make = "WeAct Studio";
            const char *model = "BlackPill";
            const char *mcu = "STM32F411CE";
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Controller: STM32F411CE BlackPill"
            #warning "Matched defined(ARDUINO_BLACKPILL_F411CE)"
        #endif

// STM32 F103Fx - Blue Pill variants

    #elif defined(ARDUINO_BLUEPILL_F103C6) || defined(ARDUINO_BLUEPILL_F103C8) || defined(ARDUINO_BLUEPILL_F103CB)

        // Only macros here
        #ifndef LED_BUILTIN
            #define LED_BUILTIN PC13
        #endif

        struct board
        {
            int type = 0;
            const char *make = "Generic";
            const char *model = "BluePill";
            const char *mcu = "STM32F103x";
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Controller: STM32F103x BluePill"
            #warning "Matched defined(ARDUINO_BLUEPILL_F103C6) or"
            #warning "Matched defined(ARDUINO_BLUEPILL_F103C8) or"
            #warning "Matched defined(ARDUINO_BLUEPILL_F103CB)"
        #endif            

    #elif defined(ARDUINO_D1MINI_G031F6)

        // Only macros here
        #ifndef LED_BUILTIN
            #define LED_BUILTIN PB6
        #endif

        struct board
        {
            int type = 0;
            const char *make = "Debinix Team";
            const char *model = "D1-mini G031Fx";
            const char *mcu = "STM32G031F6";
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Controller: D1-mini G031F6"
            #warning "Matched defined(ARDUINO_D1MINI_G031F6)"
        #endif

    #elif defined(ARDUINO_D1MINI_G031F8)
        // Only new macros here


        #ifndef LED_BUILTIN
            #define LED_BUILTIN PB6
        #endif

                struct board
        {
            int type = 0;
            const char *make = "Debinix Team";
            const char *model = "D1-mini G031Fx";
            const char *mcu = "STM32G031F8";
        };

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Controller: D1-mini G031F8"
            #warning "Matched defined(ARDUINO_D1MINI_G031F8)"
        #endif
    
    #else
        struct board
        {
            int type = 0;
            const char *make = "Unknown";
            const char *model = "Unknown";
            const char *mcu = "Unknown";
        }; 

        #if defined(BOARD_IDENTIFY_WARNING)
            #warning "Controller: Unknown Controller Model"
        #endif
    #endif


/* EOF */

