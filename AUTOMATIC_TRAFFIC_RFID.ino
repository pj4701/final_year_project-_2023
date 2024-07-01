#include<SoftwareSerial.h>
SoftwareSerial Serial1(6,7);
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>/
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET    4 // 4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


int RED1=8;
int GREEN1=9;   //Road1

int RED2=4;
int GREEN2=5;   //Road2

int RED3=2;
int GREEN3=3;  //Road3

int RED4=10;
int GREEN4=11;  //Road4

int IRROAD1=12;
int IRROAD2=15;
int IRROAD3=13;
int IRROAD4=14;

int BUZZER=16;

String card="54006D9F9731";
String card2="54006E492152";
String card3="54006EDDC92E";

String card11="54006D9F9731";
String card22="54006E492152";
String card33="54006EDDC92E";


void setup() {
  // put your setup code here, to run once:
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.print("TRAFFIC MANAGEMENT   SYSTEM FOR EMERGENCY VEHICLES");
//  display.setCursor(0, );
//  display.print("");
   display.display();
  delay(2000); // Pause for 2 seconds
  display.cp437(true);
  display.clearDisplay();
  pinMode(RED1,OUTPUT);
  pinMode(GREEN1,OUTPUT);

  pinMode(RED2,OUTPUT);
  pinMode(GREEN2,OUTPUT);

  pinMode(RED3,OUTPUT);
  pinMode(GREEN3,OUTPUT);

  pinMode(RED4,OUTPUT);
  pinMode(GREEN4,OUTPUT);

  pinMode(IRROAD1,INPUT);
  pinMode(IRROAD2,INPUT);
  pinMode(IRROAD3,INPUT);
  pinMode(IRROAD4,INPUT);
  
  pinMode(BUZZER,OUTPUT);
 Serial1.begin(9600);
  Serial.begin(9600);
 
//  lcd.begin(16,2);
//  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
 
//   if(Serial1.available()>0)
//  {
//    Serial.println("hello");
//    String card2;
//    card2=Serial1.readString();
//    Serial.println("card no is "+ String(card2));
//    delay(1000);
////    String card1;
////    String card2;  
//  }
  digitalWrite(RED1,HIGH);
  digitalWrite(RED2,HIGH);
  digitalWrite(RED3,HIGH);
  digitalWrite(RED4,HIGH);
  
//  ROAD1();
//  ROAD2();
//  ROAD3();
//  ROAD4();
//
//  ROAD1_IR();
//  ROAD2_IR();
//  ROAD3_IR();
//  ROAD4_IR();

  RFID_ROAD1();

//  RFID_ROAD2();

  

}

void ROAD1()
{
  display.fillRect(0, 18, 127, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 18);
  // Display static text
  display.print("ROAD1 MOVEMENT");
//  display.setTextSize(2);
//  display.print(Gas_val);
//delay(1000);

  digitalWrite(RED1,LOW);
  digitalWrite(RED2,HIGH);
  digitalWrite(RED3,HIGH);
  digitalWrite(RED4,HIGH);
  digitalWrite(GREEN1,HIGH);
  digitalWrite(GREEN2,LOW);
  digitalWrite(GREEN3,LOW);
  digitalWrite(GREEN4,LOW);
  Serial.println("ROAD1 MOVEMENT");
 // ROAD1_IR();
  display.display();
  delay(2000); // Pause for 2 seconds
  display.cp437(true);
  display.clearDisplay();
}
void ROAD2()
{
   display.fillRect(0, 18, 127, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 18);
  // Display static text
  display.print("ROAD2 MOVEMENT");
  digitalWrite(RED1,HIGH);
  digitalWrite(RED2,LOW);
  digitalWrite(RED3,HIGH);
  digitalWrite(RED4,HIGH);
  digitalWrite(GREEN1,LOW);
  digitalWrite(GREEN2,HIGH);
  digitalWrite(GREEN3,LOW);
  digitalWrite(GREEN4,LOW);
  Serial.println("ROAD2 MOVEMENT");
 // ROAD2_IR();
  display.display();
  delay(2000); // Pause for 2 seconds
  display.cp437(true);
  display.clearDisplay();
}
void ROAD3()
{
  display.fillRect(0, 18, 127, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 18);
  // Display static text
  display.print("ROAD3 MOVEMENT");
  digitalWrite(RED1,HIGH);
  digitalWrite(RED2,HIGH);
  digitalWrite(RED3,LOW);
  digitalWrite(RED4,HIGH);
  digitalWrite(GREEN1,LOW);
  digitalWrite(GREEN2,LOW);
  digitalWrite(GREEN3,HIGH);
  digitalWrite(GREEN4,LOW);
  Serial.println("ROAD3 MOVEMENT");
 // ROAD3_IR();
  display.display();
  delay(2000); // Pause for 2 seconds
  display.cp437(true);
  display.clearDisplay();
}
void ROAD4()
{
   display.fillRect(0, 18, 127, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 18);
  // Display static text
  display.print("ROAD4 MOVEMENT");
  digitalWrite(RED1,HIGH);
  digitalWrite(RED2,HIGH);
  digitalWrite(RED3,HIGH);
  digitalWrite(RED4,LOW);
  digitalWrite(GREEN1,LOW);
  digitalWrite(GREEN2,LOW);
  digitalWrite(GREEN3,LOW);
  digitalWrite(GREEN4,HIGH);
  Serial.println("ROAD4 MOVEMENT");
  //ROAD4_IR();
  display.display();
  delay(2000); // Pause for 2 seconds
  display.cp437(true);
  display.clearDisplay();
}

