#line 1 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Device\\Motor\\externalMotor\\externalMotor.h"
#ifndef EXTERNALMOTOR_H
#define EXTERNALMOTOR_H

#define startByte                   0x7E
#define externalMotorRunRspCommand  0XC3
#define endByte                     0xAA

#define EX_MOTOR           4

#define PIN_PC5         32
#define PIN_PC4         33
#define PIN_PC3         34
#define PIN_PC2         35

#define PIN_PB7         13
#define PIN_PB6         12
#define PIN_PB5         11
#define PIN_PB4         10

// motor direction
#define DIR_1                    0x00
#define DIR_2                    0xff

struct ExMotorPins{
    int8_t DIR;
    int8_t PWM; 
};

const ExMotorPins exMotorPinAddress[EX_MOTOR] = {
   {PIN_PC5,PIN_PB7},
   {PIN_PC4,PIN_PB6},
   {PIN_PC3,PIN_PB5},
   {PIN_PC2,PIN_PB4} 
}; 

class ExternalMotorSetup {
public:
    static void initializePins(){
        for (int i=0; i<EX_MOTOR; i++){
            int8_t dir = exMotorPinAddress[i].DIR;
            int8_t pwm = exMotorPinAddress[i].PWM;
            pinMode(dir, OUTPUT);
            pinMode(pwm, OUTPUT);
            digitalWrite(dir, false);
            digitalWrite(pwm, false);
        }   
    }
}; 

class ExternalMotorHandler {
private:

    uint8_t motorNumber;
    uint8_t motorDir;     
    uint16_t motorStep = 50000;

    uint8_t dirPin; 
    uint8_t pwmPin;

public:

    ExternalMotorHandler(int motorNumber, uint8_t motorDir):
    motorNumber(motorNumber), motorDir(motorDir){

        dirPin = exMotorPinAddress[motorNumber].DIR;
        pwmPin = exMotorPinAddress[motorNumber].PWM;

        if (motorDir == DIR_1){
            digitalWrite(dirPin, true);
        }else{
            digitalWrite(dirPin, false);
        }
    }

    bool execute(); 
    size_t response(byte* exMotorControlRsp); 

}; 

#endif
