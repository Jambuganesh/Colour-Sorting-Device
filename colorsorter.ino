#include <Servo.h>
Servo Myservo;
int pos;
const int dirPin = 6;
const int stepPin = 7;
const float stepsPerRevolution = 3200;
const int S2 = 11;
const int S3 = 10;
const int sensorOut = 12;
const int S0 = 8;
const int S1 = 9;
int color = 2;
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
// Stores the red. green and blue colors
int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int q[501];
int x = 0;
int l = 0;


int rmin = 200;
int rmax = 370;
int gmin = 276;
int gmax = 395;
int bmin = 195;
int bmax = 312;

void stepper() {
  Serial.println("Starting stepper motor");
  for (float i = 0.0; i < stepsPerRevolution/8; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(8000);
    digitalWrite(stepPin, LOW);
    //delayMicroseconds(100);
  }
}

void colorstore() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  redFrequency = pulseIn(sensorOut, LOW);
  Serial.print(" R = ");
  Serial.print(redFrequency);
  redColor = map(redFrequency, rmin, rmax, 255, 0);
  Serial.print(" R = ");
  Serial.print(redColor);
  delay(1000);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  greenFrequency = pulseIn(sensorOut, LOW);
  Serial.print("  ||| G = ");
  Serial.print(greenFrequency);
  greenColor = map(greenFrequency, gmin, gmax, 255, 0);
  Serial.print(" G = ");
  Serial.print(greenColor);
  delay(1000);


  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  blueFrequency = pulseIn(sensorOut, LOW);
  Serial.print("  ||| B = ");
  Serial.print(blueFrequency);
  blueColor = map(blueFrequency, bmin, bmax, 255, 0);
  Serial.print(" B = ");
  Serial.print(blueColor);
  delay(1000);
  // if (abs(redColor) > abs(greenColor) && abs(redColor) > abs(blueColor)) {
  //   Serial.println(" - RED detected!");
  //   //q[x++] = 1;
  //   Myservo.write(30);
  // }
  // else if (abs(blueColor) > abs(redColor) && abs(blueColor) > abs(greenColor)) {
  //   Serial.println(" - blue detected!");
  //   //q[x++] = 2;
  //   Myservo.write(90);
  // }  else if(abs(redColor) < abs(greenColor) && abs(greenColor) > abs(blueColor)) {
  //   Serial.println(" - green detected!");
  //   //q[x++] = 3;
  //   Myservo.write(150);
  // } 
  // //Serial.println(x);
  /*if(blueColor<0){
    if((redColor)<abs(blueColor)&&(blueColor)<10)
    {
      Serial.println("- Green detected");
      //delay(1000);
      Myservo.write(90);
      stepper();
      delay(500);
      Myservo.write(90);
    }
    else {
      Serial.println("-  RED detected");
      //delay(1000);
      Myservo.write(30);
      stepper();
      delay(500);
      Myservo.write(30);
    }
  }
  else {
    Serial.println("- Blue detected");
    //delay(800);
    Myservo.write(150);   
    stepper();
    delay(500);
    Myservo.write(150);
  }
  */
  if((redColor)>=(blueColor)&&(redColor)>=(greenColor))
    {
      Serial.println(" - RED detected");
      //delay(1000);
      Myservo.write(30);
      stepper();
      delay(500);
      Myservo.write(30);
    }
    else if((blueColor)>=(redColor)&&(blueColor)>=(greenColor)){
      Serial.println(" - Blue detected");
      //delay(1000);
      Myservo.write(150);
      stepper();
      delay(500);
      Myservo.write(150);
   }
   else if((redColor)>=(greenColor)&&(blueColor)>=(greenColor)) {
    Serial.println(" - Green detected");
    //delay(800);
    Myservo.write(90);   
    stepper();
    delay(500);
    Myservo.write(90);
  }
  else {
    Serial.println("- Green detected");
    //delay(800);
    Myservo.write(90);   
    stepper();
    delay(500);
    Myservo.write(90);
  }
}

void servo() {
}

void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  memset(q, -1, sizeof(q));

  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, LOW);
  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Myservo.attach(3);
  // Begins serial communication
  Serial.begin(9600);
}

void loop() {
  //stepper();
  colorstore();
  //delay(1000);
  // if (q[l] != -1) {
  //   if (q[l] == 1) {
  //     Myservo.write(30);
  //   }
  //   if (q[l] == 2) {
  //     Myservo.write(90);
  //   }
  //   if (q[l] == 3) {
  //     Myservo.write(150);
  //   }
  //   //Serial.println(l);
  //   if (l == x) {
  //     q[l] = -1;
  //     l = 0;
  //     x = 0;
  //   } else {
  //     q[l] = -1;
  //     l++;
  //   }
  // }
}
