#include "LoadCellHandler.h"

HX711 scales[NUM_LOADCELLS];

bool LoadCellHandler::execute() {
    bool success = true;

    // 로드셀 초기화 및 테어링
    // LoadcellSetup::initializePins(loadcellTarget);

    // 로드셀 값 읽기
    loadcellValues[loadcellTarget] = scales[loadcellTarget].get_units();
    Serial.print("Load Cell ");
    Serial.print(loadcellTarget + 1);
    Serial.print(": ");
    Serial.print(loadcellValues[loadcellTarget]);
    Serial.println(" units ");
    
    delay(10);

    return success;
}

size_t LoadCellHandler::response(byte* loadcellRsp) {
    size_t index = 0;
    loadcellRsp[index++] = startByte; 
    loadcellRsp[index++] = loadCellRspCommand;


    float value = loadcellValues[loadcellTarget];

    byte* bytePointer = (byte*) &value;  
    for (int j = 0; j < sizeof(float); j++) {
        loadcellRsp[index++] = bytePointer[j];
    }
    
    loadcellRsp[index++] = endByte;
    return index; 
}

