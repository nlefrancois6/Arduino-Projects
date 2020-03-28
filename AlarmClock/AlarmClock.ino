#include <DS3231.h>
DS3231  rtc(A4, A5);

const int buzzer = 9;
const int redpin = 10;
const int SW = 2;
const int greenpin = 5;
const int bluepin = 6;

//Set alarm time
//const int hour = 3600000;
//const int minute = 60000;
int setAlarm = true;
int time2wakeup = false;
String alarmTime = "10:41:40";

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
  Serial.begin(9600);

  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(10, 20, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(16, 12, 2019);   // Set the date to January 1st, 2014
}

void loop() {
  // put your main code here, to run repeatedly:
   // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  String heure = rtc.getTimeStr();
  Serial.println(rtc.getTimeStr());
  
  int offswitch = 1;
  int onswitch = 1;
  if (setAlarm == true){
    if(heure==alarmTime){
      setAlarm = false;
      time2wakeup=true;
    }
  }
  while(offswitch==1 && time2wakeup==true){
    int red = random(0, 100);
    int green = random(0, 100);
    int blue = random(0, 100);
    analogWrite(redpin, red);
    analogWrite(greenpin, green);
    analogWrite(bluepin, blue);
    int freq = random(100, 2000);
    tone(buzzer, freq);
    int buzz=random(10, 500);
    delay(1000);
    noTone(buzzer);
    int nobuzz=random(0, 1000);
    delay(nobuzz);
    Serial.print(digitalRead(SW));
    offswitch = digitalRead(SW);
  }
  while(offswitch == 0 && onswitch == 1){
    Serial.println("Get out of bed asshole  ");
    int red = 0;
    int green = 0;
    int blue = 0;
    delay(1000);
    analogWrite(redpin, red);
    analogWrite(greenpin, green);
    analogWrite(bluepin, blue);
    onswitch = digitalRead(SW);
  }
}
