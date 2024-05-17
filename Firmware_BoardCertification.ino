#include <Ethernet.h>
#include <SPI.h>
#include <Dns.h>
#include <Dhcp.h>

#include "tcp_handler.h"
#include "sensorHandler.h"
#include "Relay/relayHandler.h"
#include "LoadCell/loadcellHandler.h"
#include "Motor/externalMotor/externalMotor.h"

#define SERVER_PORT 502
#define sspin       53

IPAddress ip(192, 168, 0, 141);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

TCPHandler& tcpHandler = TCPHandler::getInstance();

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
