---
layout: post
title:  "R0 Parts Arrive"
date:   2016-08-06 16:26:26 -0700
author: Blake Ramsdell
---
![Motobuddy R0 Parts]({{ site.baseurl }}/assets/motobuddy-r0-parts.jpg)

Got my box of parts from Adafruit today. You can see in the picture (top to bottom, left to right):

* [FeatherWing Doubler - Prototyping Add-on For All Feather Boards][adafruit-2890]
* US Quarter Dollar. Because scale.
* [Adafruit Feather M0 Bluefruit LE][adafruit-2995]
* [Adafruit Ultimate GPS FeatherWing][adafruit-3133]
* [FeatherWing OLED - 128x32 OLED Add-on For All Feather Boards][adafruit-2900]
* [DHT22 temperature-humidity sensor + extras][adafruit-385]

Not pictured is [Lithium Ion Battery - 3.7v 2000mAh][adafruit-2011] that I plan to use while I figure out power.

Man that display is small for a 2-3 foot viewing distance. Like 4x too small. At least. Well anyway, it's POC, and I don't think the display is the hard part. So there.

I'm going to try and bring up the Feather with a blinky LED to make sure that [PlatformIO][platformio] and the Feather are happy with each other. Then I think I have to solder a header or two on these things to get them all to plug together.

Current R0 Master Plan:

* Feather bringup with PlatformIO
* Solder headers on Feather and OLED
* Bringup OLED
* Solder headers on GPS
* Bringup GPS
* Solder headers on Doubler
* Install everyone, make sure they still run
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

[adafruit-2995]: https://www.adafruit.com/product/2995
[adafruit-2900]: https://www.adafruit.com/products/2900
[adafruit-3133]: https://www.adafruit.com/product/3133
[adafruit-385]: https://www.adafruit.com/product/385
[adafruit-2890]: https://www.adafruit.com/product/2890
[adafruit-2011]: https://www.adafruit.com/product/2011
[platformio]: http://platformio.org/