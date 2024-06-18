#include "LoadCellHandler.h"

HX711 scales[NUM_LOADCELLS];

bool LoadCellHandler::execute(int loadcellIndex) {
    bool success = true;

    // 로드셀 초기화 및 테어링
    LoadcellSetup::initializePins(loadcellIndex);

    // 로드셀 값 읽기
    loadcellValues[loadcellIndex] = scales[loadcellIndex].get_units(1);
    Serial.print("Load Cell ");
    Serial.print(loadcellIndex + 1);
    Serial.print(": ");
    Serial.print(loadcellValues[loadcellIndex]);
    Serial.println(" units ");
    
    delay(10);

    return success;
}

size_t LoadCellHandler::response(byte* loadcellRsp) {
    size_t index = 0;
    loadcellRsp[index++] = startByte; 
    loadcellRsp[index++] = loadCellRspCommand;

    for (int i = 0; i < NUM_LOADCELLS; i++) {
        float value = loadcellValues[i];
        byte* bytePointer = (byte*) &value;  
        for (int j = 0; j < sizeof(float); j++) {
            loadcellRsp[index++] = bytePointer[j];
        }
    }
    loadcellRsp[index++] = endByte;
    return index; 
}

