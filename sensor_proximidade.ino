#include <Ultrasonic.h>
 
#define pino_trigger 4
#define pino_echo 5
#define pino_beep 11
#define pino_led_verde 10

Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  pinMode(pino_beep, OUTPUT);
  pinMode(pino_led_verde, OUTPUT);
}
 
void loop()
{
  float cm;
  long microsec = ultrasonic.timing();
  
  cm = ultrasonic.convert(microsec, Ultrasonic::CM);

  if (cm <= 5) {
    digitalWrite(pino_led_verde, LOW);
    digitalWrite(pino_beep, HIGH);
  } else {
    digitalWrite(pino_beep, LOW);
    digitalWrite(pino_led_verde, HIGH);
  }
  
  delay(500);
}
