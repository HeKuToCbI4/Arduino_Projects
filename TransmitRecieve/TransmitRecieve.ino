#include <VirtualWire.h>
#define TRPIN 5
#define STRLEN 256
void setup() {
  // put your setup code here, to run once:
Serial.begin(11250);
Serial.println("Started.");
vw_set_tx_pin(TRPIN);
vw_setup(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
char* line = malloc(STRLEN*sizeof(char));
line = Serial.readString()

free(line);
}
