/*Tüm Ledleri sırasıyla sağdan sola yakıp söndüren C++ Kodu*/

void setup()
{
  for(int i = 2; i <= 11 ; i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(int i = 2; i <= 11; i++){
  	digitalWrite(i, 1);
    delay(50);
    digitalWrite(i, 0);
  }
}

/*Tüm Ledleri sırasıyla sağdan sola ve soldan sağa yakıp söndüren C++ Kodu*/

void setup()
{
  for(int i = 2; i <= 11 ; i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(int i = 2; i <= 11; i++){
  	digitalWrite(i, 1);
    delay(50);
    digitalWrite(i, 0);
  }
  for(int i = 10; i > 2; i--){
  	digitalWrite(i, 1);
    delay(50);
    digitalWrite(i, 0);
  }
}

/*Tüm ledleri dıştan içe ve içten dışa sırasıyla yakıp söndüren C++ kodu*/

void setup()
{
  for(int i = 2; i <= 11 ; i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(int i = 2; i < 11; i++){
    if(i == 6){
      continue;
    }
  	digitalWrite(i, 1);
    digitalWrite(13-i, 1);
    delay(500);
    digitalWrite(i, 0);
    digitalWrite(13-i, 0);
  }
}

/*Potansiyometre ile gelen değerleri okuyan C++ kodu*/

#define pot A0
int value;
float voltage;

void setup()
{
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(pot);
  Serial.print("The Value: ");
  Serial.println(value);
  voltage = ((float)value/1023)*5;
  Serial.print("The Voltage: ");
  Serial.println(voltage);
  Serial.println();
  delay(500);
}

/* Potansiyometre ile gelen değere göre yanacak ledleri ayarlayan C++ kodu*/

#define pot A0
int value;
float voltage;

void setup()
{
  pinMode(pot, INPUT);
  Serial.begin(9600);
  for(int i = 2; i<7; i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  value = analogRead(pot);
  Serial.print("The Value: ");
  Serial.println(value);
  voltage = ((float)value/1023)*5;
  Serial.print("The Voltage: ");
  Serial.println(voltage);
  Serial.println();
  
  if(voltage < 1){
    for(int i = 2; i<7; i++){
    	digitalWrite(i, 0);
  	}
  }
  else if(voltage >= 1 && voltage < 2) {
    digitalWrite(2, 1);
    for(int i = 3; i<7; i++){
    	digitalWrite(i, 0);
  	}
  }
  else if(voltage >= 2 && voltage < 3) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    for(int i = 4; i<7; i++){
    	digitalWrite(i, 0);
  	}
  }
  else if(voltage >= 3 && voltage < 4) {
    for(int i = 2; i<5; i++){
    	digitalWrite(i, 1);
  	}
    digitalWrite(5, 0);
    digitalWrite(6, 0);
  }
  else if(voltage >= 4 && voltage < 5) {
    for(int i = 2; i<6; i++){
    	digitalWrite(i, 1);
  	}
    digitalWrite(6, 0);
  }
  else {
    for(int i = 2; i<7; i++){
    	digitalWrite(i, 1);
  	}
  }
  delay(500);
}


/* Potansiyometre ile gelen değere göre yanacak ledleri ayarlayan C++ kodu*/

#define pot A0
int value;
float voltage;

void setup()
{
  pinMode(pot, INPUT);
  Serial.begin(9600);
  for(int i = 2; i<7; i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  value = analogRead(pot);
  Serial.print("The Value: ");
  Serial.println(value);
  voltage = ((float)value/1023)*5;
  Serial.print("The Voltage: ");
  Serial.println(voltage);
  Serial.println();
  
  if(voltage < 1){
    ledControl(0,0,0,0,0);
  }else if(voltage >= 1 && voltage < 2) {
    ledControl(1,0,0,0,0);
  }else if(voltage >= 2 && voltage < 3) {
    ledControl(1,1,0,0,0);
  }else if(voltage >= 3 && voltage < 4) {
    ledControl(1,1,1,0,0);
  }else if(voltage >= 4 && voltage < 5) {
    ledControl(1,1,1,1,0);
  }else {
    ledControl(1,1,1,1,1);
  }
  delay(500);
}

void ledControl(int a, int b, int c, int d, int e) {
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  digitalWrite(6, e);
}

/* LDR dan gelen değeri okuyan C++ kodu */

#define ldr A1
int value;
float voltage;

void setup()
{
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(ldr);
  Serial.print("The Value: ");
  Serial.println(value);
  Serial.println();
  delay(500);
}

/* LDR dan gelen değere göre led yakan C++ kodu */

#define ldr A1
int value;
int led = 2;

void setup()
{
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(ldr);
  Serial.print("The Value: ");
  Serial.println(value);
  Serial.println();
  (value <= 155) ? digitalWrite(led,1): digitalWrite(led,0);
  delay(500);
}


/* Servo Motoru çalıştıran C++ kodu */

#include <Servo.h>

Servo myServo;
int myServoControlPin = 3;

void setup()
{
  myServo.attach(myServoControlPin);
}

void loop()
{
  for(int angle = 0; angle <= 180; angle++){
    myServo.write(angle);
    delay(50);
  }
  for(int angle = 180; angle >= 0; angle--){
    myServo.write(angle);
    delay(50);
  }
}
