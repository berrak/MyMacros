[![GitHub license](https://img.shields.io/github/license/berrak/MyMacros.svg?logo=gnu&logoColor=ffffff)](https://github.com/berrak/My_Macros/blob/master/LICENSE)
[![GitHub version](https://img.shields.io/github/release/berrak/MyMacros.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/My_Macros/releases/latest)
[![GitHub Release Date](https://img.shields.io/github/release-date/berrak/MyMacros.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/My_Macros/releases/latest)
[![GitHub stars](https://img.shields.io/github/stars/berrak/MyMacros.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/MyMacros/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/berrak/MyMacros.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/MyMacros/issues)

# Arduino library MyMacros
`MyMacros` library allows identifying boards that you own. The library maintains *personal macros* for your unique collection of boards. The existing Arduino library [Board Identify](https://github.com/MattFryer/Board_Identify) aims to identify many Arduino-compatible boards. This library, `MyMacros`, adds a separate header file with a *personal* list of boards in your possession.

Another advantage of this library is that it gives us development flexibility when working in parallel with various boards. Using `symbolic links` for specific boards [minimizes code duplication](#reduce-code-duplication). The solution discussed can be implemented on `Linux` and `Mac OS X`.

## Why use this library?
If you want to write code or libraries for specific platforms or a range of boards, it would be best if you had a way to tell them apart. Likely, that code cannot be made universal. Instead, you have to include various snippets depending on a particular board. MyMacros-library suggests using pre-processor defines for this purpose. Within the Arduino ecosystem, many kinds of definitions exist. The Library Board Identify contains over 100+ boards, but this list will never be complete considering the ever-increasing number of new development boards. In the 'MyMacros.h' header file, you can:
- extend existing board information with newly defined macros.
- add any new data or defines for your development boards
- add non-existent boards that are not in 'Board_Identify.h'

The code will be less bloated with numerous macros handling various board specifics.

## How to use c++ preprocessor directives?
Here are examples of the variation in modifying code included with the help of pre-processor directives.
```cpp
#if defined(ARDUINO_D1MINI_G031F6) || defined(ARDUINO_D1MINI_G031F8)
 //             sda, scl
 TwoWire Wire2(D21,D20);
 Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire2, OLED_RESET);
#else
  Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#endif
```
or
```cpp
#ifdef ARDUINO_TINYPICO
#include <TinyPICO.h>
TinyPICO tp = TinyPICO();
#endif
```
## Where to find it?
There are several ways to get the required definitions. Arduino uses the label `build.board` that can be found in the `boards.txt` as, e.g. `tinypico.build.board=TINYPICO`. Pre-pend 'ARDUINO' to`ARDUINO_TINYPICO` for library usage. But there are alternatives like adding `#define BOARD_IDENTIFY_WARNING` before including this library. Compiling the code, a compiler warning with the information, among other information, is sent to `stdout`.
```cpp
#define BOARD_IDENTIFY_WARNING
#include <MyMacros.h>
```
Ensure that `File->Preferences->compiler warnings` is set to *Default* or *All*. It will likely show up quickly in the beginning, in red - as a warning - of all compiled messages fast scrolling down your eyes.

In addition, the output from `MyMacros.h` includes the matching define, for example, `Matched defined(ARDUINO_AVR_UNO)` to remind ourselves what define causes the outcome. These definitions are very useful in the code, and based on that, include, exclude code, or add some macros.

An alternative at run-time. With 'printlnMatch()' macro this information is sent to Serial-port. Yet another alternative is to use the defined macro `BUILD_BOARD`.
```cpp
Serial.begin(9600);
printlnMatch();
 ARDUINO_TINYPICO
// or
Serial.println(BUILD_BOARD);
 ARDUINO_TINYPICO
```

## Examples

In Arduino IDE scroll down the long list below `File->Examples` and find `MyMacros`.

Firstly, you must include the library in your sketch:
```cpp
#include <MyMacros.h>
```
The library expands on `Boards_Identify.h` capabilities and pulls in the `Board Identify` library with 100+ boards as a dependence.

## Usage

`MyMacros` library uses the `struct board` to access defined values. You can therefore access the personal list of a board like this. 

```cpp
struct board myBoard;
Serial.println("==== MyMacros ===="); 
Serial.print("Board Type: ");
Serial.println(myBoard.type); 
Serial.print("Board Make: ");
Serial.println(myBoard.make);
Serial.print("Board Model: ");
Serial.println(myBoard.model);
Serial.print("Board MCU: ");
Serial.println(myBoard.mcu);
```
This Library automatically use board identity data that already exists in `Boards_Identify.h`. 

## How to Install

1. Navigate to the [Releases page](https://github.com/berrak/My_Macros/releases).
1. Download the latest released ZIP-archive in `~/Arduino/libraries`.
1. Unzip the archive.
1. Rename the new directory. Remove *version-code*, or *master* in the name like this for `MyMacros`.
1. Restart Arduino IDE.
1. In Arduino IDE scroll down the long list below `Sketch->Include Library` and find `MyMacros`.

For all the details on how to install libraries in the Arduino IDE, please see the [Arduino website](https://www.arduino.cc/en/Guide/Libraries). It is worthwhile reading.

## Customizing and protecting your macros

The `MyMacros.h` is installed in `~/Arduino/libraries/MyMacros/src/`. Use a local copy to avoid this file being overwritten by Arduino when the library updates. Protect this file and move this to `~/mymacros.` Create a symbolic link to this location. When the header file eventually is overwritten, re-create the link again.

```
mkdir ~/mymacros
$ cd ~/Arduino/libraries/MyMacros/src
mv MyMacros.h ~/mymacros
$ ln -s ~/mymacros/MyMacros.h MyMacros.h
$ ls -l
 MyMacros.cpp
 MyMacros.h -> /home/bekr/mymacros/MyMacros.h
```
Arduino IDE will use your file that was moved to `~/mymacros`.

# Reduce code duplication

The solution discussed here can be implemented on `Linux` and `Mac OS X`, but not on Windows. `Windows Subsystem for Linux 2` can maybe solve this. The file system has to have a specific layout to minimize duplication of code effectively. For example, we have created four different directories for our boards and one standard code directory, `CODE,` where all our sketches will live.

It's probably a good idea to update your sketch folder in `File-> Preferences` with `~/Arduino.` Create som directories for your boards.

```
~/Arduino
├── CODE
├── ESP8266
├── TinyPICO
├── libraries
├── STM32G0
└── Uno

```
The organization for sub-folders in `CODE` is very personal. For example, use something in line with Arduino's IDE structure similar to Arduino's `File-> Examples` hierarchy (analog, basic, communication, digital, display, neopixel, sensors, usb, ...). The drawback with such tree structure is that it becomes profound, and paths get very long.

For example, the idea is to have one typical *Blink* sketch for all our development boards. Thus, when saving the built-in `Blink.ino` sketch say below `CODE,` e.g. `../CODE/basic/blink/blink.ino` but not below any development board directories. The header macros will handle any differences between individual boards.

```
~/Arduino/CODE$ tree -L 1
.
├── analog
├── basic
├── communication
├── digital
├── display
├── neopixel
├── sensor
└── usb
```
Our best solution to **`reduce the depth and still have useful symbolic links`** is to adapt a sketch naming convention instead, i.e., **not** use the above structure. Instead, use the camel case naming strategy where the first parts repeat the above hierarchy. Thus the built-in `Blink.ino` is saved as **`basicBlink.ino`** direct below `CODE` but create first the directory **`basicBlink`** for the Arduino sketch. Here is a list of some inspirational prefixes in addition to the above.

- data-processing
- storage
- sample
- device-control
- sensor
- signal-io
- timing

## Add a symbolic link (manually) in the device tree to the code directory

Change the folder to one of the development boards and its main directory and create the link to the familiar `basicBlink.ino`.
```
$ cd ~/Arduino/STM32G0
$ mkdir basicBlink
$ cd basicBlink
$ ln -s ../../CODE/basicBlink/basicBlink.ino basicBlink.ino
$ ls -l
 basicBlink.ino -> ../../CODE/basicBlink/basicBlink.ino
```
We are working in this particular development board directory, but we are editing the typical `basicBlink.ino` file. Define the board macros in the `MyMacros.h` file. The sketch has its directory, as Arduino requires, and allows adding other files in the same folder.

Change to another development board folder, the main directory, and create a second link to the common `basicBlink.ino`.
```
$ cd ~/Arduino/ESP8266
$ mkdir basicBlink
$ cd basicBlink
$ ln -s ../../CODE/basicBlink/basicBlink.ino basicBlink.ino
$ ls -l
 basicBlink.ino -> ../../CODE/basicBlink/basicBlink.ino
```
The above steps are somewhat tedious, but the script `mylink` below becomes effortless.
This concept reduces the clutter of files, with fewer duplicates in the file system, for files essentially performing the same task.

## Adding a new architecture

Code links are related to the above directories. So instead of creating any symbolic links, create a new directory `rp2040` parallel to `CODE` and copy all the contents from example `Uno` into this new architecture folder.
```
cd ~/CODE
mkdir rp2040
cp -r Uno/* rp2040/
```
Folders are insensitive to later changes, like, for example, `rp2040` to `RPI-rp2040`, and the links still work as before.

## Automation of link creation

Now we will create a command script called `mylink`. Run this in the development board directory, and this makes a symbolic link.
Open an editor and copy the script content below. This file is also included in the library in the `script` folder.

```bash
#!/bin/bash
#
# mylink - script to find and create a symbolic link to a source Arduino sketch
# Author: Debinix Team (C). License GPL-3.0
# Date: 2022-08-14.
#
parent_boards_directory_name="Arduino/CODE"

case $# in
    0) echo -n "Give the name of the sketch, including '.ino': "
    read fname;;
    1) fname=$1
    ;;
    *) echo "Too many arguments given, aborting. Please correct and retry."
    exit;;
esac

if echo "$fname" | grep -q "\.ino"; then
  echo "Sketch '$fname'"
  mydir=$( cut -d '.' -f 1 <<< "$fname" )
else
  echo "Missing '.ino' in the sketch name. Please correct and retry."
  exit
fi

# Create a subdirectory for Arduino IDE
if [ ! -d "$mydir" ] 
then
    mkdir $mydir
fi

if [ -h "$PWD/$mydir/$fname" ]
then
    echo "A symbolic link with the name '$fname' already exists in '$PWD/$mydir'. Please remove this '$fname'-link, and try again."
    exit
fi

# Search below ../CODE i.e for a source sketch to link to for the board's subfolder tree
find "$HOME/$parent_boards_directory_name" -name "$fname" -exec ln -s '{}' "$mydir/$fname" \;
echo "Check that a symbolic link '$fname' has successfully been created in '$PWD/$mydir'."
```

Move this file to the `~/.local/bin` folder, and make it executable:
```
$ mv mylink ~/.local/bin
$ chmod u+x ~/.local/bin/mylink
```

Debian/Linux system includes a command called *link*, but `mylink` does the search and link creation operation effortless without specifying paths to any files. Now test the command in a third development board folder with:

```
$ cd ~/Arduino/Uno
$ mylink basicBlink.ino
 Check that a symbolic link basicBlink.ino has successfully been created in '~/Arduino/Uno/basicBlink'.
$ ls -l basicBlink
 basicBlink.ino -> /home/bekr/Arduino/CODE/basicBlink/basicBlink.ino
```
If you run it without an argument, the command will ask for the name of the sketch.

## Final thoughts

If you set Arduino `File->Preferences` to update libraries at start up, be mindful since you may overwrite the symbolic link to your customizations. In that case, re-create the symbolic link to `~/mymacros`. For planned changes, improvements, and known bugs, please visit the [Github issues tracker](https://github.com/berrak/My_Macros/issues).

The device tree does not maintain the neat hierarchical organization below CODE. Thus, choosing meaningful file names when first saving the file in the CODE-tree is helpful. Another challenge is the regression testing of code written for multiple devices. Traversing the symbolic links for each or a single board during testing is one way to set up tests.

## Credits

Thanks to `Matt Fryer` and his [Board Identify](https://github.com/MattFryer/Board_Identify) for his earlier work.
