#include <Adafruit_NeoPixel.h>
#define bkbutton   13
#define wbutton   12
#define rbutton   9
#define blbutton   10
#define gbutton   11
#define PIXEL_PIN    8    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 72

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
int r;
int g;
int b;

void setup() {
  pinMode(wbutton, INPUT_PULLUP);
  pinMode(bkbutton, INPUT_PULLUP);
  pinMode(rbutton, INPUT_PULLUP);
  pinMode(blbutton, INPUT_PULLUP);
  pinMode(gbutton, INPUT_PULLUP);
  strip.begin();
  strip.show();
  delay(300); // Initialize all pixels to 'off'
}

void loop()
{
  bool newStateblack = digitalRead(bkbutton);
  if (newStateblack == LOW && oldStateblack == HIGH)
  { delay(20);
    newStateblack = digitalRead(bkbutton);
    if (newStateblack == LOW) {
      pwer = 0;
      
      
      
    }
  } oldStateblack = newStateblack;
  
  bool newStatewhite = digitalRead(wbutton);
  if (newStatewhite == LOW && oldStatewhite == HIGH)
  { delay(20);
    newStatewhite = digitalRead(wbutton);
    if (newStatewhite == LOW) {
      pwer = 1;
   
    }
  } oldStatewhite = newStatewhite;
  
  bool newStatered = digitalRead(rbutton);
  if (newStatered == LOW && oldStatered == HIGH) {
    delay(20);
    newStatered = digitalRead(rbutton);
    if (newStatered == LOW) {
      showType++;
      showSet1 = 0;
      showSet2 = 0;
      if (showType > 2) {
        showType = 0;
      }
      startShow(showType);
    }
  }
  oldStatered = newStatered;
  
  bool newStateblue = digitalRead(blbutton);
  if (newStateblue == LOW && oldStateblue == HIGH) {
    delay(20);
    newStateblue = digitalRead(blbutton);
    if (newStateblue == LOW) {
      showSet1++;
      showSet2 = 0;
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
  
  switch (pwer) {
    case 0: colorWipe(strip.Color(0, 0, 0), 0);
      break;
    case 1: startShow(showType);  
      break;
  }
} //end of looooooopppps

//void POWER(int pwer) {
//  switch (pwer) {
  //  case 0: colorWipe(strip.Color(0, 0, 0), 0);
    //  break;
 //   case 1: startShow(showType);  
//      break;
//  }
//}

void startShow(int showType) {
  switch (showType) {
    case 0: singlecolor(showSet1);
      break;
    case 1: colorWiper(showSet1, showSet2);
      break;
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


void singlecolor(int showSet1) {
  s1n=5;
  switch(showSet1){
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



void colorWiper (int showSet1, int showSet2) {
  s1n=3;
  switch(showSet1){
    case 0: colorWipea(showSet2);
    break; 
    case 1: colorWipeb(showSet2);
    break;
    case 2: rainbowCycle(20);
    break;
   // case 2: colorWipec(showSet2); 
   // break;
  }
}

void colorWipea(int showSet2) {
  int colors;
  int numcolors=29;
  if (colors > numcolors) {
    colors = 0; }
 switch (colors) {
    case 0: colorWipet(strip.Color(255, 50, 0), showSet2); 
    case 1: colorWipet(strip.Color(255, 100, 0), showSet2);
    case 2: colorWipet(strip.Color(255, 150, 0), showSet2); 
    case 3: colorWipet(strip.Color(255, 200, 0), showSet2);  
    case 4: colorWipet(strip.Color(255, 255, 0), showSet2); 
    case 5: colorWipet(strip.Color(200, 255, 0), showSet2); 
    case 6: colorWipet(strip.Color(150, 255, 0), showSet2); 
    case 7: colorWipet(strip.Color(100, 255, 0), showSet2); 
    case 8: colorWipet(strip.Color(50, 255, 0), showSet2); 
    case 9: colorWipet(strip.Color(0, 255, 0), showSet2);  
    case 10: colorWipet(strip.Color(0, 255, 50), showSet2);  
    case 11: colorWipet(strip.Color(0, 255, 100), showSet2); 
    case 12: colorWipet(strip.Color(0, 255, 150), showSet2); 
    case 13: colorWipet(strip.Color(0, 255, 200), showSet2); 
    case 14: colorWipet(strip.Color(0, 255, 255), showSet2); 
    case 15: colorWipet(strip.Color(0, 200, 255), showSet2); 
    case 16: colorWipet(strip.Color(0, 150, 255), showSet2); 
    case 17: colorWipet(strip.Color(0, 100, 255), showSet2); 
    case 18: colorWipet(strip.Color(0, 50, 255), showSet2); 
    case 19: colorWipet(strip.Color(0, 0, 255), showSet2); 
    case 20: colorWipet(strip.Color(50, 0, 255), showSet2); 
    case 21: colorWipet(strip.Color(100, 0, 255), showSet2); 
    case 22: colorWipet(strip.Color(150, 0, 255), showSet2); 
    case 23: colorWipet(strip.Color(200, 0, 255), showSet2); 
    case 24: colorWipet(strip.Color(255, 0, 255), showSet2); 
    case 25: colorWipet(strip.Color(255, 0, 200), showSet2); 
    case 26: colorWipet(strip.Color(255, 0, 150), showSet2); 
    case 27: colorWipet(strip.Color(255, 0, 100), showSet2); 
    case 28: colorWipet(strip.Color(255, 0, 50), showSet2); 
    case 29: colorWipet(strip.Color(255, 0, 0), showSet2); 
 } 
 }
void colorWipeb(int showSet2) {
  int colorb;
  int numcolorb=17;
  if (colorb > numcolorb) {
    colorb = 0; }
 switch (colorb) {
    case 0: colorWipet(strip.Color(255, 100, 100), showSet2); 
    case 1: colorWipet(strip.Color(255, 150, 100), showSet2);
    case 2: colorWipet(strip.Color(255, 200, 100), showSet2); 
    case 3: colorWipet(strip.Color(255, 255, 100), showSet2);
    case 4: colorWipet(strip.Color(200, 255, 100), showSet2);
    case 5: colorWipet(strip.Color(150, 255, 100), showSet2);
    case 6: colorWipet(strip.Color(100, 255, 100), showSet2);
    case 7: colorWipet(strip.Color(100, 255, 150), showSet2);
    case 8: colorWipet(strip.Color(100, 255, 200), showSet2);
    case 9: colorWipet(strip.Color(100, 255, 255), showSet2);
    case 10: colorWipet(strip.Color(100, 200, 255), showSet2);
    case 11: colorWipet(strip.Color(100, 150, 255), showSet2);
    case 12: colorWipet(strip.Color(100, 100, 255), showSet2);
    case 13: colorWipet(strip.Color(150, 100, 255), showSet2);
    case 14: colorWipet(strip.Color(200, 100, 255), showSet2);
    case 15: colorWipet(strip.Color(255, 100, 255), showSet2);
    case 16: colorWipet(strip.Color(255, 100, 200), showSet2);
    case 17: colorWipet(strip.Color(255, 100, 150), showSet2);
 }
}  
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

void colorWipet(uint32_t c, int showSet2) 
{
   bool newStatered = digitalRead(rbutton);
  if (newStatered == LOW && oldStatered == HIGH) {
    delay(20);
    newStatered = digitalRead(rbutton);
    if (newStatered == LOW) {
      showType++;
      showSet1 = 0;
      showSet2 = 0;
      if (showType > 2) {
        showType = 0;
      }
      startShow(showType);
    }
  }
  oldStatered = newStatered;
  s2n=7;
  int t;
  switch(showSet2){
    case 0: t=0 ; 
            break;
    case 1: t=10 ; 
            break;
    case 2: t=20 ; 
            break;
    case 3: t=30 ; 
            break;
    case 4: t=40 ; 
            break;
    case 5: t=50 ; 
            break;
    case 6: t=60 ; 
            break;
    case 7: t=70 ; 
            break;
  }
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(t);
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
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
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
