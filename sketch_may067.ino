
#define A0Pin 0
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2);

int soil = A0;
int red = 3;
int yellow = 10;
int green = 6;
int pump =8; 


 

void setup() {
  
 Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  pinMode (pump,OUTPUT);
  
  
  pinMode (red, OUTPUT);
  pinMode (yellow, OUTPUT);
  pinMode (green, OUTPUT); 
}
 

void loop() {
  
  int soil = analogRead(A0);
  
  Serial.print("read soil : ");
  Serial.println(soil);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dry-----------Wet");
  lcd.print("read soil : ");
  lcd.println(soil);
  if (soil >430) {
    Serial.println ("vary dry");
    Serial.println ("Pumping 1 second");
    lcd.println(" dry Pumping");
    digitalWrite(pump,HIGH);
    delay(1000);
  }
  else {
    Serial.println(" vary wet");
    lcd.println(" Wet");
    digitalWrite(pump, LOW);
  }
 if (soil <350)
 digitalWrite(green, HIGH);
 else {
  digitalWrite(green,LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
 }
 if 
  (soil >= 425)
  digitalWrite(red, HIGH);
   
  delay(500);
  digitalWrite(red,LOW);
 
  
  
 
 
  delay(500);
}
