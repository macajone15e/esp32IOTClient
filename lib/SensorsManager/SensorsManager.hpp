#pragma once
#include <Arduino.h>

// Var to write it in the JSON
extern float temperature, altitude, pressure;

// Var to publish when the state of the sensor change 
extern bool isSensorsChange;

// Function to setup the sensors
void setupSensors();

// Function to get the data of the sensors and said if the temp value change
void loopSensors();
