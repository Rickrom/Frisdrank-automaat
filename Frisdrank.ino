
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(49, 47, 45, 43, 41, 39);
#include <Servo.h> 
int LED = 12;
int BUTTON = 4;
int trigPin = 10;
int echoPin = 9;
long duration;
int distance;
          
Servo servo_test; 
               
int angle = 0;   

void setup() { 
 lcd.begin(16,2);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON,INPUT);
  servo_test.attach(22); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Welcom bij deze frisdrank automaat");
  lcd.print("Welkom");
  lcd.setCursor(3,1); 
  lcd.print("Maak Uw Keuze");
}
void loop() { 
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  for(angle = 0; angle < 360; angle += 1);
  if(distance < 6){
    if(digitalRead(BUTTON) == HIGH){
      servo_test.write(angle);                 
       delay(15);
       digitalWrite(LED, LOW);
       Serial.println("Geselcteerd item: Energy van de makro");
       lcd.clear();
       lcd.print("Red Bull Energy");
       lcd.setCursor(2,1); 
       lcd.print("Prijs= $4.20");
    }
    else{
      digitalWrite(LED, LOW);
      for(angle = 360; angle>=1; angle-=5);
      servo_test.write(angle);
      lcd.clear();
      lcd.print("Welkom");
      lcd.setCursor(3,1); 
      lcd.print("Maak Uw Keuze");
      
    }
  }
  else{
    if(digitalRead(BUTTON) == HIGH){
      digitalWrite(LED , HIGH);
      Serial.println("Deze Automaat is leeg");
      lcd.clear();
      lcd.print("Dit artikel");
      lcd.setCursor(2,1); 
      lcd.print("is Uitverkocht");
      delay(300);
      lcd.clear();
      
    }
   
    else{
    digitalWrite(LED, LOW);
    
    }
    for(angle = 60; angle>=1; angle-=5);
      servo_test.write(angle);
  }
  
}
