#pragma once
#include <Arduino.h>

// Function to setup the wifi part if wifi isn't connected it create the network to link a wifi network
void setupWiFi();

// Function to loop the wifi process
void loopWiFi();

// Function to get the ESP32 Mac Adress
String getMacAddress();
