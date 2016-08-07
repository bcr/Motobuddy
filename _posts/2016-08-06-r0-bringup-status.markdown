---
layout: post
title:  "R0 Bringup Status"
date:   2016-08-06 23:12:39 -0700
author: Blake Ramsdell
---
Feather bringup with PlatformIO was uneventful. I was able to `platformio run -t upload` with a blinking LED no problems. I even changed the duty cycle so that I wasn't confused by the blinking LED example that was probably already running from the factory.

OLED bringup was similarly uneventful -- the [Adafruit example][adafruit-ssd1306-example] needed some reorganization, as the default compiler settings seemed to be crabby about calling functions without a prototype. No big deal, just moved the `setup` function definition below everyone else.

GPS bringup. Again, uneventful. I was able to get a fix fairly quickly, even in my house. Data updated once per second as expected. Right this second I have an accurate clock on the OLED, updating every second. That's half of the stated functionality!

* ***DONE*** Feather bringup with PlatformIO
* ***DONE*** Solder headers on Feather and OLED
* ***DONE*** Bringup OLED
* ***DONE*** Solder headers on GPS
* ***DONE*** Bringup GPS
* ***DONE*** Solder headers on Doubler
* ***DONE*** Install everyone, make sure they still run
* Find analog pin for DHT
* Hook up temporary DHT for bringup
* Bringup DHT
* Finalize location and install DHT
* Make sure everything still runs
* Turd polishing GUI (futz around for too long making the GUI just right, and still be mad at it)
* Rubber bands or zip tie to handlebars
* Road test
* Verify speed
* Verify altitude

[adafruit-ssd1306-example]: https://github.com/adafruit/Adafruit_SSD1306/blob/master/examples/ssd1306_128x32_i2c/ssd1306_128x32_i2c.ino
