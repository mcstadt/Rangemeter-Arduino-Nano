#include <NewPing.h>

#include <Arduino.h>                   //Libraries
#include <TM1637Display.h>

#define TRIGGER_PIN 4  
#define ECHO_PIN 5                     //TRIG and ECHO Pins
#define MAX_DISTANCE 400 

int plus = 7;
int lesen = 8;                         //+10cm Gehäuse


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

float distance;

void setup() {
  
  pinMode(plus, OUTPUT);
  pinMode(lesen, INPUT);
  digitalWrite(plus, HIGH);
  pinMode(10, OUTPUT);                   //+5V
  digitalWrite(10, HIGH);
  
  
  
}

void loop() {

boolean lesenplus = digitalRead(lesen);
  
   distance = sonar.ping_cm();

  display.setBrightness(0x0f);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 }; 

  if (lesenplus) {
    
    display.showNumberDec(distance + 0.8 + 10);             //0.8cm = Tolleranz 10cm = Body
    
    }


    else {
      
      display.showNumberDec(distance + 0.8);                // Tolleranz
      
      }

  delay(50);                                                //Restart reading the cm´s
   

}
