/*
  This sketch explain how to control the I2C Relay Board.
  Each I2C Relay Board is fitted with a MCP23017 I/O expander, 
  which gives an additional 8 outputs per board. These outputs
  are used to control the 8 relays.
  
  No library is needed for the MCP23017, as all I2C code 
  is included in this sketch.
  
  Each board has 3 address jumpers, A0, A1 and A2. This allows 
  for up to 8 I2C Relay Boards to be conneted on the I2C bus.
  Address range is between 0 and 7.
  
  To set up the I2C Relay Boards, use the following command:

    Setup_a();

  This will set all possible I2C Relay Board MCP23017 registers
  as outputs, and turn all relays off.
  This command should be part of the setup()
  
  
  To set each I2C Relay Board outputs, use the following command:
  
    Write_a(board_address, board_relays)
    
    where 
    - board_address is the address of each individual I2C Relay Board
    - board_relays  is the 8 bit data to control the 8 relays
      all relays on the board are updated at once using the 8-bit data.
    
    examples:
    -  Write_a(0, 0b00000001);  // on card 0, switch only relay 1 on
    -  Write_a(0, 0b00000010);  // on card 0, switch only relay 2 on
    -  Write_a(4, 0b11111111);  // on card 4, switch all relays on
    -  Write_a(4, 0b00000000);  // on card 4, switch all relays off
    -  Write_a(7, 0b11110000);  // on card 7, relays 1,2,3,4 off, 5,6,7,8 on
    -  Write_a(6, 0b00001111);  // on card 6, relays 1,2,3,4 on   5,6,7,8 off
    

*/

#include <Wire.h>     // needed for I2C operation
byte a;
void setup() {
  //start I2C communications
  Wire.begin();

  // Setup relay boards
  Setup_a();
  Setup_b();
}

void loop() {
  // put your main code here, to run repeatedly:
  

    Write_a(0,relaydata);    // write data to relay card 0
    Write_b(0,relaydata);
    delay(200);  
  }

  
  Wire.endTransmission();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Begin of MCP routines - no library needed
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Setup_a() {
  // Setup all possible relay cards (address 0 to 7)
  for (byte i = 0; i <= 7; i = i + 1) {
    MCP_Write(i, 0x00, 0b00000000);      //  set all pins to output
    MCP_Write(i, 0x12, 0b00000000);      //  set all outputs to off
  }
}
void Setup_b() {
  // Setup all possible relay cards (address 0 to 7)
  for (byte i = 0; i <= 7; i = i + 1) {
    MCP_Write(i, 0x01, 0b00000000);      //  set all pins to output
    MCP_Write(i, 0x13, 0b00000000);      //  set all outputs to off
  }
}

void Write_a( byte data) {
  // Write data to relays
  // --------------------
  MCP_Write(0x00, 0x12, data);
}

void Write_b(byte address, byte data) {
  // Write data to relays
  // --------------------
  MCP_Write(address, 0x13, data);
}

void MCP_Write(byte MCPaddress, byte MCPregister, byte MCPdata) {

  MCPaddress = MCPaddress + 0x20;    // 0x20 is base address for MCP
  Wire.beginTransmission(MCPaddress);
  Wire.write(MCPregister);
  Wire.write(MCPdata);
  Wire.endTransmission();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// End of MCP routines
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
