#include "loadcellHandler.h"

HX711 scales[NUM_LOADCELLS];

bool LoadCellHandler::execute() {
    bool success = true;
    for (int i = 0; i < NUM_LOADCELLS; i++) {
        if (scales[i].is_ready()) {
            scales[i].set_gain(128); // Ensure correct gain is set before reading
            delay(50); // Increase delay to ensure stable reading

            loadcellValues[i * 2] = scales[i].read();
            Serial.print("Load Cell ");
            Serial.print(i + 1);
            Serial.print(" value (gain 128): ");
            Serial.println(loadcellValues[i * 2]); 

            scales[i].set_gain(32);
            delay(50); // Increase delay to ensure stable reading

            loadcellValues[i * 2 + 1] = scales[i].read();
            Serial.print("Load Cell ");
            Serial.print(i + 1);
            Serial.print(" value (gain 32): ");
            Serial.println(loadcellValues[i * 2 + 1]); 
        } else {
            Serial.print("Load Cell ");
            Serial.print(i + 1);
            Serial.println(" is not ready.");
            success = false;
        }
    }
    return success;
}

size_t LoadCellHandler::response(byte* loadcellRsp) {
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
