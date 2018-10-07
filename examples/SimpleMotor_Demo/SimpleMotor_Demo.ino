#include <SimpleMotor.h>

void setup() 
{
  // Initialize the shield. Must be done before any other call to mShield.
  mShield.begin();
}

void loop() 
{
  // Before we can use the motor it must be enabled, lets enable motor 1.
  mShield.enable( MOTOR1 );
  // The speed us set by sending a pwm signal on the motor pin, let give full trohtle to motor 1.
  analogWrite( MOTOR1, 255 );
  // Let the motor spin for a while.
  delay( 1000 );
  // When the motor is disabled, the connection to that motor is broken and the PWM signal set to zero.
  mShield.disable( MOTOR1 );

  // Lets try it all n motor 3 also.
  mShield.enable( MOTOR3 );
  analogWrite( MOTOR3, 255 );
  delay( 1000 );
  mShield.disable( MOTOR3 );

  // To run motor 1 in reverse we must call the enable() method with the REVERSE parameter.
  mShield.enable( MOTOR1, REVERSE );
  analogWrite( MOTOR1, 255 );
  delay( 1000 );
  // We can also use the FORWARD parameter, it is the same as calling with no parameter (FORWARD is default).
  mShield.enable( MOTOR1, FORWARD );
  // Note that because disable() was not called on motor 1, we do not need to set the speed again, it just reverses.
  delay( 1000 );

  // To help catch the car, we disable all motors and go into a for-ever loop.
  mShield.disable( MOTOR1 );
  mShield.disable( MOTOR2 );
  mShield.disable( MOTOR3 );
  mShield.disable( MOTOR4 );
  while(1);
}
