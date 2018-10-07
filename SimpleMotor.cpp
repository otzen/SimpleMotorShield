// Otzen Motor shield library
// copyright Martin Otzen, 2018
// this code is public domain, enjoy!

#include "SimpleMotor.h"

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #if defined(__AVR__)
    #include <avr/io.h>
  #endif
  #include "WProgram.h"
#endif

// 8-bit bus after the 74HC595 shift register 
// (not Arduino pins)
// These are used to set the direction of the bridge driver.
#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR3_A 5
#define MOTOR3_B 7
#define MOTOR4_A 0
#define MOTOR4_B 6

// Arduino control pins for the shift register
#define MOTORLATCH 12
#define MOTORCLK 4
#define MOTORENABLE 7
#define MOTORDATA 8


SimpleMotor::SimpleMotor( void ) 
{
}

void SimpleMotor::begin( void )
{
  shiftRegisterInit();
  disable( MOTOR1 );
  disable( MOTOR2 );
  disable( MOTOR3 );
  disable( MOTOR4 );
}

void SimpleMotor::enable( MOTOR_PIN_T motorNumber, MOTOR_DIR_T direction )
{
    if( direction == FORWARD )
    {
        switch( motorNumber )
        {
            case MOTOR1:
                shiftRegisterWrite( MOTOR1_A, HIGH );
                shiftRegisterWrite( MOTOR1_B, LOW );
            break;
            case MOTOR2:
                shiftRegisterWrite( MOTOR2_A, HIGH );
                shiftRegisterWrite( MOTOR2_B, LOW );
            break;
            case MOTOR3:
                shiftRegisterWrite( MOTOR3_A, HIGH );
                shiftRegisterWrite( MOTOR3_B, LOW );
            break;
            case MOTOR4:
                shiftRegisterWrite( MOTOR4_A, HIGH );
                shiftRegisterWrite( MOTOR4_B, LOW );
            break;
            default:
                // don't know any panic exception in Arduino, so just silently ignore.
            break;
        }
    }
    else if( direction == REVERSE )
    {
        switch( motorNumber )
        {
            case MOTOR1:
                shiftRegisterWrite( MOTOR1_A, LOW );
                shiftRegisterWrite( MOTOR1_B, HIGH );
            break;
            case MOTOR2:
                shiftRegisterWrite( MOTOR2_A, LOW );
                shiftRegisterWrite( MOTOR2_B, HIGH );
            break;
            case MOTOR3:
                shiftRegisterWrite( MOTOR3_A, LOW );
                shiftRegisterWrite( MOTOR3_B, HIGH );
            break;
            case MOTOR4:
                shiftRegisterWrite( MOTOR4_A, LOW );
                shiftRegisterWrite( MOTOR4_B, HIGH );
            break;
            default:
                // don't know any panic exception in Arduino, so just silently ignore.
            break;
        }
    }
    else
    {
        // don't know any panic exception in Arduino, so just silently ignore.
    }
}


void SimpleMotor::disable( MOTOR_PIN_T motorNumber )
{
    switch( motorNumber )
    {
        case MOTOR1:
            analogWrite( MOTOR1, 0);
            shiftRegisterWrite( MOTOR1_A, LOW );
            shiftRegisterWrite( MOTOR1_B, LOW );
        break;
        case MOTOR2:
            analogWrite( MOTOR2, 0);
            shiftRegisterWrite( MOTOR2_A, LOW );
            shiftRegisterWrite( MOTOR2_B, LOW );
        break;
        case MOTOR3:
            analogWrite( MOTOR3, 0);
            shiftRegisterWrite( MOTOR3_A, LOW );
            shiftRegisterWrite( MOTOR3_B, LOW );
        break;
        case MOTOR4:
            analogWrite( MOTOR4, 0);
            shiftRegisterWrite( MOTOR4_A, LOW );
            shiftRegisterWrite( MOTOR4_B, LOW );
        break;
        default:
            // don't know any panic exception in Arduino, so just silently ignore.
        break;
    }
}

void SimpleMotor::shiftRegisterWrite(int output, int high_low)
{
  // Maintain a copy of the current content of the register on chip.
  static int register_cache = 0;
  // The defines HIGH and LOW are 1 and 0.
  // So this is valid.
  bitWrite(register_cache, output, high_low);

  // Use the default Arduino 'shiftOut()' function to
  // shift the bits with the MOTORCLK as clock pulse.
  // The 74HC595 shiftregister wants the MSB first.
  // After that, generate a latch pulse with MOTORLATCH.
  shiftOut(MOTORDATA, MOTORCLK, MSBFIRST, register_cache);
  delayMicroseconds(5);    // For safety, not really needed.
  digitalWrite(MOTORLATCH, HIGH);
  delayMicroseconds(5);    // For safety, not really needed.
  digitalWrite(MOTORLATCH, LOW);
}

void SimpleMotor::shiftRegisterInit( void )
{
    // Set pins for shift register to output
    pinMode(MOTORLATCH, OUTPUT);
    pinMode(MOTORENABLE, OUTPUT);
    pinMode(MOTORDATA, OUTPUT);
    pinMode(MOTORCLK, OUTPUT);

    // Set pins for shift register to default value (low);
    digitalWrite(MOTORDATA, LOW);
    digitalWrite(MOTORLATCH, LOW);
    digitalWrite(MOTORCLK, LOW);
    // Enable the shift register, set Enable pin Low.
    digitalWrite(MOTORENABLE, LOW);
}

SimpleMotor mShield;
