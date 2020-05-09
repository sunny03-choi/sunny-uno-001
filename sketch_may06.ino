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
 
  pinMode (pump,OUTPUT);
  
  
  pinMode (red, OUTPUT);
  pinMode (yellow, OUTPUT);
  pinMode (green, OUTPUT); 
}
 

void loop() {
  
  int soil = analogRead(A0);
  lcd.init();
  lcd.backlight();
  Serial.print("read soil : ");
  Serial.println(soil);
  lcd.begin(16,2);
  lcd.clear();
  lcd.home();
  lcd.print("read soil : ");
  lcd.println(soil);
  delay(700);
  if (soil >618) {
    Serial.println ("vary dry");
    Serial.println ("Pumping 1 second");
    lcd.noDisplay();
    delay(800);
    lcd.display();
    lcd.setCursor(0,1);
    lcd.println(" dry Pumping");
    delay(900);
    digitalWrite(pump,HIGH);
    delay(1000);
    digitalWrite(pump,LOW);
  }
  else {
    Serial.println(" vary wet");
    lcd. setCursor(0,1);
    lcd.print(" Wet");
    delay(100);
    digitalWrite(pump, LOW);
  }
 if (soil <400) {
 digitalWrite(green, HIGH);
 delay(500);
 digitalWrite(green,LOW);
 delay(600);
 digitalWrite(green,HIGH);
 delay(700);
 digitalWrite(green, HIGH);
 }
 else {
  digitalWrite(green,LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  
 }
 if 
  (soil >= 618)
  digitalWrite(red, HIGH);
   
  delay(200);
  digitalWrite(red,LOW);
 
  
  
 
 
  delay(300);
}
