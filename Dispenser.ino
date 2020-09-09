#include <Servo.h>            // required libraries
#include <Stepper.h>
   
#define servo1pin 4              //
#define servo2pin 5              // pwm pins for servo
#define servo3pin 6              //   


#define coinpin 10               // pin that receives input from the coin acceptor

#define sw1 7                                   // switch 1 pin
#define sw2 8                                   // switch 2 pin
#define sw3 9                                   // switch 3 pin

const int motorSpeed = 20;                      // adjust speed as necessary
const int stepsPerRevolution = 200;             // this should be set according to the stepper used. The current 
const int rev = 20;                             // number of revolutions taken by the stepper
const int delay_time = 3000;                    // time for which the servo should open
const int servoangle = 25;                       // angle to be turned by the servo
int flag = 0;

// stepper 1 pins
#define step1_1 22
#define step1_2 23
#define step1_3 24
#define step1_4 25

//stepper 2 pins
#define step2_1 26
#define step2_2 27
#define step2_3 28
#define step2_4 29

//stepper 3 pins
#define step3_1 30
#define step3_2 31
#define step3_3 32
#define step3_4 33

// declaring function for actuation
void actuate(int,int,int,int,int);

//setting up input pins
void setup() {
  pinMode(coinpin, INPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);

  
}

void loop() {
  if(digitalRead(coinpin)){
    flag =1;
  }
  while(flag==1){
    if(digitalRead(sw1)){
      actuate(servo1pin,step1_1,step1_2,step1_3,step1_4) ;
      }
    else if(digitalRead(sw2)){
      actuate(servo2pin,step2_1,step2_2,step2_3,step2_4) ;
      }
    else if(digitalRead(sw3)){
      actuate(servo3pin,step3_1,step3_2,step3_3,step3_4) ;
      }
    
    
  }
}


void actuate(int servpin, int step1, int step2, int step3, int step4){
Servo servo;
Stepper stepper(stepsPerRevolution, step1,step2, step3,step4);
servo.attach(servpin);
stepper.setSpeed(motorSpeed);
servo.write(servoangle);
delay(delay_time);
servo.write(0);
stepper.step(rev*stepsPerRevolution);
flag=0;

}
