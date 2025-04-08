#include <Arduino.h>
#include "SensorsManager.hpp"
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;
float temperature, pressure, altitude;
float oldTemp = 0;
bool isSensorsChange = false;
unsigned long lastSend;
#define tempTolerance 0.1
#define heartBeatTemp 60

void setupSensors() {
  if (!bmp.begin(0x76)) {
    Serial.println("BMP280 sensor not found!");
    while (1) delay(10);
  }
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);
}

void loopSensors() {
  temperature = bmp.readTemperature();
  pressure = bmp.readPressure();
  altitude = bmp.readAltitude(1015);

  if((oldTemp + tempTolerance <= temperature || oldTemp - tempTolerance >= temperature) || millis() - lastSend > heartBeatTemp * 1000) {
    oldTemp = temperature;
    lastSend = millis();
    isSensorsChange = true;
  }
}
