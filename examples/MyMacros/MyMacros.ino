/*
*  MyMacros.ino
*
*  MyMacros and 'Board Identify' combination allows identification for many boards at run time.
*  In addition, the MyMacros library maintains personal macros for your unique collection of boards.
*  Created by Debinix Team (C). License GPL-3.0.
*  Date: 2022-08-13.
*/

// Adding this line before the library will output a compile time identification.
#define BOARD_IDENTIFY_WARNING
#include <MyMacros.h>

// BAUD_RATE is 115200 as defined in 'MyMacros.h'
#ifndef BAUD_RATE
#define BAUD_RATE 9600
#endif

void setup() {

    Serial.begin(BAUD_RATE);
    Serial.println("==== BOARD IDENTIFY ====");

    // BoardIdentify::type is a unique integer that will never be changed and so should maintain future compatibility.
    // It is advised to use this for any logic. See https://github.com/MattFryer/Board_Identify
    if (BoardIdentify::type == 2) {
    Serial.print("It is an Arduino Uno");
    } else {
    Serial.print("It is NOT an Arduino Uno");
    }

    delay(5000);

}

void loop() {

for(;;) {

    // MyMacros uses the namespace 'MyMacros' to prevent variable name conflicts with other libraries.

    Serial.println("==== MYMACROS ====");
    Serial.print("Board Type: ");
    Serial.println(MyMacros::type);
    Serial.print("Board Make: ");
    Serial.println(MyMacros::make);
    Serial.print("Board Model: ");
    Serial.println(MyMacros::model);
    Serial.print("Board MCU: ");
    Serial.println(MyMacros::mcu);
    Serial.println();

    delay(5000);

    // 'Board Identify' uses the namespace 'BoardIdentify' to prevent variable name conflicts with other libraries.

    Serial.println("==== BOARD IDENTIFY ====");
    Serial.print("Board Type: ");
    Serial.println(BoardIdentify::type);
    Serial.print("Board Make: ");
    Serial.println(BoardIdentify::make);
    Serial.print("Board Model: ");
    Serial.println(BoardIdentify::model);
    Serial.print("Board MCU: ");
    Serial.println(BoardIdentify::mcu);
    Serial.println();

    delay(5000);
    }
}
