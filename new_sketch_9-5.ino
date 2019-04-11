#include <Adafruit_NeoPixel.h>
#define blackbutton   2 
#define whitebutton   3
#define redbutton   4
#define bluebutton   5 
#define greenbutton   7 
#define PIXEL_PIN    6    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 80

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
bool oldStateblack = HIGH;
bool oldStatewhite = HIGH;
bool oldStatered = HIGH;
bool oldStateblue = HIGH;
bool oldStategreen = HIGH;
int red = 0;
int showset = 0;
int showset2 = 0;

void setup() {
  pinMode(whitebutton, INPUT_PULLUP);
  pinMode(blackbutton, INPUT_PULLUP);
  pinMode(redbutton, INPUT_PULLUP);
  pinMode(bluebutton, INPUT_PULLUP);
  pinMode(greenbutton, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() 
{
  bool newStateblack = digitalRead(blackbutton);
  if (newStateblack == LOW && oldStateblack == HIGH)
  { delay(20);
    newStateblack = digitalRead(blackbutton);
    if (newStateblack == LOW) {
      strip.begin();
      strip.show();
    } } oldStateblack = newStateblack;
  bool newStatewhite = digitalRead(whitebutton);    
  if (newStatewhite == LOW && oldStatewhite == HIGH)
  { delay(20);
    newStatewhite = digitalRead(whitebutton);
    if (newStatewhite == LOW) {
      startShow(red);
    } } oldStatewhite = newStatewhite;
   bool newStatered = digitalRead(redbutton);
        if (newStatered == LOW && oldStatered == HIGH) {
          delay(20);
          newStatered = digitalRead(redbutton);
            if (newStatered == LOW) {
              red++;
               if (red > 9) {
                   red=0; } } }
      oldStatered = newStatered; 
  bool newStategreen = digitalRead(greenbutton);
  } //end of looooooopppps

void startShow(int red) {
  switch(red){
    case 0: singlecolor();
            break;
    //case 1: colorfill();
            //break;
    //case 2: colorwipe();
          //  break;
    //case 3: colorchange();
            //break;
   // case 4: rainbow();
           // break;
   // case 5: rainbowCycle();
     //       break;
    //case 6: theaterChaseRainbow();
            break;
  }
}

void singlecolor() {
 int blue=0;
  bool newStateblue = digitalRead(bluebutton);
  newStateblue = digitalRead(bluebutton);
        if (newStateblue == LOW && oldStateblue == HIGH) {
          delay(20);
          newStateblue = digitalRead(bluebutton);
            if (newStateblue == LOW) {
              blue++;
               if (blue > 9) {
                   blue=0; } } }
      newStateblue = newStateblue;
  
  switch(blue){
    case 0: for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, 255, 255, 255);
            strip.show();
            delay(0);
            break; }
    case 1: for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, 0, 255, 255);
            strip.show();
            delay(0);
            break; }
    case 2: for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, 0, 0, 255);
            strip.show();
            delay(0);
            break; }
    case 3: for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, 255, 0, 255);
            strip.show();
            delay(0);
            break; }
    case 4: for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, 255, 0, 0);
            strip.show();
            delay(0);
            break; }
    case 5: for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, 255, 255, 0);
            strip.show();
            delay(0);
            break; }
    case 6: for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, 0, 255, 0);
            strip.show();
            delay(0);
            break; }
    
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
  } }
