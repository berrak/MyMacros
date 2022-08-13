/*
*  macrofn.h
*
*  Add arbitary useful macros to your collection.
*  Created by Debinix Team (C). License GPL-3.0.
*  Date: 2022-08-13.
*/

// printlnMatch() print matching define in MyMacros.h to Serial port.
#if defined(ARDUINO_AVR_UNO)
#define printlnMatch() Serial.println("ARDUINO_AVR_UNO")

#elif defined(ARDUINO_SAMD_MKRWAN1300)
#define printlnMatch() Serial.println("ARDUINO_SAMD_MKRWAN1300")

#elif defined(ARDUINO_ESP8266_WEMOS_D1MINI)
#define printlnMatch() Serial.println("ARDUINO_ESP8266_WEMOS_D1MINI")

#elif defined(ARDUINO_ESP32_DEV)
#define printlnMatch() Serial.println("ARDUINO_ESP32_DEV")

#elif defined(ARDUINO_ESP32_THING)
#define printlnMatch() Serial.println("ARDUINO_ESP32_THING")

#elif defined(ARDUINO_TINYPICO)
#define printlnMatch() Serial.println("ARDUINO_TINYPICO")

#elif defined(ARDUINO_BLACKPILL_F411CE)
#define printlnMatch() Serial.println("ARDUINO_BLACKPILL_F411CE")

#elif defined(ARDUINO_BLUEPILL_F103C6) || defined(ARDUINO_BLUEPILL_F103C8) || defined(ARDUINO_BLUEPILL_F103CB)
#define printlnMatch() Serial.println("ARDUINO_BLUEPILL_F103C6, ARDUINO_BLUEPILL_F103C8, ARDUINO_BLUEPILL_F103CB")

#elif defined(ARDUINO_D1MINI_G031F6)
#define printlnMatch() Serial.println("ARDUINO_D1MINI_G031F6")

#elif defined(ARDUINO_D1MINI_G031F8)
#define printlnMatch() Serial.println("ARDUINO_D1MINI_G031F8")

#else
#define printlnMatch() Serial.println("NO MATCH - UNKNOWN BOARD")
#endif

// Add more here.