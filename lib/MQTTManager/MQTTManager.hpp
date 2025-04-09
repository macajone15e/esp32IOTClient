#pragma once
#include <Arduino.h>

// ID of the ESP used in the MQTTpublish
extern String mqttClientId;

// Setup function
void setupMQTT();

// Function to connect the ESP32 at the MQTT Broker 
void mqttConnect();

// Function to Run MQTT
void loopMQTT();

//Function to get the mqttClientID
String getClientId();

// Function to publish a message
// Parameters:
//   - topic : topic to publish
//   - payload : JSON 
void mqttPublish(char *topic, const String &payload);
