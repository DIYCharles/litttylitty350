#include <Adafruit_NeoPixel.h>

#define BUTTON1   2
#define BUTTON2   3
#define BUTTON3   4
#define PIXEL_PIN    6
#define PIXEL_COUNT 80
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
bool oldState1 = HIGH;
bool oldState2 = HIGH;
int showType = 0;
int showSet = 0;
int x;
int y;
void setup() {
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  bool newState1 = digitalRead(BUTTON1);
  if (newState1 == LOW && oldState1 == HIGH) {
    delay(20);
    newState1 = digitalRead(BUTTON1);
    if (newState1 == LOW) {
      showType++;
      if (showType > 2)
        showType = 0;
      startShow(showType);
    }
  }
  oldState1 = newState1;

  bool newState2 = digitalRead(BUTTON2);
  if (newState2 == LOW && oldState1 == HIGH) {
    delay(20);
    newState2 = digitalRead(BUTTON2);
    if (newState2 == LOW) {
      showSet++;
      if (showSet > 8)
        showSet = 0;
      startShow(showType);
    }
  }
  oldState2 = newState2;
}


void startShow(int showType)
{ bool y = 3;
  switch (showType) {
    case 0: color();
      break;
    case 1: rainbowCycle();
      break;
  }
}

void color(int showSet)
{
  bool newState2 = digitalRead(BUTTON2);
  if (newState2 == LOW && oldState1 == HIGH) {
    delay(20);
    newState2 = digitalRead(BUTTON2);
    if (newState2 == LOW) {
      showSet++;
      if (showSet > 8)
        showSet = 0;
      color(showSet);
    }
  }
  oldState2 = newState2;
}

  switch (showSet) {
    case 0: solid(strip.Color(255, 0, 0));  //red
      break;
    case 1: solid(strip.Color(255, 255, 0));  // yellow
      break;
    case 2: solid(strip.Color(0, 255, 0));  // lime
      break;
    case 3: solid(strip.Color(0, 255, 255));  // cyan
      break;
    case 4: solid(strip.Color(0, 0, 255));  // blue
      break;
    case 5: solid(strip.Color(255, 0, 255));  //magenta
      break;
    case 6: solid(strip.Color(255, 255, 255));  //white
      break;
  }
}

void rainbowCycle(int showSet)
{
  switch (showSet) {
    case 0: rainBow( 20);
            break;
    case 1: rainBow( 40);
            break; 

  }
}

void solid(uint32_t c)
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    color(showSet)
}
void rainBow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 5 * 256; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
    rainbowCycle(showSet);
  }
}
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
