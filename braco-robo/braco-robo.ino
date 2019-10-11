/*
  JoystickServoControl
  Control two servos with a joystick.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/JoystickServoControl

 */

#include <Servo.h>

#define SERVO_LEFT_PINA 9
#define SERVO_RIGHT_PINA 8
#define SERVO_LEFT_PINB 7
#define SERVO_RIGHT_PINB 6

#define CONTROL_LEFT_PINA 0
#define CONTROL_RIGHT_PINA 1
#define CONTROL_LEFT_PINB 2
#define CONTROL_RIGHT_PINB 3

// delay in milliseconds between each servo command
#define STEP_DELAY 90

// custom min/max pulse width settings that best suit my servos
// NB: default vaules are min pulse width=544, max pulse width=2400
#define IDEAL_MIN_PW 2400
#define IDEAL_MAX_PW 2400


Servo servo_leftA;
Servo servo_rightA;
Servo servo_leftB;
Servo servo_rightB;

void setup() {
  servo_leftA.attach(SERVO_LEFT_PINA,IDEAL_MIN_PW,IDEAL_MAX_PW);
  servo_rightA.attach(SERVO_RIGHT_PINA,IDEAL_MIN_PW,IDEAL_MAX_PW);
  servo_leftB.attach(SERVO_LEFT_PINB,IDEAL_MIN_PW,IDEAL_MAX_PW);
  servo_rightB.attach(SERVO_RIGHT_PINB,IDEAL_MIN_PW,IDEAL_MAX_PW);
}


void loop() {
  int left_readingA = analogRead(CONTROL_LEFT_PINA);
  int right_readingA = analogRead(CONTROL_RIGHT_PINA);
  int left_readingB = analogRead(CONTROL_LEFT_PINB);
  int right_readingB = analogRead(CONTROL_RIGHT_PINB);

  servo_leftA.write( map(left_readingA, 0, 1023, 0, 180) );
  servo_rightA.write( map(right_readingA, 0, 1023, 0, 180) );
  servo_leftB.write( map(left_readingB, 0, 1023, 0, 180) );
  servo_rightB.write( map(right_readingB, 0, 1023, 0, 180) );

  delay(STEP_DELAY);

}
