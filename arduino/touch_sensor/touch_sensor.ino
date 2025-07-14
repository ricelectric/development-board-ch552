#include <TouchKey.h>

#define LED_BUILTIN 15 //P1.5


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  TouchKey_begin(1 << 2); //enable TIN2 on P1.4
}

void loop() {
  TouchKey_Process();

  uint8_t result = TouchKey_Get();
  if (result & (1 << 2)) {
    USBSerial_println("Touched");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    USBSerial_println("Released");
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(10);
}
