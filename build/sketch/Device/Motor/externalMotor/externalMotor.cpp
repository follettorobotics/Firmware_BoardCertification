#line 1 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Device\\Motor\\externalMotor\\externalMotor.cpp"
#include "./externalMotor.h"

bool ExternalMotorHandler::execute(){
    for (int i=0; i<motorStep; i++){
        digitalWrite(pwmPin, true);
        digitalWrite(pwmPin, false);
        delayMicroseconds(300); 
    }
}

size_t ExternalMotorHandler::response(byte* exMotorControlRsp){
    size_t index = 0;
    exMotorControlRsp[index++] = startByte;
    exMotorControlRsp[index++] = externalMotorRspCommand;
    exMotorControlRsp[index++] = motorNumber;
    exMotorControlRsp[index++] = motorDir;
    exMotorControlRsp[index++] = motorStep & 0xFF;  
    exMotorControlRsp[index++] = (motorStep >> 8) & 0xFF;
    exMotorControlRsp[index++] = endByte;       
    return index; 
}
