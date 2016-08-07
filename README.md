This is the firmware source code for Motobuddy. Currently this supports the R0 variant of the system which is based on various Adafruit Feather boards stuck together.

* [Adafruit Feather M0 Bluefruit LE][adafruit-2995]
* [Adafruit Ultimate GPS FeatherWing][adafruit-3133]
* [FeatherWing OLED - 128x32 OLED Add-on For All Feather Boards][adafruit-2900]
* [DHT22 temperature-humidity sensor + extras][adafruit-385]
* [FeatherWing Doubler - Prototyping Add-on For All Feather Boards][adafruit-2890]

This is built using the [PlatformIO][platformio] system. When I set up the system initially I did the following:

```
platformio init --board adafruit_feather_m0_usb
platformio lib install 18
platformio lib install 135
platformio lib install 19
platformio lib install 20
platformio lib install 28
```

To build and run I do `platformio run` to just build it, and `platformio run -t upload` to build it and upload it. I have not run into anything funny with the PlatformIO integration, and it works well with my preferred workflow which is using my own editor (TextMate) and command line via bash.

[adafruit-2995]: https://www.adafruit.com/product/2995
[adafruit-2900]: https://www.adafruit.com/products/2900
[adafruit-3133]: https://www.adafruit.com/product/3133
[adafruit-385]: https://www.adafruit.com/product/385
[adafruit-2890]: https://www.adafruit.com/product/2890
[platformio]: http://platformio.org/