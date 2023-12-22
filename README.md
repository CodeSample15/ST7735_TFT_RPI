[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/paypalme/whitelight976)

![ ig ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/st7735/pcb.jpg)

#  ST7735_TFT_RPI

## Table of contents


  * [Overview](#overview)
  * [Installation](#installation)
  * [Test](#test)
  * [Software](#software)
      * [API](#api)
      * [User Options](#user-options)
      * [File system](#file-system)
      * [Fonts](#fonts)
      * [Bitmap](#bitmap)  
  * [Hardware](#hardware)
  * [Output](#output)
  * [Notes and Issues](#notes-and-issues)
	* [Compilation problems](#compilation-problems)

## Overview

* Name: ST7735_TFT_RPI
* Description:

0. C++ Library for a TFT SPI LCD, ST7735 Driver
1. Dynamic install-able Raspberry Pi C++ library.
2. Inverse colour, rotate, sleep, idle  & vertical scroll modes supported.
3. 10 fonts
4. Graphics + print class included.
5. 24 bit colour , 16 bit color & bi-color Bitmaps supported.
6. Hardware and Software SPI
7. Dependency: bcm2835 Library

* Author: Gavin Lyons
* Port of my PIC library at [github link.](https://github.com/gavinlyonsrepo/pic_16F18346_projects)

* Development ToolChain 
    1. Raspberry PI 3 model b
    2. C++ g++ (Raspbian 8.3.0-6+rpi1) 8.3.0
    3. Raspbian 10 Buster OS , armv7l Linux 5.10.63-v7. 32 bit. 
    4. bcm2835 Library 1.68

## Installation

1. Make sure SPI bus is enabled on your raspberry PI

2. Install the dependency bcm2835 Library if not installed (at time of writing latest version is 1.68.)
	* The bcm2835 library  provides SPI bus, delays and GPIO control.
	* Install the C libraries of bcm2835, [Installation instructions here](http://www.airspayce.com/mikem/bcm2835/)

3. Download the STT735_TFT_RPI library
	* Open a Terminal in a folder where you want to download,build & test library
	* Run following command to download from github.

```sh
curl -sL https://github.com/gavinlyonsrepo/ST7735_TFT_RPI/archive/1.7.tar.gz | tar xz
```

4. Install library. Run "make" to run the makefile to install library, it will be
    installed to usr/lib and usr/include 

```sh
cd ST7735_TFT_RPI-1.7
make
sudo make install
```

Note :: to uninstall library run sudo make uninstall

## Test

1. Next step is to test TFT and installed library with the included main.cpp test example file.
Wire up your TFT. Next enter the example folder and run the makefile in THAT folder,
This second makefile builds the examples file using the just installed library,
and creates a test exe file in "bin". Make run will use "sudo" as the bcm2835 requires root permissions by default [see here for details](http://www.airspayce.com/mikem/bcm2835/)
you should now see the test routines in that file running on the display. The example file is setup by default for a 128x128 red tab TFT.

```sh
cd example/
make
make run
```

2. There are three examples files. The default example file is Hello World.
To decide which one the makefile(In examples folder) builds simply edit "SRC" variable
at top of the makefile. In the "User SRC directory Option Section" at top of file.
Pick an example "SRC" directory path and ONE ONLY.

| # | example file name  | Desc|
| ------ | ------ |  ------ |
| 1 | src/Hello_world| Basic use case |
| 2 | src/Tests | Tests graphics, text, fonts, bitmap's & functions|
| 3 | src/Frame_rate_test | Frame rate per second (FPS) speed test |


## Software

### API

The API (application programming interface) documentation is at link hosted on github pages and generated by Doxygen. 

[ URL](https://gavinlyonsrepo.github.io/misc/software_docs/ST7735_TFT_RPI/index.html) 

### User options

In the example files. There are 3 sections in "Setup()" function 
where user can make adjustments to select for SPI type used, PCB type used and screen size.


1. USER OPTION 1 GPIO/SPI TYPE
2. USER OPTION 2 SCREEN SECTION 
3. USER OPTION 3 PCB_TYPE, SPI SPEED , SPI_CE_PIN


*USER OPTION 1 SPI TYPE / GPIO*

This library supports both Hardware SPI and software SPI.
The parameters set for TFTSetupGPIO define which is used, by default its Hardware.
to switch between the two: set SCLK, SDIN and CS to -1 for HW SPI
set them to valid GPIO numbers for SW SPI. HW SPI is far faster and more reliable than SW SPI
If user is having reliability issues with SW SPI in some setups. The user can adjust 
the TFT_HIGHFREQ_DELAY setting in ST7735_TFT.h file, this is a microsecond
delay in SW SPI loop. It is set to 0 by default, Increasing it will slow 
down SW SPI further.


*USER OPTION 2 Screen size  + Offsets*

User can adjust screen pixel height, screen pixel width and x & y screen offsets.
These offsets can be used in the event of screen damage or manufacturing errors around edge 
such as cropped data or defective pixels.
The function TFTInitScreenSize sets them.

*USER OPTION 3 PCB Version, SPI SPEED , SPI_CE_PIN*

TFTInitPCBType method

1. Param1 PCB_TYPE

In the main.cpp in USER OPTION 3 PCB_TYPE select your display type.
By passing an enum type to function  TFTInitPCBType.
Default is "TFT_ST7735R_Red". There are 4 types of the ST7735 TFT display supported.
If your display works but RGB colors are inverted you may have chosen wrong display type.

| Number | Description | Enum label| Tested |
| ---- | ---- | --- | ---| 
| 1 | ST7735B controller| TFT_ST7735B | n/a |
| 2 | ST7735R Green Tab | TFT_ST7735R_Green | n/a |
| 3 | ST7735R Red Tab   | TFT_ST7735R_Red | RED PCB v1.1, 1.44, 128x128 pixels |
| 4 | ST7735S Black Tab | TFT_ST7735S_Black | RED PCB v1.2, 1.8, 128 x 160 pixels |

2. Param2 SPI_Speed (HW SPI Only)

Here the user can pass the SPI Bus freq in Hertz,
Maximum 125 Mhz , Minimum 30Khz, The default in file is 8Mhz 
If you set to 0 .Speed is set to bcm2835 
constant BCM2835_SPI_CLOCK_DIVIDER_32. If using SW spi, ignore.

3. Param3 SPI_CE_PIN (HW SPI Only)

Which Chip enable pin to use two choices. If using SW spi, ignore.
	* SPICE0 = 0
	* SPICE1 = 1


### File system

In example folder:
The Main.cpp file contains tests showing library functions.
A bitmap data file contains data for bi-color bitmaps and icons tests.
The color bitmaps used in testing are in bitmap folder, 3 16-bit and 3 24-bit images.

There are two makefiles

    1. At root directory builds and installs library at a system level.
    2. Example directory builds example file + installed library to an executable.


### Fonts

10 fonts available : 

| # | name | Char size WxH | ASCII range | Size in bytes | 
| ------ | ------ | ------ | ------ | ------ |
| 1 | Default | 5x8 | Full Extended ASCII 0x00 - 0xFF | 1275 |
| 2 | Thick   | 7x8 | ASCII  0x20 - 0x5A  , no lowercase letters | 406 |
| 3 | Seven segment | 4x8 | ASCII  0x20 - 0x7A | 364 |
| 4 | Wide | 8x8 | ASCII 0x20 - 0x5A , no lowercase letters | 464 | 
| 5 | Tiny | 3x8 | ASCII  0x20 - 0x7A | 285 |
| 6 | Homespun | 7x8 | ASCII  0x20 - 0x7A | 658 |
| 7 | Big Nums | 16x32 | ASCII 0x2E-0x3A , Numbers + : . only | 704 |
| 8 | Med Nums | 16x16 | ASCII 0x2E-0x3A , Numbers + : . only | 352 |
| 9 | Arial round| 16x24 | ASCII 0x20 - 0x7E | 4608 |
| 10 | Arial bold | 16x16 | ASCII 0x20 - 0x7E | 3072 |

1. Fonts 1-6 are byte high(at text size 1) scale-able fonts,
2. The large numerical fonts, 7 - 8 cannot be scaled.
3. The large alphanumeric fonts, 9 - 10  cannot be scaled.

### Bitmap

There are four functions to support drawing bitmaps

| Function Name | Colour support | Pixel size |  Note |
| ------ | ------ | ------ | ------ |
| TFTdrawIcon | bi-colour | 8 x(0-127)   | Data vertically addressed |
| TFTdrawBitmap | bi-colour |  2048 bytes max | Data horizontally  addressed |
| TFTdrawBitmap16 | 16 bit color 565 BMP files |  32K max | ------ |
| TFTdrawBitmap24  | 24 bit color BMP files | 48K max | Converted by software to 16-bit color  |

1. Bitmap size in kiloBytes = (screenWidth * screenHeight * bitsPerPixel)/(1024 * 8)
2. Pixel size column assumes 128 by 128 screen.

## Hardware

Connections as setup in main.cpp test file.

| TFT PinNum | Pindesc | RPI HW SPI | RPI SW SPI |
| --- | --- | --- | --- |
| 1 | LED | VCC |  VCC |
| 2 | SCLK | SPI_CLK | GPIO5 |
| 3 | SDA | SPI_MOSI | GPIO6 |
| 4 | A0/DC | GPIO24 | GPIO24  |
| 5 | RESET | GPI025  | GPIO25 |
| 6 | SS/CS | SPI_CE0 | GPIO8 |
| 7 | GND | GND | GND |
| 8 | VCC | VCC | VCC  |

1. Connect LED backlight pin 1 thru a 150R/220R ohm resistor to 3.3/5V VCC.
2. This is a 3.3V logic device do NOT connect the I/O logic lines to 5V logic device.
3. You can connect VCC to 5V if there is a 3.3 volt regulator on back of TFT module.
4. Pick any GPIO you want for SW SPI for HW SPI: reset and DC lines are flexible.
5. User can select  SPI_CE0  or SPI_CE1 for HW SPI
![ wiring ](https://github.com/gavinlyonsrepo/ST7735_TFT_RPI/blob/main/extra/images/wiring.jpg)
6. Backlight control is left to user.

## Output

Output of some of the test routine's. Left to right, top to bottom.

1. Different defined colors at default font size 1. Full 16 bit colour 565 available
2. Different sizes of default font. Size 2 3 4 & 5 shown.
3. Different Fonts at font size 2, fonts 1-5. Are these fonts are scale-able, font 6 not shown.
4. Shapes
5. More Shapes!
6. Bitmap (bi-color) A background and a foreground.
7. Clock Demo showing icons, small bitmaps and font 7 "BigNums"
8. 24-bit color bitmap test image
9. 16-bit color bitmap test image

![ pic ](https://github.com/gavinlyonsrepo/pic_16F18346_projects/blob/master/images/st7735/9.jpg)
![ pic1 ](https://github.com/gavinlyonsrepo/ST7735_TFT_RPI/blob/main/extra/images/4.jpg)


### Compilation problems

Note the toolchain used in overview section, If you have trouble compiling on other 
platforms or OS. For example 64-bit OS, user may need to remove or edit
some of the CCFLAGS in root directory Makefile to allow for Compilation, if you see them throwing errors
See [pull request on SSD1306 project](https://github.com/gavinlyonsrepo/SSD1306_OLED_RPI/pull/2) for details.
Will upgrade in future release.
