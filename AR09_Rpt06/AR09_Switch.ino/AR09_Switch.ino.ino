const int ledPin = 13;
const int inputPin = 2;
int count = 0;
String ledS[] ={"LOW","HIGH"};
void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop(){
  int swInput = digitalRead(inputPin);
  int ledOutput = digitalRead(ledPin);
  if(swInput ==LOW){
    delay(400);
    if(ledOutput){
      Serial.print("LED: ");
      Serial.print(ledS[ledOutput]);
      delay(100);
      digitalWrite(ledPin,LOW);
    }
    else{
      Serial.print("LED: ");
      Serial.print(ledS[ledOutput]);
      delay(100);
      digitalWrite(ledPin, HIGH);
    }
    ++count;
    Serial.print(", count: ");
    Serial.println(count);
  }
}
