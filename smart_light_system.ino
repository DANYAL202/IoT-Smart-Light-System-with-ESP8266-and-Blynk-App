#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";  // Auth Token from Blynk app
char ssid[] = "YourWiFiSSID";   // WiFi SSID
char pass[] = "YourWiFiPassword";  // WiFi Password

void setup() {
  Serial.begin(115200);  // Start serial communication
  Blynk.begin(auth, ssid, pass);  // Connect to Blynk server

  pinMode(LED_BUILTIN, OUTPUT);  // Set the LED pin as output
}

void loop() {
  Blynk.run();  // Run Blynk virtual pins
}

// Define a virtual pin for controlling the LED
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();  // Get the virtual pin value
  digitalWrite(LED_BUILTIN, pinValue);  // Turn the LED on/off
}
