/*!
 * @file MyMacros.h
 *
 * This is part of MyMacros library for the Arduino platform.
 *
 * The MIT license.
 *
 */

#include <Board_Identify.h>

#pragma once

/** Access all data via this struct */
struct board;

// Architecture wide macros
#if defined(ARDUINO_ARCH_ESP8266)
#if defined(ARCH_IDENTIFY_WARNING)
#warning "Matched Architecture: (ARDUINO_ARCH_ESP8266)"
#endif

// Architecture macros here

#elif defined(ARDUINO_ARCH_ESP32)
#if defined(ARCH_IDENTIFY_WARNING)
#warning "Matched Architecture: (ARDUINO_ARCH_ESP32)"
#endif

// Architecture macros here

#elif defined(ARDUINO_ARCH_AVR) || defined(ARDUINO_ARCH_MEGAAVR)
#if defined(ARCH_IDENTIFY_WARNING)
#warning "Matched Architecture: (ARDUINO_ARCH_AVR) or (ARDUINO_ARCH_MEGAAVR)"
#endif

// Architecture macros here

#elif defined(ARDUINO_ARCH_STM32) || defined(ARDUINO_ARCH_ARDUINO_CORE_STM32)
#if defined(ARCH_IDENTIFY_WARNING)
#warning                                                                       \
    "Matched Architecture: (ARDUINO_ARCH_STM32) or (ARDUINO_ARCH_ARDUINO_CORE_STM32)"
#endif

// Architecture macros here

#elif defined(ARDUINO_ARCH_RP2040)
#if defined(ARCH_IDENTIFY_WARNING)
#warning "Matched Architecture: (ARDUINO_ARCH_RP2040)"
#endif

// Architecture macros here

#else
#if defined(ARCH_IDENTIFY_WARNING)
#warning                                                                       \
    "Architecture  currently not identified, please add an issue at Github/berrak/MyMacros"
#endif
#endif

// My personal applied macros among all my boards.
#ifndef BAUD_RATE
#define BAUD_RATE 115200  ///< Personal definition of baudrate, change as you see fit.
#endif
#ifndef BLINK_DELAY
#define BLINK_DELAY 125   ///< Personal definition of led blink rate in milliseconds, change as you see fit.
#endif

//---------------------------------------------------------------------------------------
// All Arduino boards you own (add as you see fit) from the 'Board_Identify.h'
// file.
//---------------------------------------------------------------------------------------
#if defined(ARDUINO_AVR_UNO)

// Only macros here

