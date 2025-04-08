#pragma once
#include <Arduino.h>
extern String mqttClientId;
void setupMQTT();
void mqttConnect();
void loopMQTT();
String getClientId();
void mqttPublish(char *topic, const String &payload);
