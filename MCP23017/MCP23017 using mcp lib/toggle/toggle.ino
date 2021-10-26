#include <Wire.h>
#include "Adafruit_MCP23017.h"

// Basic pin reading and pullup test for the MCP23017 I/O expander
// public domain!

// Connect pin #12 of the expander to Analog 5 (i2c clock)
// Connect pin #13 of the expander to Analog 4 (i2c data)
// Connect pins #15, 16 and 17 of the expander to ground (address selection)
// Connect pin #9 of the expander to 5V (power)
// Connect pin #10 of the expander to ground (common ground)
// Connect pin #18 through a ~10kohm resistor to 5V (reset pin, active low)

// Output #0 is on pin 21 so connect an LED or whatever from that to ground

Adafruit_MCP23017 mcp;
  
void setup() {  
  mcp.begin();      // use default address 0

  mcp.pinMode(0, OUTPUT);
  mcp.pinMode(9, OUTPUT);
  mcp.pinMode(10, OUTPUT);
  mcp.pinMode(11, OUTPUT);

  mcp.pinMode(1, INPUT);
  mcp.pinMode(2, INPUT);
  mcp.pinMode(8, INPUT);
  mcp.pinMode(12, INPUT);
    mcp.digitalWrite(0, HIGH);
  mcp.digitalWrite(9, HIGH);
  mcp.digitalWrite(11, HIGH);
  mcp.digitalWrite(10, HIGH);

}


// flip the pin #0 up and down

void loop() {


 if ( mcp.digitalRead(1)== HIGH)
 mcp.digitalWrite(0, LOW);
 else mcp.digitalWrite(0, HIGH);

 if ( mcp.digitalRead(2)== HIGH)
 mcp.digitalWrite(9, LOW);
 else mcp.digitalWrite(9, HIGH);

  if ( mcp.digitalRead(8)== HIGH)
 mcp.digitalWrite(10, LOW);
 else mcp.digitalWrite(10, HIGH);

  if ( mcp.digitalRead(12)== HIGH)
 mcp.digitalWrite(11, LOW);
 else mcp.digitalWrite(11, HIGH);

  
     

}
