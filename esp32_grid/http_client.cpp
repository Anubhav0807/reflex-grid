#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

#include "secrets.h"
#include "comm.h"

WiFiClientSecure wifiClient;

void httpInit() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Wait for connection
  sendMessage("Connecting...\n\n");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  sendMessage("Connected\nto WiFi\n");
  wifiClient.setInsecure();
}

String httpGet(const String& path) {
  if (WiFi.status() != WL_CONNECTED) return "";

  HTTPClient httpClient;
  String payload = "";

  if (httpClient.begin(wifiClient, BACKEND_URL + path)) {
    int httpCode = httpClient.GET();

    if (httpCode > 0) {
      payload = httpClient.getString();
    }

    httpClient.end();
  }

  return payload;
}

String httpPost(const String& path, const String& body) {
  if (WiFi.status() != WL_CONNECTED) return "";

  HTTPClient httpClient;
  String payload = "";

  if (httpClient.begin(wifiClient, BACKEND_URL + path)) {
    httpClient.addHeader("Content-Type", "application/json");
    int httpCode = httpClient.POST(body);

    if (httpCode > 0) {
      payload = httpClient.getString();
    }

    httpClient.end();
  }

  return payload;
}