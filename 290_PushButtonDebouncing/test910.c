#include <plib/timers.h>
#include <stdio.h>
#include <xc.h>

#define Button_PORT PORTA

typedef union {
  unsigned char Full;
  struct {
    unsigned char B0 : 1;
    unsigned char B1 : 1;
    unsigned char B2 : 1;
    unsigned char B3 : 1;
    unsigned char B4 : 1;
    unsigned char B5 : 1;
    unsigned char B6 : 1;
    unsigned char B7 : 1;
  };
} Button_Type;

Button_Type Button_Press; // Create the Button variable

typedef enum { Waiting, Detected, WaitForRelease, Update } states;

void Find_Button_Press(void) {
  static states Button_State = Waiting;
  static unsigned char Button_Count = 0;
  static Button_Type Temp_Press;

  switch (Button_State) {
  case (Waiting):
    if (Button_PORT) {
      Button_State = Detected;
      Button_Count = 0;
      Temp_Press.Full = Button_PORT;
    }
    break;
  case (Detected):
    if (Temp_Press.Full == Button_PORT) {
      ++Button_Count;
      if (Button_Count > MIN_BUTTON_COUNT) {
        Button_State = WaitForRelease;
      }
    } else {
      Button_State = Waiting;
    }
    break;
  case (WaitForRelease):
    if (!Button_PORT) {
      Button_State = Update;
    }
    break;
  case (Update): {
    Button_Press = Temp_Press;
    Button_State = Waiting;
    Button_Count = 0;
    Temp_Press.Full = 0;
  } break;
  default: {
    Button_State = Waiting;
    Button_Count = 0;
    Temp_Press.Full = 0;
    Button_Press.Full = 0;
  }
  }
}

/************************************************
 Function Prototypes
*************************************************/
void Initial(void);
void delay_s(unsigned char secs);

/*************************************************
 Clock
*************************************************/
#define _XTAL_FREQ 19660800

unsigned char count_test = 0;
void __interrupt myIsr(void) {
  // Timer overflows every 10mS
  if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
    Find_Button_Press(); // called every 10mS
    WriteTimer0(40960);
    INTCONbits.TMR0IF = 0; // clear this interrupt condition
  }
}

int main(void) {
  Button_Press.Full = 0x00;
  Initial();
  while (1) {
    if (Got_Button_E) // if some button has been pressed
    {
      if (Button_Press.B0) // if its button 0
        PORTCbits.RC0 = ~PORTCbits.RC0;

      if (Button_Press.B1) // if its button 0
        PORTCbits.RC1 = ~PORTCbits.RC1;

      if (Button_Press.B2) // if its button 0
        PORTCbits.RC2 = ~PORTCbits.RC2;

      if (Button_Press.B3) // if its button 0
        PORTCbits.RC3 = ~PORTCbits.RC3;

      Button_Press.Full = 0x00; // clear all button events
    }
  }
  return 0;
}