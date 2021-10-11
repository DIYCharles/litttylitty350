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
    String mins = String(min);
    if (min<10){
        String mins = String('0' + mins);
        } else {
        String mins = String(mins);
       }
    String secs = String(sec); 
    String hrs = String(hr); 
    int day = clock.getDate();
    int month = clock.getMonth(century);
    matrix.clearScreen();
    matrix.setBrightness(1);

    matrix.setTextSize(1);
    matrix.setTextWrap(false);
    
    for (int8_t x=0; x>=-100; x--){
      int sec = clock.getSecond(); 
      String secs = String(sec);
      String secss = String(secs);
      if (sec<10){
        String secss = String('0' + secs);
        } else {
        String secss = String(secs);
       }
      matrix.fillRect(36, 0, 59, 8, 0); 
      matrix.setCursor(0,0);
      matrix.setTextSize(1);
      matrix.setTextWrap(false);
      String tiem = String(hrs + ':' + mins + ':' + secss);
      matrix.print(tiem);
//      matrix.print(hr);
//      matrix.print(" ");
//      matrix.print(" ");
//      if (sec<10){
//        matrix.print("0");
//        matrix.print(sec, DEC);
//      } else {
//        matrix.print(sec, DEC);
//      }
      matrix.setCursor(0,9);
      matrix.print(tempf);
      matrix.print(" ");
      if (min<10){
        matrix.print("0");
        matrix.print(month, DEC);
      } else {
        matrix.print(month, DEC);
      };
      matrix.print("/");
      if (min<10){
        matrix.print("0");
        matrix.print(month, DEC);
      } else {
        matrix.print(month, DEC);
      };
      matrix.writeScreen();
      delay(250);
    }
    

   
    matrix.clearScreen();
    matrix.setBrightness(1);

    for (int8_t x=0; x>=-200; x--){
              matrix.clearScreen();
        int sec = clock.getSecond(); 
        matrix.setCursor(x,1);
        matrix.setTextSize(2);
        matrix.setTextWrap(false);
        matrix.print(" T");
        matrix.print(tempf);
        matrix.print("  ");
        matrix.print(hr);
        matrix.print(":");
        matrix.print(min, DEC);
        matrix.print(":");
        matrix.print(sec, DEC);
        matrix.print(" "); 
        matrix.print(hr);
        matrix.print(":");
        matrix.print(min, DEC);
        matrix.print(":");
        matrix.print(sec, DEC);
//        matrix.setCursor(-x-55,9);
//        matrix.print(" T");
//        matrix.print(tempf);
//        matrix.print(" T");
//        matrix.print(tempf);
//        matrix.print(" T");
//        matrix.print(tempf);
//        matrix.print(" T");
//        matrix.print(tempf);
//        matrix.print(" T");
//        matrix.print(tempf);
//        matrix.print(" T");
//        matrix.print(tempf);
//        matrix.print(" T");
//        matrix.print(tempf);
        matrix.writeScreen();
        delay(35);

    }
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

    // for (int8_t x=0; x>=-110; x--){
    //     matrix.clearScreen();
    //     matrix.setCursor(x,1);
    //     matrix.setTextSize(2);
    //     matrix.setTextWrap(false); 
    //     matrix.print("DEVOPS");
    //     matrix.setCursor(x+76,1);
    //     matrix.print("ENGINEER");
    //     matrix.writeScreen();
    //     delay(50);
    // }

    // for (int8_t x=-35; x>=-105; x--){
    //     matrix.clearScreen();
    //     matrix.setCursor(x,1);
    //     matrix.print("ENGINEER");
    //     matrix.writeScreen();
    //     delay(50);
    // }

    // delay(800);

    // for (uint8_t y=0; y<48; y++) {
    //     for (uint8_t x=0; x< 48; x++) {
    //         matrix.setPixel(x, y);
    //         matrix.clrPixel(x-3, y);
    //         matrix.setPixel(x-12, y);
    //         matrix.clrPixel(x-15, y);
    //         matrix.setPixel(x-24, y);
    //         matrix.clrPixel(x-27, y);
    //         matrix.setPixel(x-36, y);
    //         matrix.clrPixel(x-39, y);
    //         matrix.writeScreen();
    //     }
    // }


    Serial.println("START 1");
    Serial.println();
    matrix.fillRect(5, 0, 59, 16, 0);
    matrix.setCursor(0,0);
    matrix.print(hr);
    matrix.print(":");
    matrix.print(min, DEC);
    matrix.print(":");
    matrix.print(sec);
    matrix.print(" ");
    matrix.print(tempf);
    matrix.print("DEG");
    matrix.writeScreen();
    delay(2500);

    for (uint8_t y=0; y<matrix.height(); y++) {
        for (uint8_t x=0; x< matrix.width(); x++) {
            matrix.setPixel(x, y);
            matrix.writeScreen();
        }
    }
}