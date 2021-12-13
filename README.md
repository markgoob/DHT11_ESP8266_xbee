# DHT11_ESP8266_xbee
Use Xbee to join Arduino UNO R3 and ESP8266 to measure the temperature and humidity.

/****Facility****/
1. XBee S2C 
2. Arduino UNO R3
3. Breadboardp
4. jump line
5. Arduino Uno R3 LCD monitor
6. ESP8266 W-ROOM 02

/****XCTU****/
Serial : 115200
Firmware : ZIGBEE TH REG

Coordinator
ID PANID : 1001
SC ScanChannles : 7FFF
CE : Enable[1]
DH : Roter MAC address (before 4bits) //like 0012A300
DL : Roter MAC address (after 4bits) // like 41CFC030

Roter
ID PANID : 1001
SC ScanChannles : 7FFF
CE : AT[0]
DH : Roter MAC address (before 4bits) //like 0012A300
DL : Roter MAC address (after 4bits) // like 41CFC030
