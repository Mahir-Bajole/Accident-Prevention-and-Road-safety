#include "arduino_secrets.h"
#include "thingProperties.h"
#include "Servo.h"

Servo myservo;
int led = D0; 

Servo myservo1;
int led1 = D1;

void setup() {
  // Initialize serial and wait for port to open:
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1500);
  pinMode(D7, OUTPUT); // Buzzer
  pinMode(D8, OUTPUT); // Motor
  pinMode(D5, INPUT); // Sensor connected to D9
  pinMode(D6, INPUT); // Another sensor connected to A0
  

  pinMode(led, OUTPUT);
  myservo.attach(D2);  // Use D3 for the first servo, adjust as needed

  pinMode(led1, OUTPUT);
  myservo1.attach(D3);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  

  

}

void loop() {
  ArduinoCloud.update();
   int sensorValue = digitalRead(D5); // Read the sensor connected to D9
  int anotherSensorValue = digitalRead(D6); // Read another sensor connected to A0
   

  
  if (sensorValue == LOW ) {
    digitalWrite(D7, LOW);
    digitalWrite(D6,HIGH);// Turn on buzzer
    // Turn on motor
    delay(3000); // Keep them on for 500 milliseconds
  } else {
    digitalWrite(D7, HIGH); // Turn off buzzer
   // Turn off motor
  }
  if (anotherSensorValue == LOW) {
     // Turn on buzzer
    digitalWrite(D8, LOW);
    digitalWrite(D5,HIGH);// Turn on motor
    delay(3000); // Keep them on for 500 milliseconds
  } else {
    // Turn off buzzer
    digitalWrite(D8, HIGH); // Turn off motor
}
  

   if(barrier_zebra == 1 && smart_signal == 0)
  {
    for (int i = 0; i < 2; i++) {
    myservo.write(i == 0 ? 0 : 130);
    myservo1.write(i == 0 ? 130 : 0);
    delay(5000);
    }

  }

  else
  {
    myservo.write(120);
    myservo1.write(120);

  }
  
  if(smart_signal == 1 && barrier_zebra == 0)
  {
  for (int i = 0; i < 2; i++) {
    digitalWrite(led, i == 0 ? HIGH : LOW);
    digitalWrite(led1, i == 0 ? LOW : HIGH);
    delay(5000);
  }
 
}
else
{
    digitalWrite(led, 1);
    digitalWrite(led1, 1);
  
}
  
if(barrier_zebra == 1 && smart_signal == 1){
  for (int i = 0; i < 2; i++) {
    
    myservo.write(i == 0 ? 0 : 130);
    myservo1.write(i == 0 ? 130 : 0);
    digitalWrite(led, i == 0 ? HIGH : LOW);
    digitalWrite(led1, i == 0 ? LOW : HIGH);
    delay(5000);
  }
}
else
{
    digitalWrite(led, 1);
    digitalWrite(led1, 1);
     myservo.write(120);
    myservo1.write(120);
    //message = "Traffic Signal is ON";
}

}
/*
  Since SmartSignal is READ_WRITE variable, onSmartSignalChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSmartSignalChange()  {
  // Add your code here to act upon SmartSignal change
  

}

/*
  Since BarrierZebra is READ_WRITE variable, onBarrierZebraChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBarrierZebraChange()  {
  // Add your code here to act upon BarrierZebra change
}
/*
  Since Signal is READ_WRITE variable, onSignalChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSignalChange()  {
  // Add your code here to act upon Signal change
}
/*
  Since Servo1 is READ_WRITE variable, onServo1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onServo1Change()  {
  // Add your code here to act upon Servo1 change
}
/*
  Since Servo2 is READ_WRITE variable, onServo2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onServo2Change()  {
  // Add your code here to act upon Servo2 change
}
/*
  Since Messenger is READ_WRITE variable, onMessengerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessengerChange()  {
  // Add your code here to act upon Messenger change
}
/*
  Since Message is READ_WRITE variable, onMessageChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessageChange()  {
  // Add your code here to act upon Message change
}