struct board {
  int type = BoardIdentify::type;
  const char *make = BoardIdentify::make;
  const char *model = BoardIdentify::model;
  const char *mcu = BoardIdentify::mcu;
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Matched Board: (ARDUINO_AVR_UNO)"
#endif

// ARDUINO SAMD

#elif defined(ARDUINO_SAMD_MKRWAN1300)

// Only macros here

struct board {
  int type = BoardIdentify::type;
  const char *make = BoardIdentify::make;
  const char *model = BoardIdentify::model;
  const char *mcu = BoardIdentify::mcu;
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Matched Board: (ARDUINO_SAMD_MKRWAN1300)"
#endif

// ESP8266

#elif defined(ARDUINO_ESP8266_WEMOS_D1MINI)

// Only macros here

struct board {
  int type = BoardIdentify::type;
  const char *make = BoardIdentify::make;
  const char *model = BoardIdentify::model;
  const char *mcu = BoardIdentify::mcu;
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Matched Board: (ARDUINO_ESP8266_WEMOS_D1MINI)"
#endif

// ESP32

#elif defined(ARDUINO_ESP32_DEV)

// Only macros here

struct board {
  int type = BoardIdentify::type;
  const char *make = BoardIdentify::make;
  const char *model = BoardIdentify::model;
  const char *mcu = BoardIdentify::mcu;
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Matched Board: (ARDUINO_ESP32_DEV)"
#endif

#elif defined(ARDUINO_ESP32_THING)

// Only macros here

struct board {
  int type = BoardIdentify::type;
  const char *make = BoardIdentify::make;
  const char *model = BoardIdentify::model;
  const char *mcu = BoardIdentify::mcu;
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Matched Board: (ARDUINO_ESP32_THING)"
#endif

//-----------------------------------------------------------------------
// All other Arduino boards in your ownership or currently are developing.
//-----------------------------------------------------------------------
#elif defined(ARDUINO_TINYPICO)

// Only macros here
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 21
#define TFT_RST 5
#define TFT_DC 22
#define TFT_LED 14

struct board {
  int type = 0;
  const char *make = "Unexpected Maker";
  const char *model = "TinyPICO";
  const char *mcu = "ESP32";
};
#if defined(BOARD_IDENTIFY_WARNING)
#warning "Controller: ESP32 TinyPICO"
#warning "Matched Board: (ARDUINO_TINYPICO)"
#endif

// STM32 F411CEU6 - Black Pill

#elif defined(ARDUINO_BLACKPILL_F411CE)

// Only macros here
#ifndef LED_BUILTIN
#define LED_BUILTIN PC13
#endif

struct board {
  int type = 0;
  const char *make = "WeAct Studio";
  const char *model = "BlackPill";
  const char *mcu = "STM32F411CE";
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Controller: STM32F411CE BlackPill"
#warning "Matched Board: (ARDUINO_BLACKPILL_F411CE)"
#endif

// STM32 F103Fx - Blue Pill variants

#elif defined(ARDUINO_BLUEPILL_F103C6) || defined(ARDUINO_BLUEPILL_F103C8) ||  \
    defined(ARDUINO_BLUEPILL_F103CB)

// Only macros here
#ifndef LED_BUILTIN
#define LED_BUILTIN PC13
#endif

struct board {
  int type = 0;
  const char *make = "Generic";
  const char *model = "BluePill";
  const char *mcu = "STM32F103x";
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Controller: STM32F103x BluePill"
#warning "Matched Board: (ARDUINO_BLUEPILL_F103C6) or"
#warning "Matched Board: (ARDUINO_BLUEPILL_F103C8) or"
#warning "Matched Board: (ARDUINO_BLUEPILL_F103CB)"
#endif

#elif defined(ARDUINO_D1MINI_G031F6)

// Only macros here
#ifndef LED_BUILTIN
#define LED_BUILTIN PB6
#endif

struct board {
  int type = 0;
  const char *make = "Debinix Team";
  const char *model = "D1-mini G031Fx";
  const char *mcu = "STM32G031F6";
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Controller: D1-mini G031F6"
#warning "Matched Board: (ARDUINO_D1MINI_G031F6)"
#endif

#elif defined(ARDUINO_D1MINI_G031F8)
// Only new macros here

#ifndef LED_BUILTIN
#define LED_BUILTIN PB6
#endif

struct board {
  int type = 0;
  const char *make = "Debinix Team";
  const char *model = "D1-mini G031Fx";
  const char *mcu = "STM32G031F8";
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Controller: D1-mini G031F8"
#warning "Matched Board: (ARDUINO_D1MINI_G031F8)"
#endif

#elif defined(ARDUINO_DISCO_F407VG)
// Only new macros here

#ifndef LED_BUILTIN
#define LED_BUILTIN LED_GREEN
#endif

struct board {
  int type = 0;
  const char *make = "STMicroelectronics";
  const char *model = "Discovery Board F407VG-DISC1";
  const char *mcu = "STM32F407VG";
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Controller: Discovery Board F407VG-DISC1D1-mini G031F8"
#warning "Matched Board: (ARDUINO_DISCO_F407VG)"
#endif

#else
/**  The structure holds members from Board Identify library */
struct board {
  int type = 0;                   /**< Board type is a unique number assigned by Board Identify library  */
  const char *make = "Unknown";   /**< Manufactures name */
  const char *model = "Unknown";  /**< Model name */
  const char *mcu = "Unknown";    /**< Microcontroller used on the board */
};

#if defined(BOARD_IDENTIFY_WARNING)
#warning "Controller: Unknown Controller Model"
#endif
#endif

//------------------------------------------------------------------
// 'printlnMatch()' prints matching define to Serial port.
//------------------------------------------------------------------

#if defined(ARDUINO_AVR_UNO)
#define printlnMatch() Serial.println("ARDUINO_AVR_UNO")
#define BUILD_BOARD "ARDUINO_AVR_UNO"

#elif defined(ARDUINO_SAMD_MKRWAN1300)
#define printlnMatch() Serial.println("ARDUINO_SAMD_MKRWAN1300")
#define BUILD_BOARD "ARDUINO_SAMD_MKRWAN1300"

#elif defined(ARDUINO_ESP8266_WEMOS_D1MINI)
#define printlnMatch() Serial.println("ARDUINO_ESP8266_WEMOS_D1MINI")
#define BUILD_BOARD "ARDUINO_ESP8266_WEMOS_D1MINI"

#elif defined(ARDUINO_ESP32_DEV)
#define printlnMatch() Serial.println("ARDUINO_ESP32_DEV")
#define BUILD_BOARD "ARDUINO_ESP32_DEV"

#elif defined(ARDUINO_ESP32_THING)
#define printlnMatch() Serial.println("ARDUINO_ESP32_THING")
#define BUILD_BOARD "ARDUINO_ESP32_THING"

#elif defined(ARDUINO_TINYPICO)
#define printlnMatch() Serial.println("ARDUINO_TINYPICO")
#define BUILD_BOARD "ARDUINO_TINYPICO"

#elif defined(ARDUINO_BLACKPILL_F411CE)
#define printlnMatch() Serial.println("ARDUINO_BLACKPILL_F411CE")
#define BUILD_BOARD "ARDUINO_BLACKPILL_F411CE"

#elif defined(ARDUINO_BLUEPILL_F103C6) || defined(ARDUINO_BLUEPILL_F103C8) ||  \
    defined(ARDUINO_BLUEPILL_F103CB)
#define printlnMatch()                                                         \
  Serial.println("ARDUINO_BLUEPILL_F103C6, ARDUINO_BLUEPILL_F103C8, "          \
                 "ARDUINO_BLUEPILL_F103CB")
#define BUILD_BOARD                                                            \
  "ARDUINO_BLUEPILL_F103C6, ARDUINO_BLUEPILL_F103C8, ARDUINO_BLUEPILL_F103CB"

#elif defined(ARDUINO_D1MINI_G031F6)
#define printlnMatch() Serial.println("ARDUINO_D1MINI_G031F6")
#define BUILD_BOARD "ARDUINO_D1MINI_G031F6"

#elif defined(ARDUINO_D1MINI_G031F8)
#define printlnMatch() Serial.println("ARDUINO_D1MINI_G031F8")
#define BUILD_BOARD "ARDUINO_D1MINI_G031F8"

// Add more here.

#else
#define printlnMatch() Serial.println("UNKNOWN BOARD")    ///<  Calls Serial.println() and prints identified board
#define BUILD_BOARD "UNKNOWN BOARD"                       ///<  The defined identified board, as a macro
#endif

/* EOF */
