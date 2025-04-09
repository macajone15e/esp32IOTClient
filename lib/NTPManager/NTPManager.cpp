#include <Arduino.h>
#include "NTPManager.hpp"
#include <WiFiUdp.h>
#include <WiFiManager.h>

#define NTP_SERVER_EU "europe.pool.ntp.org"
#define NTP_REFRESH 3 * 60 * 60
#define NTP_SYNC_TIMEOUT 60

WiFiUDP ntpUDP;
Timezone timeZone;
bool ntpOk = false;

void setupNTP()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("/!\ NTP: No WiFi");
    return;
  }
  setDebug(INFO);
  setServer(NTP_SERVER_EU);
  setInterval(NTP_REFRESH);
  waitForSync(NTP_SYNC_TIMEOUT);
  timeZone.setLocation("Europe/Paris");
  Serial.println("UTC:" + UTC.dateTime());
  Serial.println("Local time: " + timeZone.dateTime());
  ntpOk = true;
}

void loopNTP()
{
  if (!ntpOk)
  {
    setupNTP();
    if (!ntpOk)
      return;
  }
  events();
}

String getTimestamp()
{
  return timeZone.dateTime("YmdHis");
}