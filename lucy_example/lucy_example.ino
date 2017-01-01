#include <Mouse.h>

#define FIRST_SEGMENT_PIN   2
#define SEGMENT_COUNT       8
// Global Variables

byte name[6] = {
  0b10000011,//L
  0b10010111,//U
  0b10100011,//C
  0b011010110,//Y
  0b000000000,
  0b000000000
};

void setup() {
  for (int i = 0; i < SEGMENT_COUNT; ++i)
    pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
}
void loop()
{
  for(int j = 0; j < 6; j++)
  {
    for (int i = 0; i < SEGMENT_COUNT; ++i) {
      boolean enableSegment = bitRead(name[j], i);
      // включаем/выключаем сегмент на основе полученного значения
      digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
    }
    delay(500);
  }
}

/*
void Blink(int red, int green, int blue)
{
  digitalWrite(LED_PIN_RED, red);  
  digitalWrite(LED_PIN_GREEN, green);
  digitalWrite(LED_PIN_BLUE, blue);
  delay(300);
}
*/
