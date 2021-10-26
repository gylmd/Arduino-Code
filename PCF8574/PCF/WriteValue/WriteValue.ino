#include "Arduino.h"
#include "PCF8574.h"

// Set the i2c HEX address
PCF8574 pcf8574(0x27);

void setup(){
  Serial.begin(115200);

  // Set the pinModes
  pcf8574.pinMode(P0, OUTPUT);
  pcf8574.pinMode(P1, OUTPUT);
   pcf8574.pinMode(P2, OUTPUT);
   pcf8574.pinMode(P3, OUTPUT);
   pcf8574.pinMode(P4, OUTPUT);
   pcf8574.pinMode(P5, OUTPUT);
   pcf8574.pinMode(P6, OUTPUT);
   pcf8574.pinMode(P7, OUTPUT);
  pcf8574.begin();
}

void loop(){
  pcf8574.digitalWrite(P0, HIGH);
  pcf8574.digitalWrite(P1, LOW);
  delay(1000);
  pcf8574.digitalWrite(P0, LOW);
  pcf8574.digitalWrite(P1, HIGH);
  delay(1000);
  pcf8574.digitalWrite(P2, HIGH);
  pcf8574.digitalWrite(P3, HIGH);
  pcf8574.digitalWrite(P4, HIGH);
  pcf8574.digitalWrite(P5, HIGH);
  pcf8574.digitalWrite(P6, HIGH);
  
}
