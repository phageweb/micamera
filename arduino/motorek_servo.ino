#include <SerialCommand.h>

#include "interval.h"
#include <Servo.h>
#include "motorek.h"

//motor1 osa x
#define stepPin1 54
#define dirPin1 55
#define enablePin1 38

//motor1 osa y
#define stepPin2 60
#define dirPin2 61
#define enablePin2 56
//motor1 osa z
#define stepPin3 46
#define dirPin3 48
#define enablePin3 62  



Motorek motor1;
Motorek motor2;
Motorek motor3;

SerialCommand sCmd;     // SerialCommand object
Servo myservo1,myservo2,myservo3,myservo4;  // create servo object to control a servo

int degreeStart=0;
int degree=90;
  


//

void setup()
{
   //serial
 
  Serial.begin(9600);
  Serial.println("Starting....");

   // Setup callbacks for SerialCommand commands
  sCmd.addCommand("m1l",  m1l);          
  sCmd.addCommand("m1r",  m1r);         
  sCmd.addCommand("m2l",  m2l);          
  sCmd.addCommand("m2r",  m2r);         
  sCmd.addCommand("m3l",  m3l);          
  sCmd.addCommand("m3r",  m3r);         
  sCmd.addCommand("s1",  s1);
  sCmd.addCommand("s2",  s2);
  sCmd.addCommand("s3",  s3);
  sCmd.addCommand("s4",  s4);
  sCmd.addCommand("asb",  asb);
  
 // sCmd.addCommand("HELLO", sayHello);        // Echos the string argument back
  sCmd.addCommand("ssm",     ssm);  // set speed motor
  sCmd.addCommand("sds",     sds);  // set degree servo
  sCmd.setDefaultHandler(unrecognized);      // Handler for command that isn't matched  (says "What?")
  Serial.println("Ready");
  
///
  myservo1.attach(11);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(4);  // attaches the servo on pin 9 to the servo object
//  myservo1.writeMicroseconds(100);  // set servo to mid-point




  motor1.setPin(enablePin1,dirPin1,stepPin1);
  motor2.setPin(enablePin2,dirPin2,stepPin2);
 motor3.setPin(enablePin3,dirPin3,stepPin3);
}

void loop()
{
    sCmd.readSerial();     // We don't do much, just process serial command
   
     motor1.action();
     motor2.action();
     motor3.action();
  /*
   if (Comp("m1right")==0) {
        Serial.write("Motor 1 right...\n");
        motor1.right(10000);
    }
    if (Comp("m1left")==0) {
        Serial.write("Motor 1 left...\n");
        motor1.left(10000);}
  motor1.action();
  //motor1.action();
 */
  /*
  if (motor1.interval_motor.expired()) {
    motor1.interval_motor.set(motor1.CONST_interval_motor); // set new interval period
    if (stepState == LOW)
      stepState = HIGH;
    else
      stepState = LOW;

    digitalWrite(stepPin, stepState);
  }
  */


    
    //digitalWrite(enablePin, LOW);
  //delayMicroseconds(20);
  //digitalWrite(dirPin, LOW);



  /*
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
   // in steps of 1 degree
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15);                       // waits 15ms for the servo to reach the position
   }
   for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(15);                       // waits 15ms for the servo to reach the position
   }
   */

}



///
void m1r(){
motor1.right(2000);
}
void m1l(){
motor1.left(2000);
}
void m2r(){
motor2.right(2000);
}
void m2l(){
motor2.left(2000);
}
void m3r(){
motor3.right(2000);
}
void m3l(){
motor3.left(2000);
}
void s1(){
  myservo1.write(degree);              // tell servo to go to position in variable 'pos'
}
void s2(){
  myservo2.write(degree);              // tell servo to go to position in variable 'pos'
}
void s3(){
  myservo3.write(degree);              // tell servo to go to position in variable 'pos'
}
void s4(){
  myservo4.write(degree);              // tell servo to go to position in variable 'pos'
}

void asb(){
  myservo1.write(degreeStart);              // tell servo to go to position in variable 'pos'
  myservo2.write(degreeStart);              // tell servo to go to position in variable 'pos'
  myservo3.write(degreeStart);              // tell servo to go to position in variable 'pos'
  myservo4.write(degreeStart);              // tell servo to go to position in variable 'pos'
}


void unrecognized(const char *command) {
  Serial.println("What?");
}

void ssm() {
  int aNumber;
  char *arg;

  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atoi(arg);    // Converts a char string to an integer
    Serial.print("Set speed motor [us]: ");
    Serial.println(aNumber);
    motor1.setSpeed(aNumber);
    motor2.setSpeed(aNumber);
    motor3.setSpeed(aNumber);
  }
  else {
    Serial.println("No arguments");
  }

 
}

void sds() {
  int aNumber;
  char *arg;

  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atoi(arg);    // Converts a char string to an integer
    Serial.print("Set degree servo [°]: ");
    degree=aNumber;
  }
  else {
    Serial.println("No arguments");
  }

 
}


