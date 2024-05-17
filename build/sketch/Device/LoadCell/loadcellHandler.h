#line 1 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Device\\LoadCell\\loadcellHandler.h"
#ifndef LOADCELLHANDLER_H
#define LOADCELLHANDLER_H

#include <HX711.h>

const int NUM_LOADCELLS = 8;

#define startByte                   0x7E
#define loadCellRspCommand          0xC4
#define endByte                     0xAA

#define PIN_PJ0     63
#define PIN_PJ1     64
#define PIN_PJ2     65
#define PIN_PJ3     66
#define PIN_PJ4     67
#define PIN_PJ5     68
#define PIN_PJ6     69
#define PIN_PJ7     79

#define PIN_PB5     11

const int LOADCELL_SCK_PIN = PIN_PB5;

const int LOADCELL_DOUT_PINS[NUM_LOADCELLS] = {
		PIN_PJ7,
		PIN_PJ6,
		PIN_PJ5,
		PIN_PJ4,
		PIN_PJ3,
		PIN_PJ2,
		PIN_PJ1,
		PIN_PJ0

};

HX711 scales[NUM_LOADCELLS];

class LoadcellSetup{
public:
   static void initializePins(){
        for (int i = 0; i < NUM_LOADCELLS; i++) {
         scales[i].begin(LOADCELL_DOUT_PINS[i], LOADCELL_SCK_PIN);
         
         scales[i].set_scale();
         scales[i].tare();
      }
    }
};

class LoadCellHandler{
private:
   long loadcellValues[NUM_LOADCELLS * 2]; 

public:
   LoadCellHandler() {
        for (int i = 0; i < NUM_LOADCELLS * 2; i++) {
            loadcellValues[i] = 0;
        }
    }

   bool execute();
   size_t response(byte* loadcellRsp);
};

#endif