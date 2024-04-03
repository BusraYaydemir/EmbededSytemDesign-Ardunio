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

/* Servo Motorun dönüş açısına göre led yakıp söndüren C++ kodu */

#include <Servo.h>

Servo myServo;
int myServoControlPin = 3;

void setup() {
  myServo.attach(myServoControlPin);
  for(int i = 4; i < 8; i++){
  	pinMode(i, OUTPUT);
  }
}

void loop() {
  for(int angle = 0; angle < 180; angle++){
  	myServo.write(angle);
    angleSetting(angle);
    delay(100);
  }
  for(int angle = 180; angle >= 0; angle--){
  	myServo.write(angle);
    angleSetting(angle);
    delay(100);
  }
}

void angleSetting(int angle){
  if(angle >= 0 && angle < 45)
      controlLed(1,0,0,0);
    else if (angle >= 45 && angle < 90)
      controlLed(1,1,0,0);
    else if (angle >= 90 && angle < 135)
      controlLed(1,1,1,0);
    else if (angle >= 135 && angle < 180)
      controlLed(1,1,1,1);
}

void controlLed(int a, int b, int c, int d) {
  digitalWrite(4, a);
  digitalWrite(5, b);
  digitalWrite(6, c);
  digitalWrite(7, d);
}

/* Relay SPDT(Single Pole Double Throw) ile Ampul yakıp söndüren C++ kodu */

#define control_pin 9

void setup()
{
  pinMode(control_pin, OUTPUT);
}

void loop()
{
  digitalWrite(control_pin, HIGH);
  delay(1000); 
  digitalWrite(control_pin, LOW);
  delay(1000); 
}

/* Ultrasonic Distance Sensorü (HC-SR04) çalıştıran C++ kodu */

#define trig 6
#define echo 5

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  
  digitalWrite(trig, LOW);
  
  long time = pulseIn(echo, HIGH);
  long distance = time * 0.01715;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
}

/* RGB Ledde sırasıyla kırmızı-mavi-yeşil renklerini yakan C++ kodu */

#define red 8
#define blue 7
#define green 6

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  
  digitalWrite(red,1);
  delay(1000);
  digitalWrite(red,0);
  
  digitalWrite(green,1);
  delay(1000);
  digitalWrite(green,0);
  
  digitalWrite(blue,1);
  delay(1000);
  digitalWrite(blue,0);
}

/* RGB Ledde sırasıyla tüm renklerini yakan C++ kodu */

#define green 3
#define blue 5
#define red 6

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  digitalWrite(red,0);
  digitalWrite(green,0);
  digitalWrite(blue,0);
  
  for(int i=0;i<256;i++){
    
   analogWrite(red,i);
   delay(20);
  }
  
  digitalWrite(red,0);
  
  for(int i=0;i<256;i++){
    
   analogWrite(blue,i);
   delay(20);
  }
  digitalWrite(blue,0);
  
  for(int i=0;i<256;i++){
    
   analogWrite(green,i);
   delay(20);
  }
}


/* Potansiyometreye göre servo motoru döndüren C++ kodu */

#include <Servo.h>

#define pot A1
int value;
float voltage;
Servo myServo;
int myServoControlPin = 13;
int angle;

void setup()
{
  pinMode(pot, INPUT);
  Serial.begin(9600);
  myServo.attach(myServoControlPin);
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
  angle = ((float)value * 180)/1024;
  myServo.write(angle);
  delay(500);
}


/* Mesafe sensörüne göre RGB de renk değiştiren C++ kodu */

#define trig 13
#define echo 12
#define red 11
#define blue 10
#define green 9

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  
  digitalWrite(trig, LOW);
  
  long time = pulseIn(echo, HIGH);
  long distance = time * 0.01715;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance >= 0 && distance <= 70) {
    ledControl(1,0,0);
  } else if(distance >= 71 && distance <= 140){
  	ledControl(0,0,1);
  } else if(distance >= 141 && distance <= 200){
  	ledControl(0,1,0);
  }
  delay(500);
}
void ledControl(int a, int b, int c) {
  digitalWrite(red, a);
  digitalWrite(blue, b);
  digitalWrite(green, c);
}


/* Remote Control C++ kodu */

#include <IRremote.h>

int receiver_pin = 10;
IRrecv receiver(receiver_pin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop()
{
  if(receiver.available()){
    if(receiver.decode(&results)) {
    int command = receiver.decodedIRData.command;
    Serial.println(command);
    delay(500);
    }
  }
  receiver.resume();
}

/*Remote Controlde basılan tuşa göre led yakıp söndüren C++ kodu */

#include<IRremote.h>

int receiver_pin=10;
int led_1=7;
int led_2=6;
int led_3=5;

IRrecv receiver(receiver_pin);

decode_results results;

void setup()
{
  Serial.begin(9600);
  //Make the receiver enabled...
  receiver.enableIRIn(); 
}

void loop()
{
  //If any command has been sent from the transmitter
  if(receiver.available())
    {
        if(receiver.decode(&results)){
          //Read the command (button) and assign it to a variable...
          int command=receiver.decodedIRData.command; 
          Serial.println(command);
          if(command==69){
            digitalWrite(led_1,1);
            digitalWrite(led_2,0);
            digitalWrite(led_3,0);
          }else if(command==70){
            digitalWrite(led_1,1);
            digitalWrite(led_2,1);
            digitalWrite(led_3,0);
          }else if(command==71){
            digitalWrite(led_1,1);
            digitalWrite(led_2,1);
            digitalWrite(led_3,1);

          }
        }
    }
    receiver.resume();
}

/*Push Button'a basarken ledi yakıp bırakınca ledi söndüren C++ kodu*/

int button=7;
int led=6;

void setup()
{
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  
}

void loop()
{
  
  if(digitalRead(button)==1){
    
    digitalWrite(led,1);
    
  }else{
    digitalWrite(led,0);
  }
}

/*Ledleri Push Buttona basılıyken sırasıyla basılı değilkende aynı anda yakıp söndüren C++ kodu*/

int button=10;

void setup()
{
  for(int i=9;i>=2;i--){
    pinMode(i,OUTPUT);
  }
  pinMode(button,INPUT);
}

void loop()
{
  if(digitalRead(button)==1){
    
   for(int i=9;i>=2;i--){
   	digitalWrite(i,1);
    delay(50);
    digitalWrite(i,0);
  }
    
    for(int i=2;i<=9;i++){
   	digitalWrite(i,1);
    delay(50);
    digitalWrite(i,0);
  }
    
  }else{
    for(int i=9;i>=2;i--){
   	    digitalWrite(i,0);
  }
    delay(500);
    
    for(int i=9;i>=2;i--){
   	    digitalWrite(i,1);
  }
  }
}

/*Push Button ile basarken soldan sağa basmıyorken sağdan sola akan led C++ kodu*/

int button = 13;

void setup()
{
  for(int i=12;i>=9;i--){
    pinMode(i,OUTPUT);
  }
  pinMode(button,INPUT);
}

void loop()
{
  if(digitalRead(button)==1){
    
   for(int i=12;i>=9;i--){
   	digitalWrite(i,1);
    delay(200);
    digitalWrite(i,0);
   }
    
  }else{
    for(int i=9;i<=12;i++){
   	digitalWrite(i,1);
    delay(200);
    digitalWrite(i,0);
   }
  }
}