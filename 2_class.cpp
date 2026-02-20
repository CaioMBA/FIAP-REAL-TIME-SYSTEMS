#include <Arduino.h>

static const int LED_PIN = 2;
static bool led = false;
static unsigned long last = 0;
static unsigned long last_print = 0;

void blink_led(){
  unsigned long now = millis();

  unsigned int diff = now - last;
  if (diff >= 500){
    digitalWrite(LED_PIN, !led);
    led = !led;
    last = now;
    Serial.printf("led has blinked %lu ms\n", diff);
  }
}

void process_anything()
{
  unsigned long temp0 = micros();
  for(volatile long i = 0; i < 5000; i++){}
  unsigned long temp1 = micros();
  if (millis() - last_print >= 2000){
    Serial.printf("delta = %lu us\n", (temp1 - temp0));
    last_print = millis();
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  blink_led();
  process_anything();
}
