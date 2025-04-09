#include <Arduino.h>
#include <WiFiManagerHelper.hpp>
#include <NTPManager.hpp>
#include <MQTTManager.hpp>
#include <SensorsManager.hpp>
#include <JsonManager.hpp>

void setup() {
  Serial.begin(115200);
  setupWiFi();
  setupNTP();
  setupMQTT();
  setupSensors();
}

void loop() {
  loopWiFi();
  loopNTP();
  loopMQTT();
  loopSensors();

  if(isSensorsChange){
    mqttPublish("Sensors", generateJson(getClientId(), getTimestamp(), temperature, altitude, pressure));
    isSensorsChange = false;
  }
}
