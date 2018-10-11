/*
 * CUSTOM SONOFF B1 FIRMWARE
 * Maxime MOREILLON
 * 
 * Flash settings:
 * Board type: Generic ESP8266 (even though the chip is an ESP8285)
 * Flash mode: DOUT
 * Flash size: 1M (64 SPIFFS)
 */

// Libraries
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>

// WiFi
#define AP_SSID "teliot"
#define AP_PASSWORD "poketenashi"

// Network
#define WWW_PORT 80
#define WS_PORT 81

// I/O
#define DI_pin 12
#define DCK_pin 14



// Party mode
#define PARTY_DURATION 5000
boolean party_mode = 0;
boolean last_party_mode = 0;
long last_change_time = 0;
long party_start_time = -PARTY_DURATION;

// Web server
ESP8266WebServer www_server(WWW_PORT);
WebSocketsServer ws_server = WebSocketsServer(WS_PORT);


// Commands sent through Web Socket
const char VACANT[] = "vacant";
const char OCCUPIED[] = "occupied";

// Door related variables
// Would be better if this was an int, but ah wel...
char* door_state = "UNKNOWN";

void setup() {

  // Mandatory initial delay
  delay(10);

  // Serial init
  Serial.begin(115200);
  Serial.println();
  Serial.println(); // Separate serial stream from initial gibberish
  Serial.println(F(__FILE__ " " __DATE__ " " __TIME__)); // Print the sketch information
  
  LED_setup();
  wifi_setup();
  web_server_setup();
  websocket_setup();
  
  LED_set(0,0,255,0,0); // Turn the light blue by default
}

void loop() {
  www_server.handleClient();
  ws_server.loop();
  
  // Party mode
  if(party_mode != last_party_mode){
    last_party_mode = party_mode;
    
    if(party_mode){
      // The party just started
      party_start_time = millis();
    }
    else {
      // The party is over
      if (strcmp(door_state,"OPEN")==0) {
        LED_set(0,255,0,0,0);
      }
      else if (strcmp(door_state,"CLOSED")==0){
        LED_set(255,0,0,0,0);
      }
      else {
        LED_set(0,0,255,0,0);
      }
    }
  }
  
  if(millis() - party_start_time < PARTY_DURATION){
    if(millis() - last_change_time > 50){
      last_change_time = millis();
      LED_set(random(0,255),random(0,255),random(0,255),0,0);
    }
  }
  else {
    // No long party mode
    party_mode = false;
  }
  
}
