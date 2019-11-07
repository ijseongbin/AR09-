const int ledPin = 13;
const int inputPin = 2;
int count = 0;
void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop(){
  int swInput = digitalRead(inputPin);
  int ledOutput = digitalRead(ledPin);
  if(swInput ==LOW){
    if(ledOutput) digitalWrite(ledPin,LOW);
    else digitalWrite(ledPin, HIGH);
    ++count;
  Serial.println(count);
  };
}
