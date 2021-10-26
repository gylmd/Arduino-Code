#include <SoftwareSerial.h>
// Configure software serial port
SoftwareSerial SIM900(12,13);

// Variable to store text message
String textMessage;
String message;
// Create a variable to store Lamp state
String lampState_0 = "A1->OFF\n";
String lampState_1 = "A2->OFF\n";
String lampState_2 = "A3->OFF\n";
String lampState_3 = "A4->OFF\n";
String lampState_4 = "A5->OFF\n";
String lampState_5 = "A6->OFF\n";
String lampState_6 = "A7->OFF\n";
String lampState_7 = "A8->OFF\n";

String lampState_9 = "B7->OFF\n";
String lampState_10 = "B8->OFF\n";
String lampState_A0 = "B1->OFF\n";
String lampState_A1 = "B2->OFF\n";
String lampState_A2 = "B3->OFF\n";
String lampState_A3 = "B4->OFF\n";
String lampState_A4 = "B5->OFF\n";
String lampState_A5 = "B6->OFF\n";

String lampState_8 = "Z->OFF\n";

// Relay connected to pin 12
const int relay_A1 = 0;
const int relay_A2 = 1;
const int relay_A3 = 2;
const int relay_A4 = 3;
const int relay_A5 = 4;
const int relay_A6 = 5;
const int relay_A7 = 6;
const int relay_A8 = 7;


const int relay_B1 = A0;
const int relay_B2 = A1;
const int relay_B3 = A2;
const int relay_B4 = A3;
const int relay_B5 = A4;
const int relay_B6 = A5;
const int relay_B7 = 9;
const int relay_B8 = 10;

const int relay_8 = 8;

int i;
void setup() {
  // Automatically turn on the shield
  //digitalWrite(9, HIGH);
  delay(1000);
 // digitalWrite(9, LOW);
  delay(2000);
  
  // Set relay as OUTPUT
  pinMode(relay_A1, OUTPUT);
  pinMode(relay_A2, OUTPUT);
  pinMode(relay_A3, OUTPUT);
  pinMode(relay_A4, OUTPUT);
  pinMode(relay_A5, OUTPUT);
  pinMode(relay_A6, OUTPUT);
  pinMode(relay_A7, OUTPUT);
  pinMode(relay_A8, OUTPUT);

  pinMode(relay_B1, OUTPUT);
  pinMode(relay_B2, OUTPUT);
  pinMode(relay_B3, OUTPUT);
  pinMode(relay_B4, OUTPUT);
  pinMode(relay_B5, OUTPUT);
  pinMode(relay_B6, OUTPUT);
  pinMode(relay_B7, OUTPUT);
  pinMode(relay_B8, OUTPUT);

  pinMode(relay_8, OUTPUT);
    
  pinMode(11,INPUT);

  
  // By default the relay is off
  digitalWrite(relay_A1, LOW);
  digitalWrite(relay_A2, LOW);
  digitalWrite(relay_A3, LOW);
  digitalWrite(relay_A4, LOW);
  digitalWrite(relay_A5, LOW);
  digitalWrite(relay_A6, LOW);
  digitalWrite(relay_A7, LOW);
  digitalWrite(relay_A8, LOW);


  digitalWrite(relay_B1, LOW);
  digitalWrite(relay_B2, LOW);
  digitalWrite(relay_B3, LOW);
  digitalWrite(relay_B4, LOW);
  digitalWrite(relay_B5, LOW);
  digitalWrite(relay_B6, LOW);
  digitalWrite(relay_B7, LOW);
  digitalWrite(relay_B8, LOW);

  digitalWrite(relay_8, LOW);
  
  // Initializing serial commmunication
 
  SIM900.begin(19200);
 //Seria//l.begin(19200);
  // Give time to your GSM shield log on to network
  delay(5000);
 //Seria//l.print("SIM900 ready...");

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
    //Seria//l.print(textMessage);    
    delay(10);
  } 
