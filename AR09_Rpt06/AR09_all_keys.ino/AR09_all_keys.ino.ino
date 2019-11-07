#include <Key.h>
#include <Keypad.h>
const byte numRows = 4;    // 행(rows) 개수
const byte numCols = 4;    // 열(columns) 개수
char keys[numRows][numCols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte rowPins[numRows] = {6,7,8,9};   // R1, R2, R3, R4 단자가 연결된 아두이노 핀 번호
byte colPins[numCols] = {5,4,3,2};   // C1, C2, C3, C4 단자가 연결된 아두이노 핀 번호
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, numRows, numCols );
 
void setup() {
  for(int i = 0; i < numRows; i++){
    pinMode(rowPins[i], INPUT_PULLUP);
  }
  for(int i = 0; i < numCols; i++){
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }
  Serial.begin(9600);
}
   
void loop() {
  char key = keypad.getKey(); // check key
  if (key) {
    Serial.print("You push ");
    Serial.print(key);
    Serial.println(" Key");
  };
}
char keypadRead(){
  char key = 0;
  for(int i = 0; i < numRows; i++){
    digitalWrite(colPins[i], LOW);
    for(int j = 0; j < numCols; j++){
      if(digitalRead(rowPins[i]) == LOW){
        delay(10);
        while(digitalRead(rowPins[j])==LOW);
        key =keys[j][i];
      };
    }
    digitalWrite(colPins[i],HIGH);
  }
  return key;
}
