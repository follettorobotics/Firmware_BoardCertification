#include <Arduino.h>
#line 1 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
#include <Ethernet.h>
#include <SPI.h>
#include <Dns.h>
#include <Dhcp.h>

#include "Communication/tcp_handler.h"
#include "Device/Sensor/sensorHandler.h"
#include "Device/Relay/relayHandler.h"

#define SERVER_PORT 502
#define sspin       53

IPAddress ip(192, 168, 0, 141);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

TCPHandler& tcpHandler = TCPHandler::getInstance();

#line 18 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
void setup();
#line 34 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
void loop();
#line 18 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
void setup()
{
	Serial.begin(115200);
    Ethernet.init(sspin);

    tcpHandler.begin(mac, ip);

    // sensor initial
    SensorHandler& sensorHandler = SensorHandler::getInstance();
    sensorHandler.initialSensorHandler(); 

    // relay initial
    Serial.println("relay");
    RelaySetup::initializePins(); 
}

void loop()
{
	
}

