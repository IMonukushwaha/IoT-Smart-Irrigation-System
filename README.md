# IoT-Smart-Irrigation-System


An IoT-based automatic plant watering system using:

.a.) Soil moisture sensor for detecting soil dryness

b.) DHT11 for humidity & temperature

c.) MOSFET + Relay module to control water pump

d.) NodeMCU (ESP8266) + Blynk App for remote monitoring & control

# Features
a.) Automatically turns ON pump if soil is dry

b.) Sends live data to Blynk app (soil moisture, temperature, humidity, pump status)

c.) Visual LED indicator on NodeMCU for pump status

d.) Manual override possible via Blynk app (by adding a virtual switch control on V3)

# Wiring Details

NodeMCU Connections

NodeMCU Pin	Connected To
A0->	Soil Moisture Sensor Analog Out,
D4-> (GPIO4)	DHT11 Data Pin,
D1-> (GPIO5)	MOSFET Gate (controls Relay),
Gnd->	GND (common ground),
3V3->	DHT11 VCC,
3V3->	Soil Moisture VCC,

MOSFET + Relay + Pump

D1 (GPIO5) controls MOSFET gate.

MOSFET drives Relay IN, which switches the pump’s power supply.

Relay module is powered by external 5V/12V, depending on pump voltage.

This ensures NodeMCU only controls low current via MOSFET, and actual pump load is handled by Relay.

Built-in LED-: LED_BUILTIN (GPIO2) on NodeMCU turns ON when pump is running.

# Blynk Setup

Template ID: TMPL5A4YPYiWc

Template Name: IOTPROJECT

Auth Token: (Use your -RCSqnRfLcstkPP9-S6-Aw1mZ46yjjiG)

Virtual Pins used -> Virtual Pin	Function

V0->	Soil Moisture (%)

V1->	Temperature (°C)

V2->	Humidity (%)

V3->	Pump Status (0 = OFF, 1 = ON)

# How to Run

1️⃣ Install libraries in Arduino IDE

ESP8266WiFi

BlynkSimpleEsp8266

DHT

2️⃣ Upload code

Update your WiFi SSID & password:

char ssid[] = "node";

char pass[] = "12345678";

Use your Blynk AUTH TOKEN.

3️⃣ Power it up

Plug NodeMCU into USB or 5V adapter.

Power pump circuit from separate supply if needed.

![Screenshot (233)](https://github.com/user-attachments/assets/3a8b1652-76a3-423c-ae18-a699b546832a)

when soil moisture sensor is not in soil

![Screenshot (235)](https://github.com/user-attachments/assets/a601016a-ff07-4fe0-9051-f79d4173986e)

When soil moisture sensor is in moist soil

![Screenshot (234)](https://github.com/user-attachments/assets/8c89a864-9473-4083-8c33-aa4acdbe1e0a)

