#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int duty=100, latch;


void setup() {
  // put your setup code here, to run once:
lcd.init();                      // initialize the lcd 
lcd.init();
  // Print a message to the LCD.
lcd.backlight();
Serial.begin(9600);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(A3, INPUT);
pinMode(A2, INPUT);
pinMode(A1, INPUT);
pinMode(A0, INPUT);
pinMode(2, INPUT);
digitalWrite(3,0);
digitalWrite(4,0);
lcd.setCursor(0,0);
lcd.print("LORA TRANSMIT");
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(A3)==0)
 {
  while(digitalRead(A3)==0){};
  for(int i=0; i<10; i++)
  {
  Serial.println("UP");
  lcd.setCursor(0,1);
  lcd.print("UP  ");
  delay(50);
  }
  duty=duty+5;
  if(duty>255) duty=0;
  lcd.setCursor(8, 1);
  lcd.print("DUTY:");
  lcd.setCursor(13, 1);
  lcd.print("   ");
  lcd.setCursor(13, 1);
  lcd.print(duty);
 }
 if(digitalRead(A2)==0)
 {
  while(digitalRead(A2)==0){};
  for(int i=0; i<10; i++)
  {
  Serial.println("DOWN");
  lcd.setCursor(0, 1);
  lcd.print("DOWN");
  delay(50);
  }
  duty=duty-5;
  if(duty<0) duty=255;
  lcd.setCursor(8, 1);
  lcd.print("DUTY:");
  lcd.setCursor(13, 1);
  lcd.print("   ");
  lcd.setCursor(13, 1);
  lcd.print(duty);
 }
 if(digitalRead(A1)==0)
 {
  while(digitalRead(A1)==0){};
  for(int i=0; i<10; i++)
  {
  Serial.println("STOP");
  lcd.setCursor(0, 1);
  lcd.print("STOP");
  delay(50);
  }
  duty=0;
  lcd.setCursor(13, 1);
  lcd.print("   ");
  lcd.setCursor(13, 1);
  lcd.print(duty);
 }
 if(digitalRead(A0)==0)
 {
  while(digitalRead(A0)==0){};
  for(int i=0; i<10; i++)
  {
  Serial.println("ROLL");
  lcd.setCursor(0, 1);
  lcd.print("ROLL");
  delay(50);
  }
  latch=~latch;
      if(latch)
      {
        digitalWrite(5,1);
        digitalWrite(4,0);
        lcd.setCursor(5, 1);
        lcd.print("+");
      }
      else
      {
        digitalWrite(4,1);
        digitalWrite(5,0);
        lcd.setCursor(5, 1);
        lcd.print("-");
      }
 }
}
