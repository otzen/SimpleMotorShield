// Otzen Motor shield library
// copyright Martin Otzen 2018
// this code is public domain, enjoy!

/*
 * Usage Notes:
 * This library is not intended as a full feature library
 * for the L293d shield, for that see the adafruit AFMotor shield.
 * This library is made for the very entry user, and for
 * educational purpose, enabling to control a motor with
 * digitalWrite() and analogWrite() and a few other commands.
 * Enabling the training to focus on digital io and PWM.
 */


#ifndef _SimpleMotor_h_
#define _SimpleMotor_h_


// Arduino pins for the motor enable.
typedef enum MOTOR_PIN
{
  MOTOR1 = 11,
  MOTOR2 =  3,
  MOTOR3 =  6,
  MOTOR4 =  5
} MOTOR_PIN_T;

// Direction type.
typedef enum MOTOR_DIR
{
  FORWARD,
  REVERSE
} MOTOR_DIR_T;

class SimpleMotor
{
  public:
    SimpleMotor( void );
    void begin( void );
    void enable( MOTOR_PIN_T motorNumber, MOTOR_DIR_T direction = FORWARD );
    void disable( MOTOR_PIN_T motorNumber );
  private:
    void shiftRegisterWrite( int output, int high_low );
    void shiftRegisterInit( void );
};

extern SimpleMotor mShield;

#endif
