#include <Servo.h>        //Servo library
 
 Servo servo_test;      //initialize a servo object for the connected servo  
                
 int angle = 0;    
 const int SW_pin = 2; // digital pin connected to switch output
 const int X_pin = 0; // analog pin connected to X output
 const int Y_pin = 1; // analog pin connected to Y output
 const int servo_pin = 9; //PWM pin connected to servo input

void setup() {
  // Initialize SW pin to value of 1
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  
  //Initialize Motor
  servo_test.attach(9);   // attach the signal pin of servo to pin9 of arduino
}

void loop() {
  //Read Input from Joystick
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  //delay(500);
  
  //Move motor according to joystick input
  angle = 100*analogRead(X_pin);            // reading the potentiometer value between 0 and 1023 
  angle = map(angle, 0, 1023, 0, 179);     // scaling the potentiometer value to angle value for servo between 0 and 180) 
  servo_test.write(angle);                   //command to rotate the servo to the specified angle 
  delay(500);
}
