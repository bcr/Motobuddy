# Overview
[![Build Status](https://travis-ci.org/bcr/Motobuddy.svg?branch=master)](https://travis-ci.org/bcr/Motobuddy)

This is the firmware source code for Motobuddy. Currently this supports the R0 variant of the system which is based on various Adafruit Feather boards stuck together.

* [Adafruit Feather M0 Bluefruit LE][adafruit-2995]
* [Adafruit Ultimate GPS FeatherWing][adafruit-3133]
* [FeatherWing OLED - 128x32 OLED Add-on For All Feather Boards][adafruit-2900]
* [DHT22 temperature-humidity sensor + extras][adafruit-385]
* [FeatherWing Doubler - Prototyping Add-on For All Feather Boards][adafruit-2890]

## PlatformIO
In order to build and run I use the [PlatformIO][platformio] system. This provides library management, board management, really solves all of the problems you have with managing multiple board environments and multiple libraries.

There are some minor compatibility issues right now with the Adafruit libraries and the PlatformIO system, the PlatformIO maintainers are super responsive and I was able to get the system working with the [development branch][platformio-devel] of the system.

To build and run I do `platformio run` to just build it, and `platformio run -t upload` to build it and upload it. PlatformIO works well with my preferred workflow which is using my own editor (TextMate) and command line via bash.

## Travis CI
I am using the Travis CI system to do build verification. This works well with PlatformIO also.

[adafruit-2995]: https://www.adafruit.com/product/2995
[adafruit-2900]: https://www.adafruit.com/products/2900
[adafruit-3133]: https://www.adafruit.com/product/3133
[adafruit-385]: https://www.adafruit.com/product/385
[adafruit-2890]: https://www.adafruit.com/product/2890
[platformio]: http://platformio.org/
[platformio-devel]: http://docs.platformio.org/en/stable/installation.html#development-version
