# 1 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
# 2 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 3 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 4 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 5 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2

# 7 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 8 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 9 "C:\\Users\\escap\\Desktop\\board_certification\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2




IPAddress ip(192, 168, 0, 141);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

TCPHandler& tcpHandler = TCPHandler::getInstance();

void setup()
{
 Serial.begin(115200);
    Ethernet.init(53);

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
