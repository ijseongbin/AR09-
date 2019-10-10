/*
 Dimming 4 leds
 */

int ledR = 3;    // LED connected to digital pin 3
int ledG = 5;
int ledB = 6;
int ledY = 9;

int dimTime = 20;

void setup()  { 
  // nothing happens in setup 
} 

void loop()  { 
  dimLed(ledR);
  dimLed(ledY);
  dimLed(ledB);
  dimLed(ledG);
}
 void dimLed(int led){
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(led, fadeValue);   
    delay(dimTime);                            
  }
  for(int fadeValue = 255; fadeValue >= 0; fadeValue -=5){
    analogWrite(led, fadeValue);
    delay(dimTime);
  }  
}