void ROAD1_IR()
{
  int ir1val=digitalRead(12);
  if(ir1val==0)
  {
   Serial.println("VEHICLE DENSITY IS HIGHER IN ROAD1");
   
  display.fillRect(0, 18, 127, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 18);
  // Display static text
  display.print("VEHICLE DENSITY IS");
   display.setCursor(64, 18);
   display.print("HIGHER IN ROAD1");
  display.display();
  delay(1000); // Pause for 2 seconds
  display.cp437(true);
   display.clearDisplay();
     ROAD1();
     delay(3000);
  }
}
void ROAD2_IR()
{
  int ir2val=digitalRead(15);
  if(ir2val==0)
  {
  Serial.println("VEHICLE DENSITY IS HIGHER IN ROAD2");
  display.fillRect(0, 18, 127, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 18);
  // Display static text
  display.print("VEHICLE DENSITY IS");
   display.setCursor(64, 18);
   display.print("HIGHER IN ROAD2");
 
   display.display();
  delay(1000); // Pause for 2 seconds
  display.cp437(true);
  display.clearDisplay();
   ROAD2();
   delay(3000);
  }
}
void ROAD3_IR()
{
  int ir3val=digitalRead(13);
  if(ir3val==0)
  {
  Serial.println("VEHICLE DENSITY IS HIGHER IN ROAD3");
  display.fillRect(0, 18, 127, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 18);
  // Display static text
  display.print("VEHICLE DENSITY IS");
  display.setCursor(64, 18);
  display.print("HIGHER IN ROAD3");
  //ROAD3();
   display.display();
  delay(1000); // Pause for 2 seconds
  display.cp437(true);
  display.clearDisplay();
   ROAD3();
   delay(3000);
  }
}
void ROAD4_IR()
{
  int ir4val=digitalRead(14);
  if(ir4val==0)
  {
  Serial.println("VEHICLE DENSITY IS HIGHER IN ROAD4");
  display.fillRect(0, 18, 127, 15, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 18);
  // Display static text
  display.print("VEHICLE DENSITY IS");
   display.setCursor(64, 18);
   display.print("HIGHER IN ROAD4");
  //ROAD4();
  display.display();
  delay(1000); // Pause for 2 seconds
  display.cp437(true);
  display.clearDisplay();
   ROAD4();
   delay(3000);
  }
}

