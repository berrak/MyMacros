/*
*  MyMacros.ino
*  Demonstrates backward compatiblity (Board Identify) and new extendability.
*  Created by Debinix Team (C). The MIT License (MIT).
*  Date: 2022-08-31.
*/

// Adding this line before the library will output compile time identification.
#define ARCH_IDENTIFY_WARNING
#define BOARD_IDENTIFY_WARNING
#include <MyMacros.h>   // This also includes all available 100+ boards from Board Identify.

// Optional define a structure variable. Only required for access to struct data.
struct board myBoard;

void setup() {

  Serial.begin(9600); while (!Serial); Serial.println();
  delay(1000);  // settling time
  
  Serial.println("==== Setup ====");
  Serial.print("Matching board define: ");
  printlnMatch(); 
  Serial.print("Arduino's 'BUILD_BOARD' property: ");
  Serial.println(BUILD_BOARD);
  delay(1000);
}

void loop() {

    // Adds the personal collection of boards and 100+ boards from Board Identify library
    // Use members in struct 'MyBoard' to access identity information from 'MyMacros.h'.
    Serial.println("==== MyMacros (Automatically pulls in from Board Identify) ===="); 
    Serial.print("Board Type: ");
    Serial.println(myBoard.type);  
    Serial.print("Board Make: ");
    Serial.println(myBoard.make);
    Serial.print("Board Model: ");
    Serial.println(myBoard.model);
    Serial.print("Board MCU: ");
    Serial.println(myBoard.mcu);
    
    delay(3000);

    // Should be identical to above
    Serial.println("==== Board Identify (source board data) ====");
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
