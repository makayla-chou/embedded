#include <Arduino.h>

// Using light sensor
// PF0 (ADC0) 41 A5_LIGHT_SENSE





void setup() {

  
  ADMUX = 0b01000000;
  // 7:6 - 01 (AVCC with external capacitor at AREF)
  // 5 ADLAR = 0
  // 4:0 - 00000 (ADC0)

  ADCSRA = 0b1000011;
  // 7 - ADEN = 1 turn on ADC
  // 6 - ADSC = 0 (don't start conversion)
  // 5 - ADIF = 0 (ADC interrupt flag)
  // 4 - ADIE = 0 (ADC interrupt enable)
  // 2:0 - ADPS2:0 = 011 (ADC prescaler, prescale clock divide by 8)

  ADCSRB = 0b00000000;
  // 7:5 - don't care rn
  // 4 - N/A
  // 3:0 - free running mode


  DIDR0 |= (1 << 0); // disable ADC0 digital input

  Serial.begin(9600);


}

int myDelay = 500;

void loop() {

  ADCSRA |= (1 << ADSC); // start ADC conversion (1 << 6)
  delay(myDelay);


  // int x = (ADCH << 8) + ADCL; // read ADC value (10-bit)
  // Serial.println(x); // print ADC value to serial monitor
  // ^ don't need cause ADCW contains the 10-bit ADC result (ADCH << 8) + ADCL at addy 78
  // ADCW reads 16 bits and gets from 78 and 79

  Serial.println(ADCW);


  
}

