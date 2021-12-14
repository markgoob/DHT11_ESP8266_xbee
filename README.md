# Use ESP8266 and XBee to sent the data for HomeKit 
Use Xbee to join Arduino UNO R3 and ESP8266 to measure the temperature and humidity.

/****Facility****/
1. XBee S2C 
2. Arduino UNO R3
3. Breadboardp
4. jump line
5. Arduino Uno R3 LCD monitor
6. ESP8266 W-ROOM 02
7. iPad Pro 2021 (or which device can support with HomeKit App )

/****XCTU****/
1. Serial : 115200
2. Firmware : ZIGBEE TH REG

/****--Coordinator****/
1. ID PANID : 1001
2. SC ScanChannles : 7FFF
3. CE : Enable[1]
4. DH : Roter MAC address (before 4bits) //like 0012A300
5. DL : Roter MAC address (after 4bits) // like 41CFC030

/****--Roter****/
1. ID PANID : 1001
2. SC ScanChannles : 7FFF
3. CE : AT[0]
4. DH : Coordinator MAC address (before 4bits) //like 0012A300
5. DL : Coordinator MAC address (after 4bits) // like 41CFC030
