/*
Biped bot 
ITSP Team 152,IIT Bombay
Author:Saurabh Chavan
Co-author:Shubham Yadav,Ketan Shirokha
*/

#include <Servo.h>

Servo leftbot;
Servo rightbot;
Servo leftup;
Servo rightup;
Servo leftArm;
Servo rightArm;

String command;
char order=0;
char mode=0;
long duration, distance;

//from bluetooth code
char val; // variable to receive data from the serial port
int ledpin = 13; // LED connected to pin 48 (on-board LED)

// controlling varibales for ultrasonic loop
const int loopPeriod = 20;          // a period of 20ms = a frequency of 50Hz
unsigned long timeLoopDelay   = 0;


int zero_ref_lb = 93;
int zero_ref_rb = 130;
int zero_ref_lu = 77;
int zero_ref_ru = 97;
int ra=15;
int la=169;

//ultrasound variables

const int trigPin = 2;
const int echoPin = 4;

// automode variables
// define the states
#define DRIVE_FORWARD     0
#define TURN_LEFT         1

int state = DRIVE_FORWARD;
void leftBackward() {   //Moving Left Leg Forward
  leftbot.write(zero_ref_lb - 23); //left foot -23
  rightbot.write(zero_ref_rb - 18);
  //delay(100); //right foot -18
  delay(600);

for(int i=zero_ref_ru;i>=zero_ref_ru-19;i--)
 {
  rightup.write(i);
 delay(15); 
 }
  leftup.write(zero_ref_lu - 16);   //left hip -29
  delay(500);

  rightbot.write(zero_ref_rb - 10);     //right foot back to flat -18
  delay(50);
  rightbot.write(zero_ref_rb); //-8
  delay(50);
  
  rightbot.write(zero_ref_rb); //+5
  leftbot.write(zero_ref_lb);       //left foot back to flat  0
 // delay(500);
}


void rightBackward() {    //Moving Right Leg Forward
  rightbot.write(zero_ref_rb + 23);      //right foot   +22
  leftbot.write(zero_ref_lb + 17);       //left foot +17
  delay(600);

 for(int i=zero_ref_lu-16;i<=zero_ref_lu;i++)
 {
  leftup.write(i);
 delay(15); 
 }
  rightup.write(zero_ref_ru);       //right hip  +16
  delay(500);

  leftbot.write(zero_ref_lb + 10);       //left foot back to flat  +20
  delay(50);
  leftbot.write(zero_ref_lb ); //+10
  delay(50);
  
  leftbot.write(zero_ref_lb);  //+0
  rightbot.write(zero_ref_rb);    //+0       //right foot back to flat
  //delay(500);
}

//---------------LEFT LEG FORWARD MOTION----------------------------------------------
void leftForward() { // moving left leg backwards

leftbot.write(zero_ref_lb - 23);  // left foot  -23
  //delay(500);
  rightbot.write(zero_ref_rb - 18);  //right foot  -18
    delay(600);
 
 for(int i=zero_ref_ru;i<=zero_ref_ru+19;i++)
 {
  rightup.write(i);
  delay(15); 
 }
  leftup.write(zero_ref_lu + 15);   //left hip  +16
  delay(600);

  rightbot.write(zero_ref_rb -10);     //right foot back to flat  -18
  delay(50);
  rightbot.write(zero_ref_rb); //-8
  delay(50);
  
  //rightbot.write(zero_ref_rb); //+5
  leftbot.write(zero_ref_lb);       //left foot back to flat  //0
  //delay(500);
}
//---------------RIGHT LEG FORWARD MOTION--------------------------------------------------------
void rightForward() {
  rightbot.write(zero_ref_rb + 23);      //right foot      +22
  //delay(100);
  leftbot.write(zero_ref_lb + 17);       //left foot +17
  delay(600);

for(int i=zero_ref_lu+16;i>=zero_ref_lu;i--)
 {
  leftup.write(i);
 delay(15); 
 }
  rightup.write(zero_ref_ru );       //right hip -16
  delay(500);

  leftbot.write(zero_ref_lb + 10);       //left foot back to flat +20
  delay(50);
  leftbot.write(zero_ref_lb ); //+10
  delay(50);
  //leftbot.write(zero_ref_lb); //0
  rightbot.write(zero_ref_rb);     //0      //right foot back to flat
  //delay(50);

}


