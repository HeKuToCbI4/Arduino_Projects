#include "VirtualWire.h"

#define RPIN 5
uint8_t message[VW_MAX_MESSAGE_LEN];
uint8_t messageLength = VW_MAX_MESSAGE_LEN;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Reading data from transmitter!");
  vw_set_rx_pin(RPIN);
  vw_setup(2000);
  vw_rx_start();
}

void loop() { 
  // put your main code here, to run repeatedly:
  vw_wait_rx();
  if (vw_get_message(message, &messageLength))
  {
    Serial.print("Temperature: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.print(char(message[i]));
    }
    Serial.println();
  }
  vw_wait_rx();
  if (vw_get_message(message, &messageLength))
  {
    Serial.print("Humidity: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.print(char(message[i]));
    }
    Serial.println();
  }
  //Serial.println("Waiting!");
}

