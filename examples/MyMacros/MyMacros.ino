/*
*  MyMacros.ino
*  Demonstrates backward compatiblity (Board Identify) and new extendability.
*  Created by Debinix Team (C). Licensed under GPL-3.0.
*  Date: 2022-08-14.
*/

// Adding this line before the library will output compile time identification.
#define BOARD_IDENTIFY_WARNING
#include <MyMacros.h>   // This also includes all available 100+ boards from Board Identify.

// Define a structure variable
struct board myBoard;

void setup() {
  Serial.begin(9600);
  while (!Serial) {;}
  
  Serial.println();
  Serial.println("==== Setup ====");
  Serial.print("Matching board define: ");
  printlnMatch(); 
  Serial.print("Global 'match' variable is assigned: ");
  Serial.println(match);
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
