const int XtrigPin = A0;
const int XechoPin = A1;
const int YtrigPin = A2;
const int YechoPin = A3;
const int ZtrigPin = A4;
const int ZechoPin = A5;
void setup() { 
Serial.begin(9600);} 
void loop()
{
float Xduration, Xcm, Yduration, Ycm, Zduration, Zcm;
//X Measurement
pinMode(XtrigPin, OUTPUT); 
digitalWrite(XtrigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(XtrigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(XtrigPin, LOW);
pinMode(XechoPin, INPUT); 
Xduration = pulseIn(XechoPin, HIGH); 
Xcm = microsecondsToCentimeters(Xduration); 

//Y Measurement
pinMode(YtrigPin, OUTPUT); 
digitalWrite(YtrigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(YtrigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(YtrigPin, LOW);
pinMode(YechoPin, INPUT); 
Yduration = pulseIn(YechoPin, HIGH); 
Ycm = microsecondsToCentimeters(Yduration); 


//Z Measurement
pinMode(ZtrigPin, OUTPUT); 
digitalWrite(ZtrigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(ZtrigPin, HIGH); 
delayMicroseconds(10);
digitalWrite(ZtrigPin, LOW);
pinMode(ZechoPin, INPUT); 
Zduration = pulseIn(ZechoPin, HIGH); 
Zcm = microsecondsToCentimeters(Zduration); 

Serial.print("X: ");
Serial.print(Xcm);
Serial.print("cm ");
Serial.print("Y: ");
Serial.print(Ycm);
Serial.print("cm ");
Serial.print("Z: ");
Serial.print(Zcm);
Serial.print("cm"); 
Serial.println(); 
delay(1000);
}
double microsecondsToCentimeters(long microseconds)
{return microseconds / 29.155 / 2.0;}
