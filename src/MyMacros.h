/*
*  MyMacros.h
*  The Arduino library identifies your unique collection of development boards.
*  Created by Debinix Team (C). Licensed under GPL-3.0.
*  Date: 2022-08-13.
*/

#include <Board_Identify.h>

#pragma once

namespace macro {

    int type = 0;
    char* make = "Unknown";
    char* model = "Unknown";
    char* mcu = "Unknown";

}

    #if defined(ARDUINO)

        // My Universal applied macros
            #define BAUD_RATE   9600
            #define BLINK_DELAY 125


            #if defined(ARDUINO_AVR_UNO)

            // Only macros here

                #if defined(BOARD_IDENTIFY_WARNING)
                    #warning "Matched defined(ARDUINO_AVR_UNO)"
                #endif

        // ARDUINO SAMD

            #elif defined(ARDUINO_SAMD_MKRWAN1300)

                // Only macros here

                #if defined(BOARD_IDENTIFY_WARNING)
                    #warning "Matched defined(ARDUINO_SAMD_MKRWAN1300)"
                #endif

        // ESP8266

            #elif defined(ARDUINO_ESP8266_WEMOS_D1MINI)

                // Only macros here

                #if defined(BOARD_IDENTIFY_WARNING)
                    #warning "Matched defined(ARDUINO_ESP8266_WEMOS_D1MINI)"
                #endif

        // ESP32

            #elif defined(ARDUINO_ESP32_DEV)

                // Only macros here

                #if defined(BOARD_IDENTIFY_WARNING)
                    #warning "Matched defined(ARDUINO_ESP32_DEV)"
                #endif

            #elif defined(ARDUINO_ESP32_THING)

                // Only macros here

                #if defined(BOARD_IDENTIFY_WARNING)
                    #warning "Matched defined(ARDUINO_ESP32_THING)"
                #endif

        // SOME COMMON ARDUINO AVR IN YOUR PERSONAL COLLECTION
            
            #elif defined(ARDUINO_TINYPICO)

                // Only macros here

                macro::type = 0;
                macro::make = "Unexpected Maker";
                macro::model = "TinyPICO";
                macro::mcu = "ESP32";
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

                macro::type = 0;
                macro::make = "WeAct Studio";
                macro::model = "BlackPill";
                macro::mcu = "STM32F411CE";

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

                macro::type = 0;
                macro::make = "Generic";
                macro::model = "BluePill";
                macro::mcu = "STM32F103x";

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

                macro::type = 0;
                macro::make = "Debinix Team";
                macro::model = "D1-mini G031Fx";
                macro::mcu = "STM32G031F6";
                #if defined(BOARD_IDENTIFY_WARNING)
                    #warning "Controller: D1-mini G031F6"
                    #warning "Matched defined(ARDUINO_D1MINI_G031F6)"
                #endif

            #elif defined(ARDUINO_D1MINI_G031F8)
                // Only new macros here


                #ifndef LED_BUILTIN
                    #define LED_BUILTIN PB6
                #endif
                macro::type = 0;
                macro::make = "Debinix Team";
                macro::model = "D1-mini G031Fx";
                macro::mcu = "STM32G031F8";

                #if defined(BOARD_IDENTIFY_WARNING)
                    #warning "Controller: D1-mini G031F8"
                    #warning "Matched defined(ARDUINO_D1MINI_G031F8)"
                #endif
            
            #else
                macro::type = 0;
                macro::make = "Unknown";
                macro::model = "Unknown";
                macro::mcu = "Unknown";

                #if defined(BOARD_IDENTIFY_WARNING)
                    #warning "Controller: Unknown Controller Model"
                #endif
            #endif

    #else
        macro::type = 0;
        macro::make = "Unknown";
        macro::model = "Unknown";
        macro::mcu = "Unknown";
    #endif

//}
