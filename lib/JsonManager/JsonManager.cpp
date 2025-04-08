#include "JsonManager.hpp"
#include <Arduino.h>
#include <ArduinoJson.h>

StaticJsonDocument<512> doc;

String generateJson(String id, String timestamp, float temperature, float altitude, float pressure) {
  doc["id"] = id;
  doc["timestamp"] = timestamp;
  doc["temperature"] = temperature;
  doc["altitude"] = altitude;
  doc["pressure"] = pressure;
  String jsonString;
  serializeJson(doc, jsonString);
  return jsonString;
}
