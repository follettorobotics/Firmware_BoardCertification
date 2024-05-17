#include "internalMotor.h"

bool InternalMotorHandler::execute(){
    for (int i=0; i<motorStep; i++){
        digitalWrite(PWM, true);
        digitalWrite(PWM, false);
        delayMicroseconds(30); 
    }
}

size_t InternalMotorHandler::response(byte* internalMotorRsp){
    size_t rspIndex = 0; 

    internalMotorRsp[rspIndex++] = startByte;
    internalMotorRsp[rspIndex++] = internalMotorRunRspCommand;
    internalMotorRsp[rspIndex++] = motorNumber;
    internalMotorRsp[rspIndex++] = motorDir;
    internalMotorRsp[rspIndex++] = endByte;

    return rspIndex; 
}