/*  --------------------     ON    -------------- */

   if(textMessage.indexOf("ON_Z")>=0){
    // Turn ON relay and save current state
    digitalWrite(relay_8, HIGH);
    lampState_8 = "Z->ON\n";
  //Seria//l.println("Z->ON");
    textMessage = ""; 
  }

    if(textMessage.indexOf("ON_A1")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_A1, HIGH);
    lampState_1 = "A1->ON\n";
    //Seria//l.println("A1->ON");  
    textMessage = "";   
  }
  
  if(textMessage.indexOf("ON_A2")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_A2, HIGH);
    lampState_2 = "A2->ON\n";
  //Seria//l.println("A2->ON");  
    textMessage = "";   
  }


    if(textMessage.indexOf("ON_A3")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_A3, HIGH);
    lampState_3 = "A3->ON\n";
  //Seria//l.println("A3->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_A4")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_A4, HIGH);
    lampState_4 = "A4->ON\n";
  //Seria//l.println("A4->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_A5")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_A5, HIGH);
    lampState_5 = "A5->ON\n";
  //Seria//l.println("A5->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_A6")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_A6, HIGH);
    lampState_6 = "A6->ON\n";
  //Seria//l.println("A6->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_A7")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_A7, HIGH);
    lampState_7 = "A7->ON\n";
  //Seria//l.println("A7->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_A8")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_A8, HIGH);
    lampState_8 = "A8->ON\n";
  //Seria//l.println("A8->ON");  
    textMessage = "";   
  }


    if(textMessage.indexOf("ON_B1")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_B1, HIGH);
    lampState_1 = "B1->ON\n";
    //Seria//l.println("B1->ON");  
    textMessage = "";   
  }
  
  if(textMessage.indexOf("ON_B2")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_B2, HIGH);
    lampState_2 = "B2->ON\n";
  //Seria//l.println("B2->ON");  
    textMessage = "";   
  }


    if(textMessage.indexOf("ON_B3")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_B3, HIGH);
    lampState_3 = "B3->ON\n";
  //Seria//l.println("B3->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_B4")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_B4, HIGH);
    lampState_4 = "B4->ON\n";
  //Seria//l.println("B4->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_B5")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_B5, HIGH);
    lampState_5 = "B5->ON\n";
  //Seria//l.println("B5->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_B6")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_B6, HIGH);
    lampState_6 = "B6->ON\n";
  //Seria//l.println("B6->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_B7")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_B7, HIGH);
    lampState_7 = "B7->ON\n";
  //Seria//l.println("B7->ON");  
    textMessage = "";   
  }

    if(textMessage.indexOf("ON_B8")>=0){
    // Turn on relay and save current state
    digitalWrite(relay_B8, HIGH);
    lampState_8 = "B8->ON\n";
  //Seria//l.println("B8->ON");  
    textMessage = "";   
  }
  
if(textMessage.indexOf("ON_ALL")>=0){
digitalWrite(relay_A1, HIGH);
  digitalWrite(relay_A2, HIGH);
  digitalWrite(relay_A3, HIGH);
  digitalWrite(relay_A4, HIGH);
  digitalWrite(relay_A5, HIGH);
  digitalWrite(relay_A6, HIGH);
  digitalWrite(relay_A7, HIGH);
  digitalWrite(relay_A8, HIGH);


  digitalWrite(relay_B1, HIGH);
  digitalWrite(relay_B2, HIGH);
  digitalWrite(relay_B3, HIGH);
  digitalWrite(relay_B4, HIGH);
  digitalWrite(relay_B5, HIGH);
  digitalWrite(relay_B6, HIGH);
  digitalWrite(relay_B7, HIGH);
  digitalWrite(relay_B8, HIGH);

  digitalWrite(relay_8, HIGH);

  
 lampState_0 = "A1->ON\n";
 lampState_1 = "A2->ON\n";
 lampState_2 = "A3->ON\n";
 lampState_3 = "A4->ON\n";
 lampState_4 = "A5->ON\n";
 lampState_5 = "A6->ON\n";
 lampState_6 = "A7->ON\n";
 lampState_7 = "A8->ON\n";

 lampState_9 = "A7->ON\n";
 lampState_10 = "A8->ON\n";
 lampState_A0 = "B1->ON\n";
 lampState_A1 = "B2->ON\n";
 lampState_A2 = "B3->ON\n";
 lampState_A3 = "B4->ON\n";
 lampState_A4 = "B5->ON\n";
 lampState_A5 = "B6->ON\n";

 lampState_8 = "Z->ON\n";
  
  //Seria//l.println("ALL: ON");
    textMessage = "";    
    }

