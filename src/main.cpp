#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_GPS.h>
#include <Adafruit_NeoPixel.h>

#define OLED_RESET_PIN      -1      // Pin used for OLED reset signal, -1 is unused
#define DHT_PIN             2       // Pin which is connected to the DHT sensor.
#define GPSSerial           Serial1 // what's the name of the hardware serial port?
#define PIXEL_PIN           6       // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT         16      // Number of NeoPixels connected

// http://platformio.org/lib/show/28/Adafruit-NeoPixel
// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

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

    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
    // GPS updating. I can't imagine this would run forever, but let it run
    while (GPS.read() != 0);

    if (GPS.newNMEAreceived())
    {
        if (GPS.parse(GPS.lastNMEA()))
        {
            // We have new GPS data, if you want to optimize screen update
        }
    }

    // For temperature and humidity from the DHT, that's on a polled basis,
    // so maybe cool your jets and don't poll every time through the loop
}