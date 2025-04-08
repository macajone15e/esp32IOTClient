#include "config.hpp"
#include "MQTTManager.hpp"
#include "WiFiManagerHelper.hpp"
#include <PubSubClient.h>
#include <WiFi.h>

WiFiClient espClient;
PubSubClient mqtt(espClient);
String mqttClientId = "";


void setupMQTT()
{
  Serial.println("MQTT: server=" + mqttServer);
  mqtt.setServer(mqttServer.c_str(), mqttPort);
  mqttClientId = "ESP32-" + getMacAddress();
  Serial.println("MQTT: clientID=" + mqttClientId);
}

void mqttConnect()
{
  if (mqtt.connected())
    return;
  while (!mqtt.connected())
  {
    Serial.println("MQTT: attempting connection");
    if (mqtt.connect(mqttClientId.c_str(), mqttUser.c_str(), mqttPassword.c_str()))
    {
      Serial.println("MQTT: connected!");
      mqtt.publish("outTopic", ("Hello from " + mqttClientId).c_str());
    }
    else
    {
      Serial.print("MQTT: failed, rc=");
      Serial.print(mqtt.state());
      Serial.println(". Try again in 5 seconds");
      delay(5000);
    }
  }
}

void loopMQTT()
{
  if (!mqtt.connected())
    mqttConnect();
  mqtt.loop();
}

String getClientId()
{
  return mqttClientId;
}

void mqttPublish(char* topic, const String &payload)
{
  mqtt.publish(topic, payload.c_str());
}
