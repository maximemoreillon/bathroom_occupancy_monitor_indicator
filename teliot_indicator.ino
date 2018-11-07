/*
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
#define WIFI_AP_SSID "toiletIndicatorSouth"
#define WIFI_AP_PASSWORD "poketenashi"

// Network
#define WWW_PORT 80
#define WS_PORT 81

// I/O
#define DI_pin 12
#define DCK_pin 14

// Web server
ESP8266WebServer www_server(WWW_PORT);
WebSocketsServer ws_server = WebSocketsServer(WS_PORT);

// Commands sent through Web Socket
const char VACANT[] = "vacant";
const char OCCUPIED[] = "occupied";

// Toilet occupancy variable
// -1: unknown, 0: vacant, 1: occupied
int toilet_occupied = -1; 

#define TOILET_COUNT 255
int toilets_occupany[TOILET_COUNT];

void setup() {

  // Mandatory initial delay
  delay(10);

  // Serial init
  Serial.begin(115200);
  Serial.println();
  Serial.println(); // Separate serial stream from initial gibberish
  Serial.println(F(__FILE__ " " __DATE__ " " __TIME__)); // Print the sketch information

  init_array();
  LED_setup();
  wifi_setup();
  web_server_setup();
  websocket_setup();
  
  LED_set(0,0,255,0,0); // Turn the light blue by default
}

void loop() {
  www_server.handleClient();
  ws_server.loop();
}
