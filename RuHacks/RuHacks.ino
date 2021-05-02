#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>
#define FIREBASE_HOST "PRIVATE"
#define FIREBASE_AUTH "PRIVATE"
#define WIFI_SSID "PRIVATE"
#define WIFI_PASSWORD "PRIVATE"
#define gas_sensor A0
#define sensorPin D4
#define DHTPIN D2                                           // Digital pin connected to DHT11
#define DHTTYPE DHT11  // Initialize dht type as DHT 11
DHT dht(DHTPIN, DHTTYPE);
const int ldrPin = D5;
int sensorThres = 400;
int sensorState = 0;
int lastState = 0;
void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  pinMode(gas_sensor, INPUT);
  pinMode(DHTPIN, INPUT);
  pinMode(ldrPin, INPUT);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Serial.println("Reading From the Sensor ...");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("user/1/A_IP_Address", "192.168.43.210");
}



void loop() {
  int analogSensor = analogRead(gas_sensor);
  int ldrStatus = digitalRead(ldrPin);
  dht.begin();
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t))                                     // Checking sensor working
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  String fireHumid = String(h) + String("%");                   //Humidity integer to string conversion
Firebase.setString("user/1/Humidity",fireHumid );
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("°C ");
  String fireTemp = String(t) + String("°C");
  Firebase.setString("user/1/Temperature", fireTemp);

  //moisture
  sensorState = digitalRead(sensorPin);
  if (sensorState == 1 && lastState == 0) {
    Serial.println("Moisture level Low");
    Firebase.setString("user/1/Soil_Moisture", "Low!!");
    lastState = 1;
    delay(1000);


  }
  else if (sensorState == 1 && lastState == 1) {
    //do nothing, has not been watered yet
    Serial.println("Moisture level Low");
    delay(1000);
  }
  else {
    //st
    Serial.println("Moisture is Sufficient");
    Firebase.setString("user/1/Soil_Moisture", "Sufficient!!");
    lastState = 0;
    delay(1000);
  }

 

  //gas sensor
  if (analogSensor > sensorThres)
  {
    Serial.println("Carbon level : 2");
    Firebase.setString("user/1/Carbon_level", "High");
  }
  else
  {Serial.println("Carbon level : 1");
    Serial.println("Air is Clean!");
    Firebase.setString("user/1/Carbon_level", "Low");
  }
  // ldr
  if (ldrStatus==LOW){
    Serial.println("Sufficient Light is available");
    Firebase.setString("user/1/Light", "Sufficient");
    }
   else{
    Serial.println("No Light is Available");
    Firebase.setString("user/1/Light", "Low");
    }
    
  Serial.println("FireBase Database Updated Successfully!");
  Serial.println();
  delay(5000);


}
