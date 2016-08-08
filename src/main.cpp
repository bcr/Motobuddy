#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMonoBold24pt7b.h>   // See https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_GPS.h>
#include <Adafruit_NeoPixel.h>

#define OLED_RESET_PIN      -1      // Pin used for OLED reset signal, -1 is unused
#define DHT_PIN             5       // Pin which is connected to the DHT sensor.
#define GPSSerial           Serial1 // what's the name of the hardware serial port?
#define PIXEL_PIN           6       // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT         16      // Number of NeoPixels connected

#define GMT_OFFSET_HOURS    (-7)    // Current timezone relative to GMT

#define KNOTS_TO_MPH(KTS)           ((KTS) * 1.151)
#define CENTIMETERS_IN_INCH         (2.54)
#define INCHES_IN_FOOT              (12)
#define FEET_IN_METER               (3.28)
#define CENTIMETERS_TO_FEET(CM)     (((CM) / CENTIMETERS_IN_INCH) / INCHES_IN_FOOT)
#define METERS_TO_FEET(M)           ((M) * FEET_IN_METER)
#define CELSIUS_TO_FAHRENHEIT(C)    ((C) * 9 / 5 + 32)
#define TRUNC(N)                    ((int) (N))
#define ROUND(N)                    TRUNC((N) + .5)

// TEXT_Y_ORIGIN is a lot of fun. If you use the standard font, the origin when
// drawing is the upper left. If you use a custom font, the origin when drawing
// is the baseline. If you change the font, you may need to muck with this
// number until it looks right. You might want to compute this automatically,
// but that will depend on the characters you want to display.
#define TEXT_Y_ORIGIN   (30)

// http://platformio.org/lib/show/28/Adafruit-NeoPixel
// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Connect to the GPS on the hardware port
Adafruit_GPS GPS(&GPSSerial);

// http://platformio.org/lib/show/135/Adafruit-SSD1306
Adafruit_SSD1306 display(OLED_RESET_PIN);

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// http://platformio.org/lib/show/18/Adafruit-DHT-Unified
#define DHT_TYPE          DHT22     // DHT 22 (AM2302)
DHT_Unified dht(DHT_PIN, DHT_TYPE);

void setup()
{
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
    display.begin();  // initialize with the I2C addr
    display.display();
    display.setFont(&FreeMonoBold24pt7b);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    dht.begin();

    // 9600 NMEA is the default baud rate for Adafruit MTK GPS's- some use 4800
    GPS.begin(9600);
    // uncomment this line to turn on RMC (recommended minimum) and GGA (fix data) including altitude
    GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    // uncomment this line to turn on only the "minimum recommended" data
    //GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY);
    // For parsing data, we don't suggest using anything but either RMC only or RMC+GGA since
    // the parser doesn't care about other sentences at this time
    // Set the update rate
    GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // 1 Hz update rate
    // For the parsing code to work nicely and have time to sort thru the data, and
    // print it out we don't suggest using anything higher than 1 Hz

    // Request updates on antenna status, comment out to keep quiet
    GPS.sendCommand(PGCMD_ANTENNA);

//    strip.begin();
//    strip.show(); // Initialize all pixels to 'off'

    display.clearDisplay();
}

void loop()
{
    // GPS updating. I can't imagine this would run forever, but let it run
    while (GPS.read() != 0);

    if (GPS.newNMEAreceived())
    {
        if (GPS.parse(GPS.lastNMEA()))
        {
            display.clearDisplay();
            display.setCursor(0, TEXT_Y_ORIGIN);

            if ((GPS.seconds % 10) < 5)
            {
                const char* separatorChar = (GPS.seconds % 2) ? " " : ":";

                // Output the time now that we have new data
                int finalHour = GPS.hour + GMT_OFFSET_HOURS;
                if (finalHour < 0)
                {
                    finalHour += 24;
                }
                else if (finalHour > 24)
                {
                    finalHour -= 24;
                }

                // Convert to 12 hour format
                finalHour = (finalHour + 12) % 12;

                display.print(finalHour);
                display.print(separatorChar);
                if (GPS.minute < 10)
                {
                    display.print("0");
                }
                display.print(GPS.minute);
                display.println();
            }
            else
            {
                sensors_event_t event;
                dht.temperature().getEvent(&event);
                if (isnan(event.temperature))
                {
                    display.println("Temp broken");
                }
                else
                {
                    display.print(ROUND(CELSIUS_TO_FAHRENHEIT(event.temperature)));
                    display.println("F");
                }
            }

            display.display();
        }
    }
}
