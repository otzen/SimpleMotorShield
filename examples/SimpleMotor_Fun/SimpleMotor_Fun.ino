#include <SimpleMotor.h>

void setup() 
{
  mShield.begin();
}

void loop() 
{
  // Forward on one wheel at the time.
  mShield.enable( MOTOR1 );
  analogWrite( MOTOR1, 255 );
  delay( 1000 );
  mShield.disable( MOTOR1 );

  mShield.enable( MOTOR3 );
  analogWrite( MOTOR3, 255 );
  delay( 1000 );
  mShield.disable( MOTOR3 );

  // Reverse on one wheel at the time.
  mShield.enable( MOTOR1, REVERSE );
  analogWrite( MOTOR1, 255 );
  delay( 1000 );
  mShield.disable( MOTOR1 );

  mShield.enable( MOTOR3, REVERSE );
  analogWrite( MOTOR3, 255 );
  delay( 1000 );
  mShield.disable( MOTOR3 );
  
  // Tight  turn left and right.
  mShield.enable( MOTOR1 );
  mShield.enable( MOTOR3, REVERSE );
  analogWrite( MOTOR1, 255 );
  analogWrite( MOTOR3, 255 );
  delay( 1000 );
  mShield.enable( MOTOR3 );
  mShield.enable( MOTOR1, REVERSE );
  delay( 1000 );
  mShield.disable( MOTOR3 );
  mShield.disable( MOTOR1 );

  while(1);
}
