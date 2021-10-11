#include "Adafruit_HT1632.h"
#include <StopWatch.h>
#include <DS3231.h>
#include <Wire.h>


DS3231 clock;
bool h12Flag;
bool pmFlag;
bool century = false;


StopWatch MySW;
StopWatch SWarray[5];

#define HT_DATA 2
#define HT_WR   3
#define HT_CS   4
#define HT_CS2  5
float swmin;
float swmin1;
Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS, HT_CS2);

void setup() {
    Wire.begin();
    Serial.begin(115200);
    matrix.begin(ADA_HT1632_COMMON_16NMOS);
    matrix.fillScreen();
    delay(500);
    matrix.clearScreen();
    matrix.setBrightness(5);
    Serial.println("Stopwatch demo");
    Serial.print("Version: ");
    Serial.println(STOPWATCH_LIB_VERSION);
    SWarray[0].start();
}
  
void loop() {
    Serial.print(clock.getHour(h12Flag, pmFlag), DEC); //24-hr
    Serial.print(":");
    Serial.print(clock.getMinute(), DEC);
    Serial.print(":");
    Serial.println(clock.getSecond(), DEC);
    Serial.print(clock.getTemperature(), 2);
    Serial.print(clock.getMonth(century), DEC);
    Serial.print(clock.getDate(), DEC);

    int tempc = clock.getTemperature();
    int tempf = (tempc*1.8)+32;
    int hr = clock.getHour(h12Flag, pmFlag); //get the current hour in 24hr format
    int min = clock.getMinute(); 
    int sec = clock.getSecond(); 
    int day = clock.getDate();
    int month = clock.getMonth(century);
    matrix.clearScreen();
    matrix.setBrightness(1);
    matrix.setTextSize(1);
    matrix.setTextWrap(false);

    // For loop that diaplays time on top and temp+date below
    for (int8_t x=0; x>=-300; x--){
      int tempc = clock.getTemperature();
      int tempf = (tempc*1.8)+32;
      int hr = clock.getHour(h12Flag, pmFlag); //get the current hour in 24hr format
      int min = clock.getMinute(); 
      int sec = clock.getSecond();
      int day = clock.getDate();
      int month = clock.getMonth(century); 
      matrix.fillRect(16, 0, 59, 8, 0); 
      matrix.setCursor(0,1);
      matrix.setTextSize(1);
      matrix.setTextWrap(false);
      
      matrix.print(hr);
      
      matrix.print(":");
      
      if (min<10){
        matrix.print("0");
        matrix.print(min, DEC);
      } else {
        matrix.print(min, DEC);
      }
      
      matrix.print(":");
      
      if (sec<10){
        matrix.print("0");
        matrix.print(sec, DEC);
      } else {
        matrix.print(sec, DEC);
      }
      
      matrix.setCursor(0,9);
      
      matrix.print(tempf);
      
      matrix.print("F");
      
      if (month<10){
        matrix.print("0");
        matrix.print(month, DEC);
      } else {
        matrix.print(month, DEC);
      }
      
      matrix.print("/");
      
      if (day<10){
        matrix.print("0");
        matrix.print(day, DEC);
      } else {
        matrix.print(day, DEC);
      }
      matrix.writeScreen();
      delay(100);
    }
    

   
    matrix.clearScreen();
    matrix.setBrightness(1);
    for (int8_t i=0; i>=-2; i--){
    for (int8_t x=0; x>=-59; x--){ 
        matrix.setCursor(x,1);
        matrix.setTextSize(1);
        matrix.setTextWrap(false);
        matrix.clearScreen();
        matrix.print(" ");
        if (hr<10){
          matrix.print("0");
          matrix.print(hr, DEC);
        } else {
          matrix.print(hr, DEC);
        }
        if (min<10){
          matrix.print("0");
          matrix.print(min, DEC);
        } else {
          matrix.print(min, DEC);
        }
        matrix.print(" ");
        if (hr<10){
          matrix.print("0");
          matrix.print(hr, DEC);
        } else {
          matrix.print(hr, DEC);
        }
        if (min<10){
          matrix.print("0");
          matrix.print(min, DEC);
        } else {
          matrix.print(min, DEC);
        }
        matrix.print(" ");
        if (hr<10){
          matrix.print("0");
          matrix.print(hr, DEC);
        } else {
          matrix.print(hr, DEC);
        }
        if (min<10){
          matrix.print("0");
          matrix.print(min, DEC);
        } else {
          matrix.print(min, DEC);
        }
        matrix.print(" ");
        if (hr<10){
          matrix.print("0");
          matrix.print(hr, DEC);
        } else {
          matrix.print(hr, DEC);
        }
        if (min<10){
          matrix.print("0");
          matrix.print(min, DEC);
        } else {
          matrix.print(min, DEC);
        }
        matrix.writeScreen();
        matrix.setCursor(-(x*1)-83,9);
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.print(-tempf);
        matrix.print("F- ");
        matrix.writeScreen();
        int sec = clock.getSecond();
        delay(50);
      };
    };
      
    matrix.clearScreen();
    matrix.setTextSize(1);
    matrix.setCursor(3,0);
    matrix.print("Charlie");
    matrix.setCursor(9,8);
    matrix.print("Ahner");
    matrix.writeScreen();
    delay (2500);
    matrix.clearScreen();
    matrix.setTextWrap(false); 
    
    for (int8_t x=-1; x>=-48; x--) {
        matrix.clearScreen();
        matrix.setCursor(x+3,0);
        matrix.print("Charlie");
        matrix.setCursor(-x+9,8);
        matrix.print("Ahner");
        matrix.writeScreen();
        delay (25);
    }


    for (uint8_t y=0; y<matrix.height(); y++) {
        for (uint8_t x=0; x< matrix.width(); x++) {
            matrix.setPixel(x, y);
            matrix.writeScreen();
        }
    }
    delay (1000);
}