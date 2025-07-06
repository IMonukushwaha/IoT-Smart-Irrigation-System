#define BLYNK_TEMPLATE_ID "TMPL5A4YPYiWc"
#define BLYNK_TEMPLATE_NAME "IOTPROJECT"
#define BLYNK_AUTH_TOKEN "-RCSqnRfLcstkPP9-S6-Aw1mZ46yjjiG"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "node";
char pass[] = "12345678";

BlynkTimer timer;

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define PUMP_PIN 5         // D1 = GPIO5
#define LED_BUILTIN_PIN 2  // Built-in LED for visual feedback

#define MOISTURE_THRESHOLD 30  // Below this value = pump ON

void sendSensor() {
  int rawValue = analogRead(A0);
  int moisture = map(rawValue, 400, 1023, 100, 0);

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  delay(10);

  if (isnan(humidity) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
  }
  if(isnan(moisture)){
    Serial.println("Failed to read from soil moisture sensor!");
  }
  // Send to Blynk
  Blynk.virtualWrite(V0, moisture);
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, humidity);

  Serial.println("---------- Sensor Readings ----------");
  Serial.print("Raw Moisture: ");
  Serial.println(rawValue);
  Serial.print("Mapped Moisture: "); 
  Serial.print(moisture); 
  Serial.println("%");
  // Serial.print("Temp: "); 
  // Serial.print(temp); 
  // Serial.print("°C, Humidity: "); 
  // Serial.print(humidity); 
  // Serial.println("%");

// Auto Pump Control
if (moisture < MOISTURE_THRESHOLD) {
  digitalWrite(PUMP_PIN, 1);           // Pump ON
  digitalWrite(LED_BUILTIN_PIN, LOW);     // LED ON (LOW = ON for built-inLED)
  Blynk.virtualWrite(V3, 1);              // Pump ON to Blynk
  Serial.println("Pump Status: ON (Soil too dry)");
}
else {
  digitalWrite(PUMP_PIN, 0);            // Pump OFF
  digitalWrite(LED_BUILTIN_PIN, HIGH);    // LED OFF
  Blynk.virtualWrite(V3, 0);              // Pump OFF to Blynk
  Serial.println("Pump Status: OFF (Soil is moist)");
  }
  Serial.println("-------------------------------------");
}

void setup() {
  Serial.begin(115200);

  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);  // Default OFF

  pinMode(LED_BUILTIN_PIN, OUTPUT);
  digitalWrite(LED_BUILTIN_PIN, HIGH);  // Default LED OFF

  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(5000L, sendSensor);  // Every 2 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}
