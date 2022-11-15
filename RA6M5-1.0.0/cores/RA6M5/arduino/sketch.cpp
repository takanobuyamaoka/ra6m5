#include <Arduino.h>

BSP_WEAK_REFERENCE void setup() {
	pinMode(PIN_LED_G, OUTPUT);

	Serial.begin(115200);
	Serial.println("Hello");
}

BSP_WEAK_REFERENCE void loop() {
	static bool led = true;

	digitalWrite(PIN_LED_G, led);
	led = !led;

	delay(500);
}