//------------------------STOP-FUNCTION----------------------------------------------------
void stop_rb()
{
  leftbot.write(zero_ref_lb);
  rightbot.write(zero_ref_rb);
  leftup.write(zero_ref_lu);
  rightup.write(zero_ref_ru);
}
//---------------------------------------------------
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
//-----------------------------------------------------
void driveForw(int time)
{ 
  //stop_rb();
  leftForward();
  delay(time);
  rightForward();
  delay(time);
}

void autodriveForw(int time)
{
   leftForward();
  delay(time);
  rightForward();
  delay(time);
}
//------------------------Backward------------------------
void driveBack(int time)
{
  //stop_rb();
  leftBackward();
  delay(time);
  rightBackward();
  delay(time);
    
}
//--------------------------------TURN RIGHT---------------------------------------------
void turnRight()
{
  //Lift right leg----------------------------
  stop_rb();
   rightbot.write(zero_ref_rb + 23);      //right foot      +22i
  //delay(100);
  leftbot.write(zero_ref_lb + 18);       //left foot +17
  delay(800);

 for(int i=zero_ref_lu;i>=zero_ref_lu-14;i--)
 {
  leftup.write(i);
 delay(20); 
 }
 rightup.write(zero_ref_ru+8);       //right hip  +16
  delay(500);
  
  leftbot.write(zero_ref_lb + 10); //left foot back to flat +20
  delay(50);
  leftbot.write(zero_ref_lb );     //+10
  delay(50);
  //leftbot.write(zero_ref_lb);    //0
  rightbot.write(zero_ref_rb);     //right foot back to flat
  
  delay(1000);
  //Lift the other leg-------------------------------
  leftbot.write(zero_ref_lb - 23);  // left foot  -23
  //delay(500);
  rightbot.write(zero_ref_rb - 18);  //right foot  -18
  delay(600);
  
  for(int i=zero_ref_ru+8;i>=zero_ref_ru;i--)
  {
  rightup.write(i);
  delay(20);
  }
  
  leftup.write(zero_ref_lu);
  delay(500);
  
  rightbot.write(zero_ref_rb -10);     //right foot back to flat  -18
  delay(50);
  rightbot.write(zero_ref_rb); //-8
  delay(50);
  
  //rightbot.write(zero_ref_rb); //+5
  leftbot.write(zero_ref_lb);       //left foot back to flat  //0
  
}
//------------------------------TURN LEFT-------------------------------------------------------