void RFID_ROAD1()
{
  Serial.begin(9600);
  Serial.println("Road1111");
  while(1)
  {
    if(Serial.available()>0)
    {
      String card4;
      
      String RFID1=Serial.readString();
      Serial.println("Card4: ");
      Serial.print(card4);
  
      if(card==card11)
      {
        Serial.println("EMERGENCY VEHICLE PASSING IN ROAD 1");

        digitalWrite(BUZZER,HIGH);
        delay(1000);
        digitalWrite(BUZZER,LOW);
        
        display.fillRect(0, 18, 127, 15, BLACK);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        // Display static text
        display.print("EMERGENCY VEHICLE PASSING IN ROAD1 ");
        display.print("");
        
      
       display.display();
        delay(1000); // Pause for 2 seconds
        display.cp437(true);
        display.clearDisplay();
          ROAD1();
          delay(4000);
      }
      else if(card2==card22)
      {
         Serial.println("EMERGENCY VEHICLE PASSING IN ROAD 1");

        digitalWrite(BUZZER,HIGH);
        delay(1000);
        digitalWrite(BUZZER,LOW);
        
        display.fillRect(0, 18, 127, 15, BLACK);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        // Display static text
        display.print("EMERGENCY VEHICLE PASSING IN ROAD1 ");
        display.print("");
        
      
       display.display();
        delay(1000); // Pause for 2 seconds
        display.cp437(true);
        display.clearDisplay();
          ROAD1();
          delay(4000);
      }
       else if(card3==card33)
      {
          Serial.println("EMERGENCY VEHICLE PASSING IN ROAD 1");

        digitalWrite(BUZZER,HIGH);
        delay(1000);
        digitalWrite(BUZZER,LOW);
        
        display.fillRect(0, 18, 127, 15, BLACK);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        // Display static text
        display.print("EMERGENCY VEHICLE PASSING IN ROAD1 ");
        display.print("");
        
      
       display.display();
        delay(1000); // Pause for 2 seconds
        display.cp437(true);
        display.clearDisplay();
          ROAD1();
          delay(4000);
      }
    }
    RFID_ROAD2();
    ROAD1();
    ROAD2();
    ROAD3();
    ROAD4();

  ROAD1_IR();
  ROAD2_IR();
  ROAD3_IR();
  ROAD4_IR();
  }
}

void RFID_ROAD2()
{
   Serial1.begin(9600);
  if(Serial1.available()>0)
  {
    
    String card1;
    String RFID2=Serial1.readString();
    Serial.println("Card2: ");
    Serial.print(card1);
   
    if(card==card11)
    {
      
       Serial.println("EMERGENCY VEHICLE PASSING IN ROAD 2");

        digitalWrite(BUZZER,HIGH);
        delay(1000);
        digitalWrite(BUZZER,LOW);
        
        display.fillRect(0, 18, 127, 15, BLACK);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        // Display static text
        display.print("EMERGENCY VEHICLE PASSING IN ROAD2 ");
        display.print("");
        
      
       display.display();
        delay(1000); // Pause for 2 seconds
        display.cp437(true);
        display.clearDisplay();
          ROAD4();//change  
          delay(4000);
    }
   else if(card2==card22)
    {
       Serial.println("EMERGENCY VEHICLE PASSING IN ROAD 2");

        digitalWrite(BUZZER,HIGH);
        delay(1000);
        digitalWrite(BUZZER,LOW);
        
        display.fillRect(0, 18, 127, 15, BLACK);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        // Display static text
        display.print("EMERGENCY VEHICLE PASSING IN ROAD2 ");
        display.print("");
        
      
       display.display();
        delay(1000); // Pause for 2 seconds
        display.cp437(true);
        display.clearDisplay();
          ROAD4();//change
          delay(4000);
    }
    if(card3==card33)
   
   { 
      Serial.println("EMERGENCY VEHICLE PASSING IN ROAD 2");

        digitalWrite(BUZZER,HIGH);
        delay(1000);
        digitalWrite(BUZZER,LOW);
        
        display.fillRect(0, 18, 127, 15, BLACK);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        // Display static text
        display.print("EMERGENCY VEHICLE PASSING IN ROAD2 ");
        display.print("");
        
      
       display.display();
        delay(1000); // Pause for 2 seconds
        display.cp437(true);
        display.clearDisplay();
          ROAD4();//change 
          delay(4000);
    }
  }
  
}
