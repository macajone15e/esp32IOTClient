/*
Software : ESP32 Client IOT Projeect
Objective : Send sensors data to MQTT broker
Developers :
    MACAJONE Enzo
    MARCELLIN Massimo
    MAZARS Baptiste
    DAMOUR Antoine
Architecture :
    |_src => main file
      |_ main.cpp => main file
    |_lib => classes dir
        |_Config
          |_Config.hpp => config class
          |_Config.cpp 
        |_MQTTManager
          |_MQTTManager.hpp => MQTT class
          |_MQTTManager.cpp
        |_NTPManager
          |_NTPManager.hpp => NTP class
          |_NTPManager.cpp
        |_SensorsManager
          |_SensorsManager.hpp => Sensors class
          |_SensorsManager.cpp
        |_JsonManager
          |_JsonManager.hpp => Json class
          |_JsonManager.cpp
Run program :
    Build and upload the code to ESP32 board
*/


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
