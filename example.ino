#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define lamp   4  // GPIO_4

bool state = false;

ESP8266WebServer server(80);

void toggle() {
  Serial.println("toggle");
  state = !state;
  digitalWrite(lamp, state);
  server.send(200, "text/plain", "ok");
}

void setup() {
  pinMode(lamp, OUTPUT);
  WiFi.softAP("ESP8266_AP");
  Serial.begin(115200);
  Serial.println("ready");
  server.on("/toggle", toggle);
  server.begin();
}

void loop() {
  server.handleClient();
}