void turnLeft()
{
  //Lift left leg--------------------------------
  leftbot.write(zero_ref_lb - 24);  // left foot  -23
  rightbot.write(zero_ref_rb - 17);  //right foot  -18
  delay(800);
 
  for(int i=zero_ref_ru;i<=zero_ref_ru+15;i++)
  {
  rightup.write(i);
  delay(20); 
  }
  leftup.write(zero_ref_lu -7);   //left hip  +16
  delay(500);
  
  rightbot.write(zero_ref_rb -10);     //right foot back to flat  -18
  delay(50);
  rightbot.write(zero_ref_rb); //-8
  delay(50);
  leftbot.write(zero_ref_lb);       //left foot back to flat  //0
 delay(1000);
  
  //Lift right leg-----------------------------------
  rightbot.write(zero_ref_rb + 23);      //right foot      +22
  //delay(100);
  leftbot.write(zero_ref_lb + 17);       //left foot +17
  delay(600);

for(int i=zero_ref_lu-7;i<=zero_ref_lu;i++)
 {
  leftup.write(i);
 delay(20); 
 }
  rightup.write(zero_ref_ru );       //right hip -16
  delay(600);
//-------BOTH FEET FLAT----------
  leftbot.write(zero_ref_lb + 8);       //left foot back to flat +20
  delay(30);
  leftbot.write(zero_ref_lb ); //+10
  delay(50);
  rightbot.write(zero_ref_rb);     //0      //right foot back to flat
  delay(200);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void readUltrasonicSensors()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = microsecondsToCentimeters(duration);

}
void auto_mode()
{
  
 if(state == DRIVE_FORWARD) // no obstacles detected
    {
        if(distance > 15 || distance < 0) // if there's nothing in front of us distance will be negative for some ultrasonics if there's nothing in range)
        {
            //-----------
            autodriveForw(300);
        }
        else // there's an object in front of us
        {
            state = TURN_LEFT;
        }
    }
    else if(state == TURN_LEFT) // obstacle detected -- turn left
    {
        unsigned long timeToTurnLeft = 1200; // 90 degrees turn hone ka time yhan dal de
        
        unsigned long turnStartTime = millis(); // save the time that we started turning

        while((millis()-turnStartTime) < timeToTurnLeft) // stay in this loop until timeToTurnLeft  has elapsed
        {
            // turn left ka code
            turnLeft();
           
        }
        
        state = DRIVE_FORWARD;
    }
    
}
void setup()
{
  Serial.begin(9600);
  leftbot.attach(9);
  rightbot.attach(10);
  leftup.attach(6);
  rightup.attach(11);
  leftArm.attach(5);
  rightArm.attach(3);
  
  
  //ultra
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledpin, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  
  stop_rb();
  leftArm.write(la);
  rightArm.write(ra);
  //----------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------
  Serial.println("setup is done");
  delay(1000);
  
}
void loop()
{
if (millis() - timeLoopDelay >= loopPeriod)
  {
  readUltrasonicSensors(); // read and store the measured distances
  if(mode==1)
  auto_mode();
  timeLoopDelay = millis();
  }
  
switch (order)
{
// here command nature is to be changed depending upon interface
        //--------------FORWARD-----------------------
        

case 'w':
        {
            driveForw(400);         
            //stop_rb();
            //digitalWrite(ledpin, HIGH);  // turn ON the LED
            Serial.write('w');
            break;
        }
        //--------------BACKWARD--------------------
      case 's':
        {
          driveBack(400);
          //stop_rb();
          Serial.write('s');
          break;
        }       
        //------------------TURN-RIGHT---------------------------------
      case 'd':
        {
            turnRight();
            //stop_rb();
            Serial.write('d');
          break;
        }
      //---------------------TURN LEFT---------------------------------
      case 'a' :
        {
            turnLeft();
            //stop_rb();
            Serial.write('a');
            break;
        }
         //---------------------TURN LEFT ARM UP---------------------------------
      case 'q' :
        {
           for(;la>=1;la--)
           {
           leftArm.write(la);
           delay(40);
           }
            //stop_rb();
            Serial.write('q');
            break;
        }
         //---------------------TURN RIGHT ARM UP---------------------------------
      case 'e' :
        {    
          for(;ra<=179;ra++)
           {
           leftArm.write(ra);
           delay(40);
           }
            //stop_rb();
            Serial.write('e');
            break;
        }
         //---------------------TURN LEFT ARM DOWN---------------------------------
      case 'z' :
        {    
          for(;la<=169;la++)
           {
           leftArm.write(la);
           delay(40);
           }
           //stop_rb();
           Serial.write('z');
            break;
        }
         //---------------------TURN RIGHT ARM DOWN---------------------------------
      case 'c' :
        {  
            for(;ra>=1;ra--)
           {
           leftArm.write(ra);
           delay(40);
           }
            //stop_rb();
            Serial.write('c');
            break;
        }
      //------------------------STOP-----------------------------------
      case 'x':
        {
          stop_rb();
          //digitalWrite(ledpin, LOW); 
          Serial.write('x');                      // otherwise turn it OFF
          break;
        }
        case '1':
        {
          mode=1;
          Serial.write('1');
          break;
        }
        case '2':
        {
          mode=0;
          Serial.write('2');
          break;
        }
      }
}
void serialEvent()
{
//order
  if (Serial.available() > 0)
  {
    order = Serial.read();
  }
}

