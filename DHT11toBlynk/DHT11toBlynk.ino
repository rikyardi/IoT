#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

#define BLYNK_TEMPLATE_ID "TMPL6CEqDDTtg"
#define BLYNK_TEMPLATE_NAME "Temperature"
#define BLYNK_AUTH_TOKEN "EVFikNAxvUuDKjjFFds1iGXUwcEWIjEz"

#define BLYNK_PRINT Serial

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "Amran";
char pass[] = "rumahamran";

BlynkTimer timer;
void sensor(){
  float suhu = dht.readTemperature();
  float klmb = dht.readHumidity();

  Blynk.virtualWrite(V0, klmb);
  Blynk.virtualWrite(V1, suhu);
  
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
