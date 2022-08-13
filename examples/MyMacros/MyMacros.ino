/*
*  MyMacros.ino
*
*  MyMacros and 'Board Identify' combination allows identification for many boards at run time.
*  In addition, the MyMacros library maintains personal macros for your unique collection of boards.
*  Created by Debinix Team (C). License GPL-3.0.
*  Date: 2022-08-13.
*/

// Adding this line before the library will output compile time identification.
#define BOARD_IDENTIFY_WARNING
#include <MyMacros.h>    // includes all boards from Board Identify library.

// BAUD_RATE is 115200, defined in 'MyMacros.h'
#ifndef BAUD_RATE
#define BAUD_RATE 9600
#endif

void setup() {

    Serial.begin(BAUD_RATE);
    Serial.println("Setup complete.");
    delay(2000);
}

void loop() {

    for(;;) {

        // MyMacros uses the namespace 'mymacro' to prevent 
        // variable name conflicts with other libraries.
        Serial.println("==== MyMacros ====");
        Serial.print("Board Type: ");
        Serial.println(mymacro::type);
        Serial.print("Board Make: ");
        Serial.println(mymacro::make);
        Serial.print("Board Model: ");
        Serial.println(mymacro::model);
        Serial.print("Board MCU: ");
        Serial.println(mymacro::mcu);
        Serial.println();

        delay(3000);

        // Mix in identification from Board Identify, with its own namespace.
        Serial.println("==== Board Identify ====");
        Serial.print("Board Type: ");
        Serial.println(BoardIdentify::type);
        Serial.print("Board Make: ");
        Serial.println(BoardIdentify::make);
        Serial.print("Board Model: ");
        Serial.println(BoardIdentify::model);
        Serial.print("Board MCU: ");
        Serial.println(BoardIdentify::mcu);
        Serial.println();

        delay(3000);

    }
}
