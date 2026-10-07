#include <Arduino.h>
#define BIT_RBUTTON 6
#define BIT_LBUTTON 4



#define LED1_BIT 6   // D10 = PB6
#define LED2_BIT 5   // D9  = PB5
#define LED3_BIT 7   // D6  = PD7


bool running = false;
bool prevRButtonState = false;
int count = 0;



void setup() {

  DDRB |= (1 << LED1_BIT);   // PB6 output
  DDRB |= (1 << LED2_BIT);   // PB5 output
  DDRD |= (1 << LED3_BIT);   // PD7 output

  DDRC |= (1 << BIT_RBUTTON); // set right button pin as input
  DDRD |= (1 << BIT_LBUTTON); // set left button pin as input



}



void loop() {

  uint8_t regPINF = PINF;
  uint8_t regPIND = PIND;

  bool rButtonPressed = (regPINF & (1 << BIT_RBUTTON)) != 0;

  bool lButtonPressed = (regPIND & (1 << BIT_LBUTTON)) != 0;


  if (rButtonPressed && !prevRButtonState) {
        running = !running;
    }

    prevRButtonState = rButtonPressed;

  if (lButtonPressed) {
      count = 0;
  }


  if (count & (1 << 0))
        PORTB |= (1 << LED1_BIT);
    else
        PORTB &= ~(1 << LED1_BIT);

    if (count & (1 << 1))
        PORTB |= (1 << LED2_BIT);
    else
        PORTB &= ~(1 << LED2_BIT);

    if (count & (1 << 2))
        PORTD |= (1 << LED3_BIT);
    else
        PORTD &= ~(1 << LED3_BIT);


    if (running) {

      delay(1000);

      count++;

      if (count > 7) {
          count = 0;
      }
    }

    /*
      // 000
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      delay(100);
      // 001
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);  
      delay(100);      // 010
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      delay(100);
      // 011
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      delay(100);
      // 100
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      delay(100);
      // 101
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);   
      delay(100);     
      // 110
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH); 
      delay(100); 
      // 111 
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      delay(100);
  }
*/


}
