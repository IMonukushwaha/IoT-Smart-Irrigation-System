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
