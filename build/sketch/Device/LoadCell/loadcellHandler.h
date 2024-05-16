#line 1 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Device\\LoadCell\\loadcellHandler.h"
#ifndef LOADCELLHANDLER_H
#define LOADCELLHANDLER_H

#include <HX711.h>

const int numCells = 16;

#define PIN_PC0     53
#define PIN_PC1     54

#define PIN_PD4     47
#define PIN_PD5     48
#define PIN_PD6     49
#define PIN_PD7     50

#define PIN_PF0     97
#define PIN_PF1     96
#define PIN_PF2     95
#define PIN_PF3     94 
#define PIN_PF4     93
#define PIN_PF5     92
#define PIN_PF6     91
#define PIN_PF7     90

#define PIN_PH2     14

#define PIN_PJ0     63
#define PIN_PJ1     64
#define PIN_PJ2     65
#define PIN_PJ3     66
#define PIN_PJ4     67
#define PIN_PJ5     68
#define PIN_PJ6     69
#define PIN_PJ7     79

#define PIN_PK0     89
#define PIN_PK1     88
#define PIN_PK2     87
#define PIN_PK3     86
#define PIN_PK4     85
#define PIN_PK5     84
#define PIN_PK6     83
#define PIN_PK7     82

#define PIN_PL4     39

typedef struct LOAD_ts{
   int8_t   DOUT;
   int8_t   SCKD;
}LOAD_ts;
const LOAD_ts LOADCELL[numCells]={
   {PIN_PD5, PIN_PF6},
   {PIN_PJ6, PIN_PK6},
   {PIN_PD4, PIN_PF7},
   {PIN_PJ7, PIN_PK7},
   {PIN_PD7, PIN_PF4},
   {PIN_PJ4, PIN_PK4},
   {PIN_PD6, PIN_PF5},
   {PIN_PJ5, PIN_PK5},
   {PIN_PL4, PIN_PF2},
   {PIN_PJ2, PIN_PK2},
   {PIN_PH2, PIN_PF3},
   {PIN_PJ3, PIN_PK3},
   {PIN_PC0, PIN_PF0},
   {PIN_PJ0, PIN_PK0},
   {PIN_PC1, PIN_PF1},
   {PIN_PJ1, PIN_PK1}
};

#endif