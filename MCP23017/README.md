# mcp23017  I2C written with aduino c

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
    
       

