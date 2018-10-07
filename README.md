# SimpleMotorShield

L293d Motor shield V1 firmware. 

Enables very simple Arduino style control of the shield.

This library is not intended as a full feature library for the L293d shield, This library is made for the very entry user,
 and for educational purpose, enabling to control a motor with digitalWrite() and analogWrite() and a few other commands.

In fact the library only supports DC-motors connected to M1, M2, M3 and M4.

Focus was on enabling the training to focus on Arduino digital i/o and PWM.

The quickest way to learn the library is to look in the example Simplemotor_Demo, the code in there is plenty commented to learn the commands.

For a more advanced library that uses all the fatures and motor types of the L293d V1 shield see https://github.com/adafruit/Adafruit-Motor-Shield-library
