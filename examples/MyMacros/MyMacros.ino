/*
*  MyMacros.ino
*
*  MyMacros and 'Board Identify' library combination identifies 100+ boards at compile and run time.
*  In addition, the MyMacros library maintains personal macros for your unique collection of boards.
*  Created by Debinix Team (C). License GPL-3.0.
*  Date: 2022-08-13.
*/

// Adding this line before the library will output compile time identification.
#define BOARD_IDENTIFY_WARNING

#include <MyMacros.h>   // This add all available 100+ boards from Board Identify.
#include "macrofn.h"    // Add additional personal macro function constructs.

// BAUD_RATE is default to 9600, defined in 'MyMacros.h'
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

        Serial.println("==== MyMacros ====");
        Serial.print("Matching board define: ");
        // from #include "macrofn.h", in working directory.
        printlnMatch(); 

        // MyMacros uses namespace 'mymacro' 
        // Your unique collection of boards.
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

        // Use namespace 'BoardIdentity'
        // Identify 100+ boards from Board Identify library.
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
