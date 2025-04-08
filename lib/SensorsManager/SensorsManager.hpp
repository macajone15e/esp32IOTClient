#pragma once
#include <Arduino.h>
extern float temperature, altitude, pressure;
extern bool isSensorsChange;
void setupSensors();
void loopSensors();
