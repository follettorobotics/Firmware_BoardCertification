#line 1 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Device\\LoadCell\\loadcellHandler.cpp"
#include "./loadcellHandler.h"

bool LoadCellHandler::execute(){
    bool success = true;
    for (int i = 0; i < NUM_LOADCELLS; i++) {
        if (scales[i].is_ready()) {
            loadcellValues[i * 2] = scales[i].read();
            scales[i].set_gain(32);
            delay(10);
            loadcellValues[i * 2 + 1] = scales[i].read();
            scales[i].set_gain(128);
            delay(10); 
        } else {
            success = false;
        }
    }
    return success;
}

size_t LoadCellHandler::response(byte* loadcellRsp){
    size_t index = 0;
    loadcellRsp[index++] = startByte; 
    loadcellRsp[index++] = loadCellRspCommand;

    for (int i = 0; i < NUM_LOADCELLS * 2; i++) {
        long value = loadcellValues[i];
        loadcellRsp[index++] = value & 0xFF;
        loadcellRsp[index++] = (value >> 8) & 0xFF;
        loadcellRsp[index++] = (value >> 16) & 0xFF;
        loadcellRsp[index++] = (value >> 24) & 0xFF;
    }

    loadcellRsp[index++] = endByte;
    return index; 
}
