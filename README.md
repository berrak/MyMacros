[![GitHub license](https://img.shields.io/github/license/berrak/My_Macros.svg?logo=gnu&logoColor=ffffff)](https://github.com/berrak/My_Macros/blob/master/LICENSE)
[![GitHub version](https://img.shields.io/github/release/berrak/My_Macros.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/My_Macros/releases/latest)
[![GitHub Release Date](https://img.shields.io/github/release-date/berrak/My_Macros.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/My_Macros/releases/latest)
[![GitHub stars](https://img.shields.io/github/stars/berrak/My_Macros.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/My_Macros/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/berrak/My_Macros.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/My_Macros/issues)
[![Codacy grade](https://img.shields.io/codacy/grade/05e2e79ae90d4b9489689f918ad2ccb5.svg?logo=codacy&logoColor=ffffff)](https://www.codacy.com/app/berrak/My_Macros)

# Arduino library My Macros
`My_Macros` library allows identifying boards that you own. The library maintains *personal macros* for your unique collection of boards. The existing Arduino library `Boards Identify` aims to identify many Arduino-compatible boards. This library, `My Macros,` adds a separate header file with a *personal* list of boards in your possession.

Another advantage of this library is that it gives us development flexibility when working in parallel with various boards. Using symbolic links for specific boards minimizes code duplication.

## How to Install
The easiest way is to download the ZIP-archive in `~/Arduino/libraries` or any other folder. Possible remove *master* in the file name. Then in the sketch, open the menu `Sketch->Include library->Add ZIP Library...` and select the file. Arduino IDE will expand the ZIP-archive contents in the right location, i.e. `~/Arduino/libraries`.

## Examples

Find a code example in Arduino IDE under `File->Examples->My_Macros`.

Firstly, you must include the library in your sketch:
```cpp
#include <My_Macros.h>
```
The library expands on `Boards_Identify.h` capabilities, and pulls in the `Board Identify` library as a dependence. This is strictly not required.

## Customizing and protecting your macros

The `My_Macros.h` is by default installed in `~/Arduino/libraries/My_Macros/src/`. Use a local copy to avoid this file being overwritten by Arduino when the library updates. Protect this file and move this to `~/mymacros.` Create a symbolic link to this location. When the library file eventually is overwritten, re-create the link again.

```
mkdir ~/mymacros
$ cd ~/Arduino/libraries/My_Macros/src
mv My_Macros.h ~/mymacros
$ ln -s ~/mymacros/My_Macros.h My_Macros.h
$ ls -l
 My_Macros.cpp
 My_Macros.h -> /home/bekr/mymacros/My_Macros.h
```
Arduino IDE will use your file that was moved to `~/mymacros`.

## Compile time identification

To get a compile-time warning, add this line, before the line `#include <My_Macros.h>`.:
```cpp
#define BOARD_IDENTIFY_WARNING
```
Ensure that `File->Preferences->compiler warnings` is set to *Default* or *All*. It will likely show up quickly in the beginning, in red - as a warning - of all compiled messages fast scrolling down your eyes.

In addition, the output from `My_Macros.h` includes the matching define, for example, `Matched defined(ARDUINO_AVR_UNO)` to remind ourselves what define causes the outcome. These definitions are very useful in the code, and based on that, include, exclude code, or add some macros.

## Add a new Arduino board identification

Being able to output board information to the screen or logs is generally useful. We are indeed working with the right board! This is identical to [Board Identify](https://github.com/MattFryer/Board_Identify) usage.

`My Macros` library uses the namespace `MyMacros` to prevent conflicts with other libraries. You can therefore access the personal list of a board like so. Information about how Arduino uses the label `build.board` can be found in the `boards.txt` as, e.g. `tinypico.build.board=TINYPICO`. Enter `ARDUINO_TINYPICO` for the `define` in `My_Macros.h` to match the new Arduino board.

```cpp
Serial.print("Board Make: ");
Serial.println(MyMacros::make);
Serial.print("Board Model: ");
Serial.println(MyMacros::model);
Serial.print("Board MCU: ");
Serial.println(MyMacros::mcu);
```
`My Macros` does not use the unique numerical `type` value. Set this value to `0` in the `My_Macros.h`. Note that if the board already exists in `Boards_Identify.h`, you must use that library-defined namespace `BoardsIdentify` like so.
```cpp
Serial.print("Board Type: ");
Serial.println(BoardIdentify::type);
Serial.print("Board Make: ");
Serial.println(BoardsIdentify::make);
Serial.print("Board Model: ");
Serial.println(BoardsIdentify::model);
Serial.print("Board MCU: ");
Serial.println(BoardsIdentify::mcu);
```

## Reduce code duplication

The file system has to have a specific layout to minimize duplication of code effectively. For example, we have created four different directories for our boards and one standard code directory, `CODE,` where all our sketches will live.

It's probably a good idea to update your sketch folder in `File-> Preferences` with `~/Arduino/CODE.`

```
~/Arduino
├── arduinoUno
├── CODE
├── debinixSTM32G031F8
├── lolinESP8266
└── sparkfunESP32
```
The organization for sub-folders in `CODE` is very personal. For example, use something in line with Arduino's IDE structure similar to Arduino's `File-> Examples` hierarchy.

```
~/Arduino/CODE$ tree -L 1
.
├── analog
├── basic
├── communication
├── digital
├── display
├── sensors
└── USB
```
For example, the idea is to have one typical *blink* sketch for all of our development boards. Thus, when saving the built-in` blink.ino` sketch should be below `CODE,` e.g. `../CODE/basic/blink/blink.ino` and is not below any development board directories. The header macros will handle any differences between individual boards.

## Add a symbolic link (manually) to the code directory

Change the folder to one of the development boards and its main directory and create the link to the familiar `blink.ino`.
```
$ cd ~/Arduino/debinixSTM32G031F8
$ ln -s ../CODE/basic/blink/blink.ino blink.ino
$ ls -l
 blink.ino -> ../CODE/basic/blink/blink.ino
```
We are working in this particular development board directory, but we are editing the typical `blink.ino` file. Define the board macros in the `My_Macros. h' file.

Change to another development board folder, the main directory, and create a second link to the common `blink.ino`.
```
$ cd ~/Arduino/lolinESP8266
$ ln -s ../CODE/basic/blink/blink.ino blink.ino
$ ls -l
 blink.ino -> ../CODE/basic/blink/blink.ino
```

Reduce the clutter of files, with fewer duplicates in the file system, for files essentially performing the same task.

## Automation of link creation

Now we will create a command script called `mylink.` Run this in the development board directory, and this makes a symbolic link.

## Create the bash command script

Open an editor and copy the content below.

```bash
#!/bin/bash
#
# mylink - script to find and create a symbolic link to a source Arduino sketch
# Author: Debinix Team (C). License GPL-3.0.
# Date: 2022-08-10
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
else
  echo "Missing '.ino' in the sketch name. Please correct and retry."
  exit
fi

if test -h "$fname";
then
    echo "A symbolic link with the name '$fname' already exists in '$PWD'. Please remove this '$fname'-link, and try again."
    exit
fi

# Search below ../CODE i.e for a source sketch to link to for the board's subfolder tree
find "$HOME/$parent_boards_directory_name" -name "$fname" -exec ln -s '{}' "$fname" \;
echo "Check that a symbolic link '$fname' has successfully been created in '$PWD'."

```

Move this file to the `~/.local/bin` folder, and make it executable:
```
$ mv mylink ~/.local/bin
$ chmod u+x ~/.local/bin/mylink
```

Debian/Linux system includes a command called *link*, but `mylink` does the search and link creation operation effortless without specifying paths to any files. Now test the command in a third development board folder with:

```
$ cd ~/Arduino/arduinoUno
$ mylink blink.ino
 Check that a symbolic link blink.ino has successfully been created in '~/Arduino/arduinoUno'.
$ ls -l
 blink.ino -> ../CODE/basic/blink/blink.ino
```
If you run it without an argument, the command will ask for the name of the sketch.

## Final thoughts

If you set Arduino `File->Preferences` to update libraries at start up, be mindful since you may overwrite the symbolic link to your customizations. In that case, re-create the symbolic link to `~/mymacros`. For planned changes, improvements, and known bugs, please visit the [Github issues tracker](https://github.com/berrak/My_Macros/issues).

## Credits

Thanks to `Matt Fryer` and his [Board Identify](https://github.com/MattFryer/Board_Identify) and his earlier work.
