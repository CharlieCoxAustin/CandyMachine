#include <Servo.h>
#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
Servo pusher;
Servo door;


void setup() 
{
  Serial.begin(9600);
  delay(10);
  pusher.attach(3);
  pusher.write(180);
}

void loop() 
{
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");

  delay(10);

  if (a < 40)
  {
    pusher.write(180);
    delay(2000);
    pusher.write(215);
    delay (2000);  
    pusher.write(180);
  }
}
