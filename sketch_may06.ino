

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
  
  int soil = analogRead(A0);     //토양 값을 A0 출력
  lcd.init();                    //lcd 시작
  lcd.backlight();               //lcd backlight 켬   
  Serial.print("read soil : ");
  Serial.println(soil);
  delay(900);
  lcd.begin(16,2);               //lcd 시작   
  lcd.clear();                  //lcd 초기화
  lcd.home();                   //lcd (0.0)에 맞춤   
  lcd.print("read soil : ");    //lcd "read soil"이라고 씀  
  lcd.println(soil);           //lcd soil 값 출력
  
  
 
 
  if (soil <400) {
   
 Serial.println("enough water");
 lcd.setCursor(0,1);
 lcd.println("enough");
 digitalWrite(green, HIGH);
 delay(4000);
 digitalWrite(green,LOW);
 }
   if (soil >618) {
    Serial.println ("vary dry");
    Serial.println ("Pumping 1 second");
    lcd.noDisplay();
    delay(1100);
    lcd.display();
    lcd.setCursor(0,1);
    lcd.println(" dry,Pumping");
    delay(100);
    
   
  digitalWrite(red,HIGH);
 
    digitalWrite(pump,HIGH);
    delay(3000);
    digitalWrite(pump,LOW);
   digitalWrite(red,LOW);
  }
  if (401< soil <617) {
    Serial.println(" vary wet");   
    digitalWrite(yellow,HIGH);
    delay(300);
    digitalWrite(yellow,LOW);
  }
delay(100);
}
