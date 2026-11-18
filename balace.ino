#include <KiwisIoT.h>

// ===== WIFI =====
const char* ssid  = "prakatheesh";
const char* pass  = "123456789";
const char* topic = "dash_1791367866871";

KiwisIoT kiwisiot(ssid, pass, topic);

// ===== LED =====
#define LED_PIN D2

void onControl(String ch, String val) {

  // Only Channel 0
  if (ch != "0") return;

  Serial.print("Channel: ");
  Serial.println(ch);

  Serial.print("Value: ");
  Serial.println(val);

  // Value 0 = LED OFF
  if (val == "0") {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
  }

  // Any other value = LED ON
  else {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT LED Control Started");
}

void loop() {
  kiwisiot.run();
}
