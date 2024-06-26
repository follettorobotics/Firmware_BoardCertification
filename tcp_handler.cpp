#include "tcp_handler.h"

uint16_t TCPHandler::port = 502;

TCPHandler& TCPHandler::getInstance(){
    static TCPHandler instance;
    return instance;
}

void TCPHandler::begin(byte mac[], IPAddress ip){
    Ethernet.begin(mac, ip);

    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield not found.");
      while (true) {
        delay(1); // 무한 루프
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }

    TCPserver.begin();
}


void TCPHandler::clientHandle(){
    EthernetClient newClient = TCPserver.available();

    if (newClient && !TCPclient.connected()){
        TCPclient = newClient;  // over-write TCPclient
        Serial.println("tcp client disconnected and new client accept");
    }

    // parse the message logic 
    messageHandle(); 

    return;
}

void TCPHandler::messageHandle(){
    byte request[20] {0, };
    size_t requestSize = 0;

    // check the data 
    // if the client disconnected, client.available() return 0
    int dataSize = TCPclient.available();
    if (dataSize > 0){
        for (int i=0; i<dataSize; i++){
            byte data = TCPclient.read();
            request[requestSize++] = data; 
        }
    }
    
    if (requestSize != 0){
        Dispatcher& dispatch = Dispatcher::getInstance();

        byte response[100] = {0, };
        size_t responseSize = 0;

        responseSize = dispatch.dispatch(request, requestSize, response);

        sendMessageToClient(response, responseSize); 
    }

}

bool TCPHandler::sendMessageToClient(const byte* message, size_t size){
  // Serial.print("response: "); 
  // for (int i=0; i<size; i++){
  //   Serial.print(message[i]);
  //   Serial.print(" "); 
  // }
  // Serial.println(); 
    if (TCPclient.connected()){
        TCPclient.write(message, size);
        return true; 
    }else{
        EthernetClient newClient = TCPserver.available();
        if (newClient){
            TCPclient = newClient;
            TCPclient.write(message, size); 
            return true; 
        }
        else{
            Serial.println("tcp not available to send response message");
            return false; 
        }
    }
}