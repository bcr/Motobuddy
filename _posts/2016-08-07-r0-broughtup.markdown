---
layout: post
title:  "R0 Broughtup"
date:   2016-08-07 21:13:05 -0700
author: Blake Ramsdell
---
![Motobuddy R0 Up and Running]({{ site.baseurl }}/assets/motobuddy-r0-time-temperature.jpg)

It pretty much does all the stuff I want. You know, time and temperature. I probably spent way too much time futzing with the DHT22 placement and wiring. And I used 26 gauge solid core wire which isn't really the right idea.

I think electrically R0 is as done as it's getting. I spent a lot of time futzing around with getting the DHT22 mounted. But it's mounted and it works and no magic smoke was released, so I'm going to call it a victory.

There is the matter of hooking into the bike power rail, but I'm not thinking about that yet, since I can accomplish pretty much everything I want with battery power.

As a general observation, I really hate committing to a pin with solder. I spend an inordinate amount of time fretting over whether the other pin functions might be something I need in the future, whether I'm unnecessarily burning a PWM pin, etc. For what it's worth, I'm using the M0 digital pin 5 next to SCL and SDA. I need to relax more and just connect and pray I guess.

Speed and altitude are iffy. I was in Bellevue with a GPS fix and my altitude was negative two hundred feet. Speed isn't close enough to warrant using it, off by at least 10%, indicates moving when completely stationary.

I don't have a reference thermometer yet, but temperature seems reasonable. In the picture is the remote for my gas fireplace that indicates the ambient temperature. 24.3°C is 75.74°F which is of course not 73°F as reported by the remote. But the remote could be a jerk. I think this is close enough in any case.

![Rainy Forecast]({{ site.baseurl }}/assets/2016-08-07-forecast.png)

Weather is looking pissy tomorrow, plus the mechanical team hasn't figured out how to strap this sucker to the bars, so I presume there will just be more UI work.

Still looking for display options and yelling at the mechanical team for more warp speed. Electrical team spent half the day handwringing about the DHT placement and messing around with Amazon Echo. I have some 30 gauge wire on order, hopefully that helps.

* ***DONE*** Feather bringup with PlatformIO
* ***DONE*** Solder headers on Feather and OLED
* ***DONE*** Bringup OLED
* ***DONE*** Solder headers on GPS
* ***DONE*** Bringup GPS
* ***DONE*** Solder headers on Doubler
* ***DONE*** Install everyone, make sure they still run
* ***DONE*** Find analog, er I mean digital, pin for DHT
* ***DONE*** Hook up temporary DHT for bringup
* ***DONE*** Bringup DHT
* ***DONE*** Finalize location and install DHT
* ***DONE*** Make sure everything still runs
* Turd polishing GUI (futz around for too long making the GUI just right, and still be mad at it)
* Rubber bands or zip tie to handlebars
* Road test
* ***DONE*** Verify speed
* ***DONE*** Verify altitude
