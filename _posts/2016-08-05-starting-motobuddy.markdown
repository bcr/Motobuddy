---
layout: post
title:  "Starting Motobuddy"
date:   2016-08-05 18:40:21 -0700
author: Blake Ramsdell
---
It was hot the other day. I went to ride my bike and I didn't know what the temperture was. I think I have a speaker jammed into the hole where the air temp is on other bikes.

Then I looked at the clock on the head unit and of course that's like 20 minutes off. It drifts constantly, it's only somewhat accurate when I set it when DST changes. Because, you know, having an accurate digital clock isn't a solved problem for the last 30 years.

So that made me mad enough to go order a bunch of parts at Adafruit.

My plan is to plug all of it together and then dial in some code for the display.

Then I think I'll stick it in some kind of box and strap it to my handlebars and hook it up to my bike's power supply.

# Parts
This is what I'm starting with. Plus a bunch of headers:

* [Adafruit Feather M0 Bluefruit LE][adafruit-2995]
* [FeatherWing OLED - 128x32 OLED Add-on For All Feather Boards][adafruit-2900]
* [Adafruit Ultimate GPS FeatherWing][adafruit-3133]
* [DHT22 temperature-humidity sensor + extras][adafruit-385]
* [FeatherWing Doubler - Prototyping Add-on For All Feather Boards][adafruit-2890]

I am curious about the OLED display. I think it's pretty constrained, but it was available in Feather form, so I figured I'd try it. I don't have a lot of output, so we'll see how legible it is at various sizes and what I can fit on the screen. But it should behave adequately in the wide variety of outdoor lighting conditions, so we'll see how it goes. I can always shade it with my hand in bright sunlight.

The GPS should give me an accurate UTC time. I'll need to figure out some way to configure or compute the timezone. As an overly optimistic software guy, I am assuming that given a GPS location I can figure out the timezone. But there's probably some amount of heartache regarding DST rules and assigning those to GPS regions that is going to make me cry.

I also get altitude and speed data if I want it. And maybe automatic periodic logging for saving trips.

As an American, I looked into an RTC solution, seeding from [WWVB][WWVB]. That might be fun to do at some point, but right now I just want the clock to work, and I don't want to go through any effort to set it, and I haven't found any WWVB decoding solution that I like.

The DHT22 should give me reasonably accurate temperature information (±0.5°C, or around ±0.9°F). Plus it has humidity information if I want that.

I got the Doubler so that I could have the display and GPS on "top" -- I'll probably put the M0 under the OLED and then the GPS on the other side of the Doubler. We'll see if the GPS performance is good enough to get the time or if I need to add an external antenna.

I haven't figured out the power situation yet. I have tons of 12VDC on the bike, but it looks like I need to step that down to at least 6VDC (optimally 5VDC) to meed the requirements of the charging circuit. I'd like to jack the charge rate up to 1000mA, but this requires a resistor change, and then when I plug it into a PC I need to be careful that I'm not drawing more than the USB port can provide -- my assumption is that if there's no battery attached then the draw should be the normal draw of the circuit, so I should be OK with no battery.

# Mechanical
I don't know what to do for an enclosure yet. I'd like for a first cut:

* Mounts on bike
* Readable display
* Enough GPS reception to get the time
* Weatherproof
* Runs all day

I have the mechanical team on it. We'll see what they come up with.

I don't know what to do for buttons. There's some teeny buttons on the OLED shield that are going to be useless while wearing gloves. I was thinking about maybe some kind of vibration sensor or accelerometer and then you just smack it to "do something else". Or maybe there's no interaction, and if there's multiple screens, switch between them periodically. Not sure yet.

# Firmware
I'm also using this project to try out [Platform.io][platformio] as a development environment. I'm a sucker for command lines. I have built a project that includes all of the libraries for the various parts and it compiles. We'll see what happens when I get all the parts.

# Wrapping Up
I'm not particularly married to the Feather M0, but I may have some evil master plan that needs Bluetooth. I may actually try a [Teensy 3.2][teensy] and forgo Bluetooth or graft it on, but then I'll either need to use the Feather adapter (sold out at Adafruit), or hotwire it into the FeatherWings. Plus I'll need to figure out the battery management if I don't use the Feather adapter.

[adafruit-2995]: https://www.adafruit.com/product/2995
[adafruit-2900]: https://www.adafruit.com/products/2900
[adafruit-3133]: https://www.adafruit.com/product/3133
[adafruit-385]: https://www.adafruit.com/product/385
[adafruit-2890]: https://www.adafruit.com/product/2890
[WWVB]: https://en.wikipedia.org/wiki/WWVB
[platformio]: http://platformio.org/
[teensy]: https://www.pjrc.com/store/teensy32.html
