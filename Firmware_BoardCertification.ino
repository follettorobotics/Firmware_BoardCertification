#include <Ethernet.h>
#include <SPI.h>
#include <Dns.h>
#include <Dhcp.h>

#include "tcp_handler.h"
#include "sensorHandler.h"
#include "relayHandler.h"
#include "loadcellHandler.h"
#include "externalMotor.h"
#include "internalMotor.h"

#define SERVER_PORT 502
#define sspin       53

IPAddress ip(192, 168, 0, 110);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

TCPHandler& tcpHandler = TCPHandler::getInstance();

void setup()
{
	Serial.begin(115200);
    Ethernet.init(sspin);

    tcpHandler.begin(mac, ip);
    Serial.print("IP: ");
    Serial.println(ip);
    
    Serial.println("tcp begin"); 

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
    Serial.println("internal motor");
    InternalMotorSetup::initializePins(); 
}

void loop()
{
    TCPHandler& tcpHandler = TCPHandler::getInstance(); 
	tcpHandler.clientHandle();
}
