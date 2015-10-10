#include "DHT.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#define DHTPIN 8


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2



// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)



// Software SPI (slower updates, more flexible pin options):
// pin 6 - Serial clock out (SCLK)
// pin 5 - Serial data out (DIN)
// pin 4 - Data/Command select (D/C)
// pin 3 - LCD chip select (CS)
// pin 2 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.print("This shit is going real!");
  dht.begin();
  display.begin();
  display.setContrast(50);
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h) && (t > 0) && (h > 0)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.println(t);
    Serial.println(h);

    //display.setTextColor(BLACK);
    display.setTextSize(1);
    delay(200);
    display.clearDisplay();
    display.setCursor(10, 20);
    display.print("Temp: ");
    display.println(t);
    display.setCursor(10, 28);
    display.print("Humid: ");
    display.println(h);
    display.display();

  }
}