//꼭 선이 잘 끼워저 있는지 확인하고 작동시켜주세요!!!
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
 
  pinMode (pump,OUTPUT);       //펌프 출력      
  pinMode (red, OUTPUT);       //led 빨간색 출력
  pinMode (yellow, OUTPUT);   //led 노란색 출력
  pinMode (green, OUTPUT);    //led 초록색 출력
}

void loop() {
  
  int soil = analogRead(A0);     
  lcd.init();                    
  lcd.backlight();               //lcd backlight 켬   
  Serial.print("read soil : ");
  Serial.println(soil);
  delay(700);
  lcd.begin(16,2);               //lcd 시작   
  lcd.clear();                  //lcd 초기화
  lcd.home();                   //lcd (0.0)에 맞춤   
  lcd.print("read soil : ");    //lcd "read soil"이라고 씀  
  lcd.println(soil);           //lcd soil 값 출력
  
  
 
 
  if (soil <430) {
   
 Serial.println("enough water");          
 lcd.setCursor(0,1);                  //lcd 초점 (0,1)에 맞추기
 lcd.println("enough");              //lcd 에 "enough"라고 쓰기
 digitalWrite(green, HIGH);           //led 초록색 켜기
 delay(3000);                        //3초 동안 켜기
 digitalWrite(green,LOW);            //led 초록색 끄기  
 }

else  if (430< soil && soil <540) {      //흙의 수분이 430 초과 540 미만일 때
  Serial.println(" not enough");        
 digitalWrite(yellow,HIGH);             //노란색 led 켜짐 
  delay(600);                           //0.6초 동안 켜기     
  digitalWrite(yellow,LOW);//노란색 led 켜기
  lcd.noDisplay();
  delay(3000);
  lcd.display();
 
  lcd.setCursor(0,1);
 lcd.println("Usual");
 }
 
 
   else {
    Serial.println ("vary dry");          
    Serial.println ("Pumping 1 second");
    lcd.noDisplay();                    //lcd에 보여주지 않기
    delay(1900);                        //1.9초 동안 쉬기
    lcd.display();                      //lcd 보여주기
   
    lcd.setCursor(0,1);                 //(0,1)에 초점 맞추기
    lcd.println(" dry,Pumping");       //lcd에 dry,pumping 이라고 쓰기
    digitalWrite(red,HIGH);              // 빨간색 led 켜기
 
    digitalWrite(pump,HIGH);            //펌프 켜기
    delay(2000);                        //2초 동안 켜기    
    digitalWrite(pump,LOW);            //펌프 끄기
   digitalWrite(red,LOW);              //빨간색 led 끄기
   
  }
 delay(800);
}
