#include <SoftwareSerial.h>
// Configure software serial port
SoftwareSerial SIM900(12,13);

// Variable to store text message
String textMessage;
String message;
// Create a variable to store Lamp state
String lampState_1 = "Canal_1: ON\n";
String lampState_2 = "Canal_2: ON\n";
String lampState_3 = "Canal_3: ON\n";
String lampState_4 = "Canal_4: ON\n";
String lampState_5 = "Canal_5: ON\n";
String lampState_6 = "Canal_6: ON\n";
String lampState_7 = "Canal_7: ON\n";
String lampState_8 = "Canal_8: ON\n";

// Relay connected to pin 12
const int relay_1= 9;
const int relay_2 = 2;
const int relay_3 = 3;
const int relay_4 = 4;
const int relay_5 = 5;
const int relay_6 = 6;
const int relay_7 = 7;
const int relay_8 = 8;
int i;
void setup() {
  // Automatically turn on the shield
  //digitalWrite(9, HIGH);
  delay(1000);
 // digitalWrite(9, LOW);
  delay(5000);
  
  // Set relay as OUTPUT
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  pinMode(relay_5, OUTPUT);
  pinMode(relay_6, OUTPUT);
  pinMode(relay_7, OUTPUT);
  pinMode(relay_8, OUTPUT);
  pinMode(11,INPUT);
  // By default the relay is off
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
  digitalWrite(relay_3, HIGH);
  digitalWrite(relay_4, HIGH);
  digitalWrite(relay_5, HIGH);
  digitalWrite(relay_6, HIGH);
  digitalWrite(relay_7, HIGH);
  digitalWrite(relay_8, HIGH);
  
  // Initializing serial commmunication
  Serial.begin(19200); 
  SIM900.begin(19200);

  // Give time to your GSM shield log on to network
  delay(5000);
  Serial.print("SIM900 ready...");

  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

void loop(){
  if(SIM900.available()>0){
    textMessage = SIM900.readString();
    Serial.print(textMessage);    
    delay(10);
  } 

    if(textMessage.indexOf("ON_1")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_1, LOW);
    lampState_1 = "Canal_1: ON\n";
    Serial.println("Canal_1: ON");  
    textMessage = "";   
  }
  
  if(textMessage.indexOf("ON_2")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_2, LOW);
    lampState_2 = "Canal_2: ON\n";
    Serial.println("Canal_2: ON");  
    textMessage = "";   
  }


    if(textMessage.indexOf("ON_3")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_3, LOW);
    lampState_3 = "Canal_3: ON\n";
    Serial.println("Canal_3: ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_4")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_4, LOW);
    lampState_4 = "Canal_4: ON\n";
    Serial.println("Canal_4: ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_5")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_5, LOW);
    lampState_5 = "Canal_5: ON\n";
    Serial.println("Canal_5: ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_6")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_6, LOW);
    lampState_6 = "Canal_6: ON\n";
    Serial.println("Canal_6: ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_7")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_7, LOW);
    lampState_7 = "Canal_7: ON\n";
    Serial.println("Canal_7: ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_8")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_8, LOW);
    lampState_8 = "Canal_8: ON\n";
    Serial.println("Canal_8: ON");  
    textMessage = "";   
  }
if(textMessage.indexOf("ON_ALL")>=0){
  for(i=0;i<=8;i++)
  {
     digitalWrite(i, LOW);
    }
    message = "ALL: ON\n";
    Serial.println("ALL: ON");
    textMessage = "";    
    }
//

  
  if(textMessage.indexOf("OFF_1")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_1, HIGH);
    lampState_1 = "Canal_1: OFF\n";
    Serial.println("Canal_1: OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_2")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_2, HIGH);
    lampState_2 = "Canal_2: OFF\n";
    Serial.println("Canal_2: OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_3")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_3, HIGH);
    lampState_3 = "Canal_3: OFF\n";
    Serial.println("Canal_3: OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_4")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_4, HIGH);
    lampState_4 = "Canal_4: OFF\n";
    Serial.println("Canal_4: OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_5")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_5, HIGH);
    lampState_5 = "Canal_5: OFF\n";
    Serial.println("Canal_5: OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_6")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_6, HIGH);
    lampState_6 = "Canal_6: OFF\n";
    Serial.println("Canal_6: OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_1")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_7, HIGH);
    lampState_7 = "Canal_7: OFF\n";
    Serial.println("Canal_7: OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_8")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_8, HIGH);
    lampState_8 = "Canal_8: OFF\n";
    Serial.println("Canal_8: OFF");
    textMessage = ""; 
  }

  if(textMessage.indexOf("OFF_ALL")>=0){
  for(i=0;i<=8;i++)
  {
     digitalWrite(i, HIGH);
    }
    message = "ALL: OFF\n";
    Serial.println("ALL: OFF"); 
    textMessage = "";   
    }
  //
  
  if(textMessage.indexOf("STATE")>=0){
 //   message ="hello";
    message = lampState_1 + lampState_2 +lampState_3 + lampState_4 +lampState_5 + lampState_6 +lampState_7 + lampState_8;
    sendSMS(message);
    Serial.println("Lamp state resquest");
    textMessage = "";
  }
  if (digitalRead(11)==HIGH) 
   {
 digitalWrite(relay_4, LOW);
      
      lampState_4 = "Canal_4: OFF\n";
      message = lampState_1 + lampState_2 +lampState_3 + lampState_4 +lampState_5 + lampState_6 +lampState_7 + lampState_8;
      sendSMS(message);
    Serial.println("Lamp state resquest");
    textMessage = "";  
    }
}  

// Function that sends SMS
void sendSMS(String message){
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(500);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS

SIM900.println("AT+CMGS=\"XXXXXXXXXX\"\r");

  delay(500);
  // Send the SMS
  SIM900.println(message); 
  delay(500);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(500);
  SIM900.println();
  // Give module time to send SMS
  delay(600);  
}
