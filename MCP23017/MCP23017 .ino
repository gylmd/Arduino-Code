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

    SetupRelays();

  This will set all possible I2C Relay Board MCP23017 registers
  as outputs, and turn all relays off.
  This command should be part of the setup()
  
  
  To set each I2C Relay Board outputs, use the following command:
  
    WriteRelays(board_address, board_relays)
    
    where 
    - board_address is the address of each individual I2C Relay Board
    - board_relays  is the 8 bit data to control the 8 relays
      all relays on the board are updated at once using the 8-bit data.
    
    examples:
    -  WriteRelays(0, 0b00000001);  // on card 0, switch only relay 1 on
    -  WriteRelays(0, 0b00000010);  // on card 0, switch only relay 2 on
    -  WriteRelays(4, 0b11111111);  // on card 4, switch all relays on
    -  WriteRelays(4, 0b00000000);  // on card 4, switch all relays off
    -  WriteRelays(7, 0b11110000);  // on card 7, relays 1,2,3,4 off, 5,6,7,8 on
    -  WriteRelays(6, 0b00001111);  // on card 6, relays 1,2,3,4 on   5,6,7,8 off
    
       
  Created by Eric Brouwer
  July 2015

*/

#include <Wire.h>     // needed for I2C operation

void setup() {
  //start I2C communications
  Wire.begin();

  // Setup relay boards
  SetupRelays();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (byte relaydata = 64; relaydata <= 1024; relaydata = relaydata + 32) {
    // write data to cards 0 .. 7 relays
    WriteRelays(0,relaydata);    // write data to relay card 0
    WriteRelays(1,relaydata);    // write data to relay card 1
 /*   WriteRelays(2,relaydata);    // write data to relay card 2
    WriteRelays(3,relaydata);    // write data to relay card 3
    WriteRelays(4,relaydata);    // write data to relay card 4
    WriteRelays(5,relaydata);    // write data to relay card 5
    WriteRelays(6,relaydata);    // write data to relay card 6
    WriteRelays(7,relaydata);    // write data to relay card 7*/
    delay(200);  
  }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Begin of MCP routines - no library needed
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void SetupRelays() {
  // Setup all possible relay cards (address 0 to 7)
  for (byte i = 0; i <= 7; i = i + 1) {
    MCP_Write(i, 0x00, 0b00000000);      //  set all pins to output
    MCP_Write(i, 0x12, 0b00000000);      //  set all outputs to off
  }
}

void WriteRelays(byte address, byte data) {
  // Write data to relays
  // --------------------
  MCP_Write(address, 0x12, data);
}

void MCP_Write(byte MCPaddress, byte MCPregister, byte MCPdata) {
  // I2C write routine 
  // -----------------
  MCPaddress = MCPaddress + 0x20;    // 0x20 is base address for MCP
  Wire.beginTransmission(MCPaddress);
  Wire.write(MCPregister);
  Wire.write(MCPdata);
  Wire.endTransmission();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// End of MCP routines
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
