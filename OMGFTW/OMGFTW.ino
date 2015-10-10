#include <VirtualWire.h>
#include "Ultrasonic.h"
#include "DHT.h"


#define DHTPIN 2

#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
#define CM 1
#define INC 0
#define TPIN 9

DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ultrasonic(4, 5);
void setup() {
  Serial.begin(9600);
  Serial.print("This shit is going real!");
  dht.begin();
  vw_set_tx_pin(TPIN);
  vw_setup(2000);
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  char te[6], hu[6];
  dtostrf(t, 3, 2, te);
  dtostrf(h, 3, 2, hu);
  Serial.println(te);
  Serial.println(hu);
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    if (ultrasonic.Ranging(CM) <= 3)
    {
      Serial.println("Started transmitting!");
      vw_send((uint8_t *)te, strlen(te));
      vw_wait_tx();
      vw_send((uint8_t *)hu, strlen(hu));
      vw_wait_tx();
      Serial.println("Finished!");
      delay(1000);
    }
  }

  delay(100);
}
