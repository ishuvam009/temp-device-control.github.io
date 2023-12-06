#define BLYNK_TEMPLATE_ID "TMPL3wgw2k6Ev"
#define BLYNK_TEMPLATE_NAME "Switch"
#define BLYNK_AUTH_TOKEN "Znq0DTC_I0tpSvIECajrsjOc_pTQr27K"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN 14 // DHT11 sensor pin D5

#define DHTTYPE DHT11 // DHT11 sensor type
DHT dht(DHTPIN, DHTTYPE);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "S21FE";
char pass[] = "Shuv@2802";

void setup()
{
 Serial.begin(9600);
 dht.begin();
 Blynk.begin(auth, ssid, pass);
}

void loop()
{
 Blynk.run();
 float temp = dht.readTemperature();
 float hum = dht.readHumidity();
 if (isnan(temp) || isnan(hum)) {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }

Blynk.virtualWrite(V0, temp);
 Blynk.virtualWrite(V5, hum);
 delay(2000);
}