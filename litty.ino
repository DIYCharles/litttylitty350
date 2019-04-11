#include <Adafruit_NeoPixel.h>
#define bkbutton   2
#define wbutton   3
#define rbutton   4
#define blbutton   5
#define gbutton   7
#define PIXEL_PIN    6    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 80

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
bool oldStateblack = HIGH;
bool oldStatewhite = HIGH;
bool oldStatered = HIGH;
bool oldStateblue = HIGH;
bool oldStategreen = HIGH;
int pwer = 0;
int showType = 0;
int showSet1 = 0;
int s1n;
int showSet2 = 0;
int s2n;

void setup() {
  pinMode(wbutton, INPUT_PULLUP);
  pinMode(bkbutton, INPUT_PULLUP);
  pinMode(rbutton, INPUT_PULLUP);
  pinMode(blbutton, INPUT_PULLUP);
  pinMode(gbutton, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  bool newStateblack = digitalRead(bkbutton);
  if (newStateblack == LOW && oldStateblack == HIGH)
  { delay(5);
    newStateblack = digitalRead(bkbutton);
    if (newStateblack == LOW) {
      pwer = 0;
      
    }
  } oldStateblack = newStateblack;
  
  bool newStatewhite = digitalRead(wbutton);
  if (newStatewhite == LOW && oldStatewhite == HIGH)
  { delay(5);
    newStatewhite = digitalRead(wbutton);
    if (newStatewhite == LOW) {
      pwer = 1;
    }
  } oldStatewhite = newStatewhite;
  
  bool newStatered = digitalRead(rbutton);
  if (newStatered == LOW && oldStatered == HIGH) {
    delay(5);
    newStatered = digitalRead(rbutton);
    if (newStatered == LOW) {
      showType++;
      if (showType > 9) {
        showType = 0;
      }
    }
  }
  oldStatered = newStatered;
  
  bool newStateblue = digitalRead(blbutton);
  if (newStateblue == LOW && oldStateblue == HIGH) {
    delay(5);
    newStateblue = digitalRead(blbutton);
    if (newStateblue == LOW) {
      showSet1++;
      if (showSet1 > s1n) {
        showSet1 = 0;
      }
    }
  }
  oldStateblue = newStateblue;

  bool newStategreen = digitalRead(gbutton);
  if (newStategreen == LOW && oldStategreen == HIGH) {
    delay(20);
    newStategreen = digitalRead(gbutton);
    if (newStategreen == LOW) {
      showSet2++;
      if (showSet2 > s2n) {
        showSet2 = 0;
      }
    }
  }
  oldStategreen = newStategreen;
POWER(pwer);
} //end of looooooopppps

void POWER(int pwer) {
  switch (pwer) {
    case 0: colorWipe(strip.Color(0, 0, 0), 50);
      break;
    case 1: startShow(showType);  // Red
      break;
  }
}

void startShow(int showType) {
  switch (showType) {
    case 0: singlecolor(showSet1);
      break;
    //case 1: colorWiper(showSet1);  // Red
      //break;
   // case 2: rainbowCycler(showSet1);
      //break;
      //case 3: colorchange();
      //break;
      // case 4: rainbow();
      // break;
      // case 5: rainbowCycle();
      //       break;
      //case 6: theaterChaseRainbow();
  }
}


void singlecolor(int i) {
  s1n=5;
  switch(i){
    case 0: colorWipe(strip.Color(255, 0, 0), 0); 
            break;
    case 1: colorWipe(strip.Color(255, 255, 0), 0);
            break;
    case 2: colorWipe(strip.Color(0, 255, 0), 0); 
            break;
    case 3: colorWipe(strip.Color(0, 255, 255), 0);  
            break;
    case 4: colorWipe(strip.Color(0, 0, 255), 0); 
            break;
    case 5: colorWipe(strip.Color(255, 0, 225), 0); 
            break;
 
  }
}

//void colorWiper (int i) {
  //s1n=0;
//}


//void rainbowCycler (int i) {
  //s1n=0;
//}

void colorWipe(uint32_t c, uint8_t wait) 
{
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
