#include <Arduino.h>
#include "WiFiManagerHelper.hpp"
#include <WiFiManager.h>

WiFiManager wm;

void setupWiFi() {
  WiFi.mode(WIFI_STA);
  bool wifiOk = false;
  uint8_t count = 3;
  Serial.println("WiFi: try to connect");
  while (!wifiOk && count > 0) {
    if (wm.autoConnect("AutoConnectAP")) {
      Serial.println("WiFi: connected");
      wifiOk = true;
    } else {
      count--;
      if (count == 0)
        Serial.println("WiFi: configuration portal running");
    }
  }
}

void loopWiFi() {
  wm.process();
}

String getMacAddress() {
  String temp = WiFi.macAddress();
  temp.replace(":", "");
  return temp;
}
