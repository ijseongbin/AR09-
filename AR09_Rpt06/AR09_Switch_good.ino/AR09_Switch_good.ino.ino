const int ledPin = 13;   
const int inputPin = 2;
const int swCountTime = 10;
int count = 0;
int swCountTimer = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
  Serial.begin(9600);  
}

void loop(){
  int ledOutput = digitalRead(ledPin);
  if (swCheck(inputPin)){
    if (ledOutput)  digitalWrite(ledPin, LOW);
    else   digitalWrite(ledPin, HIGH);
    ++count;
    Serial.println(count);
  };
}

boolean swCheck(int pin){
  boolean swInput = digitalRead(pin);
  boolean state;
 if(swInput == LOW){
    if(swCountTimer >= swCountTime){
      if(swCountTimer ==  swCountTime)  state = HIGH;
      else state = LOW; 
	  swCountTimer = swCountTime + 1;
     }
     else{
      ++swCountTimer;  
     }
  }
  else{
    state = LOW;
    swCountTimer = 0;
  }
  return state;
}
