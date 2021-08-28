
#include <DS3231.h>
#include <Wire.h>

DS3231 clock;
bool led_stop = false; //this is what is holding the value for the button press
bool h12Flag;
bool pmFlag;
int ledpin = 13;
int buttonpin = 12;



void setup() {
  Wire.begin();
  Serial.begin(57600);
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP); //set the button to work by shorting to ground. Open is high, closed is low. 
  digitalWrite(buttonpin, HIGH);  // turn on pullup resistor
}

void loop() {
  int hr = clock.getHour(h12Flag, pmFlag); //get the current hour in 24hr format

   
  if (hr <= 22 && hr >= 19){ //if it is between 7pm and 10pm
    if (led_stop == 0){ //and the button is still in the false state do this.
      digitalWrite(ledpin, HIGH);
      delay(50);
      digitalWrite(ledpin, LOW);
      delay(50);
      digitalWrite(ledpin, HIGH);
      Serial.print("nightime meds ");
    } else { //otherwise do this
      digitalWrite(ledpin, LOW);
    }
  } else if (hr <= 10 && hr >= 07){ //also if it is between 7am and 10am
    if (led_stop == 0){ //and the button is still in the false state do this.
      digitalWrite(ledpin, HIGH);
      delay(100);
      digitalWrite(ledpin, LOW);
      delay(100);
      digitalWrite(ledpin, HIGH);
      Serial.print("morning meds ");
    } else {
      digitalWrite(ledpin, LOW);
    }
  } else {
    digitalWrite(ledpin, LOW);
  }
  
  if (hr == 12){ //if it is 12 reset the button boolean 
    led_stop = 0;
    Serial.print("bool reset ");
  } else if (hr == 23){ //if it is 11pm reset the button boolean 
    led_stop = 0;
    Serial.print("bool reset ");
  }
  
  if (digitalRead(buttonpin) == LOW) { //read to see if the button has been pressed
    delay(100); //wait a sec so you're not just spamming the button with a single press
    led_stop = 1; //set the button boolean to true  
    Serial.print("ledstopped ");
    }
}