/*  --------------------     OF    -------------- */
  if(textMessage.indexOf("OFF_A1")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B1, LOW);
    lampState_1 = "A1->OFF\n";
  //Seria//l.println("A1->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_A2")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B2, LOW);
    lampState_2 = "A2->OFF\n";
  //Seria//l.println("A2->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_A3")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B3, LOW);
    lampState_3 = "A3->OFF\n";
  //Seria//l.println("A3->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_A4")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B4, LOW);
    lampState_4 = "A4->OFF\n";
  //Seria//l.println("A4->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_A5")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_A5, LOW);
    lampState_5 = "A5->OFF\n";
  //Seria//l.println("A5->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_A6")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_A6, LOW);
    lampState_6 = "A6->OFF\n";
  //Seria//l.println("A6->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_A7")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_A7, LOW);
    lampState_7 = "A7->OFF\n";
  //Seria//l.println("A7->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_A8")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B8, LOW);
    lampState_8 = "A8->OFF\n";
  //Seria//l.println("A8->OFF");
    textMessage = ""; 
  }

    if(textMessage.indexOf("OFF_B1")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B1, LOW);
    lampState_1 = "B1->OFF\n";
  //Seria//l.println("B1->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_B2")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B2, LOW);
    lampState_2 = "B2->OFF\n";
  //Seria//l.println("B2->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_B3")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B3, LOW);
    lampState_3 = "B3->OFF\n";
  //Seria//l.println("B3->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_B4")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B4, LOW);
    lampState_4 = "B4->OFF\n";
  //Seria//l.println("B4->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_B5")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B5, LOW);
    lampState_5 = "B5->OFF\n";
  //Seria//l.println("B5->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_B6")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B6, LOW);
    lampState_6 = "B6->OFF\n";
  //Seria//l.println("B6->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_B1")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B7, LOW);
    lampState_7 = "B7->OFF\n";
  //Seria//l.println("B7->OFF");
    textMessage = ""; 
  }
    if(textMessage.indexOf("OFF_B8")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_B8, LOW);
    lampState_8 = "B8->OFF\n";
  //Seria//l.println("B8->OFF");
    textMessage = ""; 
  }
   if(textMessage.indexOf("OFF_Z")>=0){
    // Turn off relay and save current state
    digitalWrite(relay_8, LOW);
    lampState_8 = "Z->OFF\n";
  //Seria//l.println("Z->OFF");
    textMessage = ""; 
  }
  

  if(textMessage.indexOf("OFF_ALL")>=0){
  digitalWrite(relay_A1, LOW);
  digitalWrite(relay_A2, LOW);
  digitalWrite(relay_A3, LOW);
  digitalWrite(relay_A4, LOW);
  digitalWrite(relay_A5, LOW);
  digitalWrite(relay_A6, LOW);
  digitalWrite(relay_A7, LOW);
  digitalWrite(relay_A8, LOW);


  digitalWrite(relay_B1, LOW);
  digitalWrite(relay_B2, LOW);
  digitalWrite(relay_B3, LOW);
  digitalWrite(relay_B4, LOW);
  digitalWrite(relay_B5, LOW);
  digitalWrite(relay_B6, LOW);
  digitalWrite(relay_B7, LOW);
  digitalWrite(relay_B8, LOW);

  digitalWrite(relay_8, LOW);

 lampState_0 = "A1->OFF\n";
 lampState_1 = "A2->OFF\n";
 lampState_2 = "A3->OFF\n";
 lampState_3 = "A4->OFF\n";
 lampState_4 = "A5->OFF\n";
 lampState_5 = "A6->OFF\n";
 lampState_6 = "A7->OFF\n";
 lampState_7 = "A8->OFF\n";

 lampState_9 = "A7->OFF\n";
 lampState_10 = "A8->OFF\n";
 lampState_A0 = "B1->OFF\n";
 lampState_A1 = "B2->OFF\n";
 lampState_A2 = "B3->OFF\n";
 lampState_A3 = "B4->OFF\n";
 lampState_A4 = "B5->OFF\n";
 lampState_A5 = "B6->OFF\n";

 lampState_8 = "Z->OFF\n";
 
  //Seria//l.println("ALL: OFF"); 
    textMessage = "";   
    }
  //
  
  if(textMessage.indexOf("STATE")>=0){

  message =lampState_0 +lampState_1 + lampState_2 +lampState_3 + lampState_4 +lampState_5 + lampState_6 +lampState_7 +lampState_A0+lampState_A1+lampState_A2+lampState_A3+lampState_A4+lampState_A5+lampState_9+lampState_10+lampState_8;
    sendSMS(message);
  //Seria//l.println("Lamp state resquest");
    textMessage = "";
  }

  if (digitalRead(11)== HIGH) {   
 
 
  digitalWrite(relay_A1, HIGH);
  digitalWrite(relay_A2, HIGH);
  digitalWrite(relay_A3, HIGH);
  digitalWrite(relay_A4, HIGH);
  digitalWrite(relay_A5, HIGH);
  digitalWrite(relay_A6, HIGH);
  digitalWrite(relay_A7, HIGH);
  digitalWrite(relay_A8, HIGH);


  digitalWrite(relay_B1, HIGH);
  digitalWrite(relay_B2, HIGH);
  digitalWrite(relay_B3, HIGH);
  digitalWrite(relay_B4, HIGH);
  digitalWrite(relay_B5, HIGH);
  digitalWrite(relay_B6, HIGH);
  digitalWrite(relay_B7, HIGH);
  digitalWrite(relay_B8, HIGH);

  digitalWrite(relay_8, HIGH);

 lampState_0 = "A1->ON  ";
 lampState_1 = "A2->ON\n";
 lampState_2 = "A3->ON  ";
 lampState_3 = "A4->ON\n";
 lampState_4 = "A5->ON  ";
 lampState_5 = "A6->ON\n";
 lampState_6 = "A7->ON  ";
 lampState_7 = "A8->ON\n";

 lampState_9 = "B7->ON  ";
 lampState_10 = "B8->ON\n";
 lampState_A0 = "B1->ON  ";
 lampState_A1 = "B2->ON\n";
 lampState_A2 = "B3->ON  ";
 lampState_A3 = "B4->ON\n";
 lampState_A4 = "B5->ON  ";
 lampState_A5 = "B6->ON\n";

 lampState_8 = "Z->ON";
 
  ////Seria//l.println("ALL: ON");
     delay(50);
    message =lampState_0 +lampState_1 + lampState_2 +lampState_3 + lampState_4 +lampState_5 + lampState_6 +lampState_7 +lampState_A0+lampState_A1+lampState_A2+lampState_A3+lampState_A4+lampState_A5+lampState_9+lampState_10+lampState_8;
 //delay(100);
  sendSMS(message);
  delay(5000);
  //Seria//l.println("Lamp state resquest");
   digitalWrite(relay_A1, LOW);
  digitalWrite(relay_A2, LOW);
  digitalWrite(relay_A3, LOW);
  digitalWrite(relay_A4, LOW);
  digitalWrite(relay_A5, LOW);
  digitalWrite(relay_A6, LOW);
  digitalWrite(relay_A7, LOW);
  digitalWrite(relay_A8, LOW);


  digitalWrite(relay_B1, LOW);
  digitalWrite(relay_B2, LOW);
  digitalWrite(relay_B3, LOW);
  digitalWrite(relay_B4, LOW);
  digitalWrite(relay_B5, LOW);
  digitalWrite(relay_B6, LOW);
  digitalWrite(relay_B7, LOW);
  digitalWrite(relay_B8, LOW);

  digitalWrite(relay_8, LOW);

 lampState_0 = "A1->OFF\n";
 lampState_1 = "A2->OFF\n";
 lampState_2 = "A3->OFF\n";
 lampState_3 = "A4->OFF\n";
 lampState_4 = "A5->OFF\n";
 lampState_5 = "A6->OFF\n";
 lampState_6 = "A7->OFF\n";
 lampState_7 = "A8->OFF\n";

 lampState_9 = "A7->OFF\n";
 lampState_10 = "A8->OFF\n";
 lampState_A0 = "B1->OFF\n";
 lampState_A1 = "B2->OFF\n";
 lampState_A2 = "B3->OFF\n";
 lampState_A3 = "B4->OFF\n";
 lampState_A4 = "B5->OFF\n";
 lampState_A5 = "B6->OFF\n";

 lampState_8 = "Z->OFF\n";

  delay(50);
  message =lampState_0 +lampState_1 + lampState_2 +lampState_3 + lampState_4 +lampState_5 + lampState_6 +lampState_7 +lampState_A0+lampState_A1+lampState_A2+lampState_A3+lampState_A4+lampState_A5+lampState_9+lampState_10+lampState_8;
 //delay(100);
  sendSMS(message);
  //Seria//l.println("Lamp state resquest");
    textMessage = ""; 
delay(5000);  
  digitalWrite(relay_A3, HIGH);
  digitalWrite(relay_A4, HIGH);
  digitalWrite(relay_A5, HIGH);  
    }    }  

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
//Seria//l.println(message);
  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(500);
  SIM900.println();
  // Give module time to send SMS
  delay(600);  
}
