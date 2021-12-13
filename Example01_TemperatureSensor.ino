
#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "wifi_info.h"
#include "ThingSpeak.h"
//include the Arduino library for your real sensor here, e.g. <DHT.h>
#define LOG_D(fmt, ...)   printf_P(PSTR(fmt "\n") , ##__VA_ARGS__);

//change to your thingspeak channel_ID and Write_API_key
unsigned long myChannelNumber = ;
const char * myWriteAPIKey = "";

int a,b,c,d;
int tmp;
int tmp_catch;
int rh;
char Thousand[20];  
char Hundred[20];  
char Ten[20];  
char Indivual[20];  


void setup() {
	Serial.begin(115200);
 ThingSpeak.begin(client);
	wifi_connect(); // in wifi_info.h
	my_homekit_setup();
}

void loop() {
	my_homekit_loop();
	delay(10);
}

//==============================
// Homekit setup and loop
//==============================

// access your homekit characteristics defined in my_accessory.c
extern "C" homekit_server_config_t config;
extern "C" homekit_characteristic_t cha_current_temperature;
extern "C" homekit_characteristic_t humidity;       //humidity


static uint32_t next_heap_millis = 0;
static uint32_t next_report_millis = 0;

void my_homekit_setup() {
	arduino_homekit_setup(&config);
}

void my_homekit_loop() {
  arduino_homekit_loop();
	
	const uint32_t t = millis();
 
	if (t > next_report_millis) {
		// report sensor values every 10 seconds
		next_report_millis = t + 10 * 1000;
		my_homekit_report();
	}
	if (t > next_heap_millis) {
		// show heap info every 5 seconds
		next_heap_millis = t + 5 * 1000;
		LOG_D("Free heap: %d, HomeKit clients: %d",
				ESP.getFreeHeap(), arduino_homekit_connected_clients_count());

	}
 
}

void my_homekit_report() {


 if (Serial.available()){  
    
     int xbee = Serial.parseInt();
     delay(30);
     
        c = xbee/100%10; //温度
        d = xbee/1000%10;  
         
         itoa(c, Hundred, 20);               
         itoa(d, Thousand, 20); 
        
        a = xbee%10; //湿度
        b = xbee/10%10; 
         itoa(a, Indivual, 20);                       
         itoa(b, Ten, 20);
  
         strcat(Thousand, Hundred);
         strcat(Ten, Indivual); 
         
        int tmp = atoi(Thousand);
        int rh = atoi(Ten); 
        
Serial.print("Accept from xBee is : ");
Serial.println(xbee);
  
        if(tmp == 0){
          tmp = tmp_catch;
               
          }else if(tmp > 0){
            tmp_catch = tmp;
            }
         
    
        if(xbee > 99999 ){  

        tmp = tmp*(-1);
     
        }
    ThingSpeak.setField(1, tmp);
    ThingSpeak.setField(2, rh);
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  
	float temperature_value = tmp; 
  float humidity_value = rh;
  
  cha_current_temperature.value.float_value = temperature_value;
  humidity.value.float_value = humidity_value;
  
  LOG_D("Current temperature: %.1f", temperature_value);
  homekit_characteristic_notify(&cha_current_temperature, cha_current_temperature.value);
  homekit_characteristic_notify(&humidity, humidity.value);
  delay(5000);

   }
   

}
