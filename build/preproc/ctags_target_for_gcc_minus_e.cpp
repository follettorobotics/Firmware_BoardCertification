# 1 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino"
# 2 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 3 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 4 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 5 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2

# 7 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 8 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 9 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 10 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 11 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2
# 12 "C:\\Users\\Owner\\OneDrive\\바탕 화면\\Firmware_BoardCertification\\Firmware_BoardCertification.ino" 2




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
