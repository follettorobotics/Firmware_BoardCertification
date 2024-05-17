#ifndef INTERNALMOTOR_H
#define INTERNALMOTOR_H

#include <Arduino.h>

#define startByte                   0x7E
#define internalMotorRunRspCommand  0XC2
#define endByte                     0xAA

#define MOTOR                       6 
#define BUITIN_MOTOR_EN             39

// motor DIR, PWM
#define PIN_PE6     33
#define PIN_PH4     7

#define PIN_PE7     32
#define PIN_PH5     8

#define PIN_PL6     43
#define PIN_PE5     3

#define PIN_PL7     42
#define PIN_PH3     6

#define PIN_PE2     35
#define PIN_PE3     5

#define PIN_PH7     34
#define PIN_PE4     2

struct MotorPins{
    int8_t dir;
    int8_t pwm; 
};

const MotorPins motorPinAddress[MOTOR] = {
    {PIN_PE6,PIN_PH4}, 
    {PIN_PE7,PIN_PH5},
    {PIN_PL6,PIN_PE5}, 
    {PIN_PL7,PIN_PH3}, 
    {PIN_PE2,PIN_PE3},
    {PIN_PH7,PIN_PE4} 
}; 

// internal motor setup class 
class InternalMotorSetup {
public:
    static void initializePins(){
        pinMode(BUITIN_MOTOR_EN, OUTPUT);
        digitalWrite(BUITIN_MOTOR_EN, false);

        DDRE |= 0b11000100;
        DDRH |= 0b10000000;

        for (int i=0; i<MOTOR; i++){
            int8_t dir = motorPinAddress[i].dir;
            int8_t pwm = motorPinAddress[i].pwm;
            pinMode(dir, OUTPUT);
            pinMode(pwm, OUTPUT);
            digitalWrite(dir, false);
            digitalWrite(pwm, false);
        }
    }
}; 

class InternalMotorHandler {
private:

    uint8_t motorNumber;
    uint8_t motorDir;     
    uint16_t motorStep = 3200;

    int8_t DIR;
    int8_t PWM;

    float speed = 0; 

public:
    InternalMotorHandler(int motorNumber, int motorDir):
    motorNumber(motorNumber), motorDir(motorDir), motorStep(motorStep){
        
        DIR = motorPinAddress[motorNumber - 1].dir;
        PWM = motorPinAddress[motorNumber - 1].pwm;

        if (motorNumber == 2 || motorNumber == 3){
            digitalWrite(DIR, 0);
            // Serial.println("if motor number 2 or 3, dir setting"); 
        }else {
            if (motorDir != 0){
                if (motorNumber == 0){ 
                    PORTE |= 0b01000000; 
                }else if(motorNumber == 1){
                    PORTE |= 0b10000000; 
                }else if(motorNumber == 4){
                    PORTE |= 0b00000100; 
                }else if(motorNumber == 5){
                    PORTH |= 0b10000000; 
                }
            }else {
                if(motorNumber == 0){
                    PORTE &= 0b10111111; //off
                }else if(motorNumber == 1){
                    PORTE &= 0b01111111; //off
                }else if(motorNumber == 4){
                    PORTE &= 0b11111011; //off
                }else if(motorNumber == 5){
                    PORTH &= 0b01111111; //off
                }
            }
        }
    }

    bool execute(); 
    size_t response(byte* motorControlRsp); 
};



#endif