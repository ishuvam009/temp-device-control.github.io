// wifi controlled home automation using Blynk App & ESP8266
#define BLYNK_TEMPLATE_ID "TMPL3wgw2k6Ev"
#define BLYNK_TEMPLATE_NAME "Switch"
#define BLYNK_AUTH_TOKEN "Znq0DTC_I0tpSvIECajrsjOc_pTQr27K"

#define BLYNK_PRINT Serial
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = BLYNK_AUTH_TOKEN;
 
char ssid[] = "S21FE"; // Your Wifi Name
char pass[] = "Shuv@2802"; // Your Wifi Password
 
//in the below code, we have set all values reverse
//For value==1, digitalWrite is "LOW" as the realy module is active "LOW" to turn device ON.
//For value==0, digitalWrite is "HIGH" as Optocoupler based relay is turned OFF when HIGH Input is given
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D1, LOW); 
    Serial.println("LED ON"); //Setting Digital PIN as LOW to turn ON Device if relay module is "active low"
  }
  if(value == 0)
  {
     digitalWrite(D1, HIGH);
     Serial.println("LED OFF");//Setting Digital PIN as HIGH to turn OFF Device if relay module is "active low"
  }
}
 
BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D2, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D2, HIGH);  
     Serial.println("LED OFF");
  }
}
 
BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D3, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D3, HIGH);
     Serial.println("LED OFF");
  }
}
 
BLYNK_WRITE(V4)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D4, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D4, HIGH);
     Serial.println("LED OFF");
  }
}
 
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D1,OUTPUT); //GPIO 16 (equivalent to PIN 16 of Arduino)
  pinMode(D2,OUTPUT); //GPIO 05 (equivalent to PIN 05 of Arduino)
  pinMode(D3,OUTPUT);//GPIO 04 (equivalent to PIN 16 of Arduino)
  pinMode(D4,OUTPUT);//GPIO 00 (equivalent to PIN 00 of Arduino)
}
 
void loop()
{
  Blynk.run();
}