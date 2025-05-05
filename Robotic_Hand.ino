#include <Servo.h>

Servo servo1;  
Servo servo2;  
Servo servo3;  
Servo servo4;  

const int joy1X = A0;  
const int joy1Y = A1;  
const int joy2X = A2;  
const int joy2Y = A3;  
const int joy1SW = 2; 
const int joy2SW = 3; 

const int servoPin1 = 9;   
const int servoPin2 = 10;  
const int servoPin3 = 11;  
const int servoPin4 = 12;  

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);

  pinMode(joy1SW, INPUT_PULLUP);
  pinMode(joy2SW, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {

  int joy1SWState = digitalRead(joy1SW);
  int joy2SWState = digitalRead(joy2SW);
  
  if (joy1SWState == LOW || joy2SWState == LOW) {
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    Serial.println("Servos reset to 90 degrees");
    delay(200); 
  } else {
    int joy1XVal = analogRead(joy1X);
    int joy1YVal = analogRead(joy1Y);
    int joy2XVal = analogRead(joy2X);
    int joy2YVal = analogRead(joy2Y);

    int servo1Angle = map(joy1XVal, 0, 1023, 0, 180);
    int servo2Angle = map(joy1YVal, 0, 1023, 0, 180);
    int servo3Angle = map(joy2XVal, 0, 1023, 0, 180);
    int servo4Angle = map(joy2YVal, 0, 1023, 0, 180);
 
    servo1.write(servo1Angle);
    servo2.write(servo2Angle);
    servo3.write(servo3Angle);
    servo4.write(servo4Angle);
 
    Serial.print("Servo1: "); Serial.print(servo1Angle);
    Serial.print(" | Servo2: "); Serial.print(servo2Angle);
    Serial.print(" | Servo3: "); Serial.print(servo3Angle);
    Serial.print(" | Servo4: "); Serial.println(servo4Angle);
  }
  
  delay(15);
}