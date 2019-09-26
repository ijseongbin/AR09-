/*
 예제 2.3
 컴퓨터로부터 시리얼 통신을 통하여 데이터 수신하기
*/

// LED 출력을 할 핀 번호 설정
const int ledPin = 13;  

// 점멸횟수 변수 설정
int blinkNumber = 0;
void setup() {
  // 9600bps로 시리얼 통신 설정  
  Serial.begin(9600);
  // 13번 핀을 출력으로 설정    
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(Serial.available()){       
   char val = Serial.read(); 
    if(isDigit(val)){
      blinkNumber = (val - '0');
    }
    Serial.print("입력한 수 :");
    Serial.println(blinkNumber);
    
       delay(2000);
 for(char i = 0; i<  blinkNumber; i++)
    {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }      
  }
  blinkNumber = 0;
}
