/*
*  MyMacros.ino
*  Demonstrates backward compatibilty (Board Identify) and new extensability.
*  Created by Debinix Team (C). Licensed under GPL-3.0.
*  Date: 2022-08-14.
*/

// Adding this line before the library will output compile time identification.
#define BOARD_IDENTIFY_WARNING
#include <MyMacros.h>   // This add all available 100+ boards from Board Identify.
#include "macrofn.h"    // Add your macro function constructs.

// Define a structure variable
struct board myBoard;

void setup() {
  Serial.begin(9600);
  while (!Serial) {;}
  delay(3000);
  Serial.println();
  Serial.println("==== Setup ====");
  Serial.print("Matching board define: ");
  // see "macrofn.h", in working directory.
  printlnMatch(); 
  Serial.print("Global 'match' variable is assigned: ");
  Serial.println(match);
  delay(3000);
}

void loop() {

    // Use members in 'struct board' to access
    // identity information from 'MyMacros.h'.
    // Adds the personal collection of boards.
    Serial.println("==== MyMacros ===="); 
    Serial.print("Board Type: ");
    Serial.println(myBoard.type);  
    Serial.print("Board Make: ");
    Serial.println(myBoard.make);
    Serial.print("Board Model: ");
    Serial.println(myBoard.model);
    Serial.print("Board MCU: ");
    Serial.println(myBoard.mcu);
    
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
