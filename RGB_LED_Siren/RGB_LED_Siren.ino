int redPin = 6;
int bluePin = 9;
int greenPin = 5;
int red = 255;
int blue = 0;
int green = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  red = 0;
  blue = 255;
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);

  delay(500);
  red = 255;
  blue = 0;
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
}
