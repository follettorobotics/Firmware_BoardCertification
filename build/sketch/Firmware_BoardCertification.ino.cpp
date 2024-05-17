#include <Arduino.h>
#line 1 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
#include <Ethernet.h>
#include <SPI.h>
#include <Dns.h>
#include <Dhcp.h>

#include "Communication/tcp_handler.h"
#include "Device/Sensor/sensorHandler.h"
#include "Device/Relay/relayHandler.h"
#include "Device/LoadCell/loadcellHandler.h"
#include "Device/Motor/externalMotor/externalMotor.h"

#define SERVER_PORT 502
#define sspin       53

IPAddress ip(192, 168, 0, 141);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

TCPHandler& tcpHandler = TCPHandler::getInstance();

#line 20 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
void setup();
#line 46 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
void loop();
#line 20 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
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

    // loadcell initial
    Serial.println("loadcell");
    LoadcellSetup::initializePins(); 

    // external motor initial
    Serial.println("external motor");
    ExternalMotorSetup::initializePins(); 

    // internal motor initial
}

void loop()
{
	
}

