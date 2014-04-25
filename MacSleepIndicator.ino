#include <DigiUSB.h>

#define  kMODE_OFF       0
#define  kMODE_ON        1
#define  kMODE_BLINK_PB  2
#define  kMODE_BLINK_MB  3

#define  kPWM_OFFSET     64

#define BUILT_IN_LED_PIN  1 /* Digispark Model A (Rev2) built-in LED pin number (Change it to 2 for Model B) */

static uint8_t  gStatus;
static uint8_t  Pwm;
static int8_t   Dir;

void setup()
{
  DigiUSB.begin();

  pinMode( BUILT_IN_LED_PIN, OUTPUT);

  gStatus = kMODE_ON;
  Pwm = 0;
  Dir = 1;
}


void get_input() {
  int lastRead;

  if (DigiUSB.available()) {
    lastRead = DigiUSB.read();
    switch( lastRead) {
    case '0':
      gStatus = kMODE_OFF;
      break;

    case '1':
      gStatus = kMODE_ON;
      break;

    case '2':
      gStatus = kMODE_BLINK_PB;
      Pwm = 0;
      Dir = 1;
      break;

    case '3':
      gStatus = kMODE_BLINK_MB;
      Pwm = 0;
      Dir = 1;
      break;

    default:
      break;
    }
  }
  // refresh the usb port for 10 milliseconds
  DigiUSB.delay(1);

}


void loop()
{
  static uint32_t StartMs = millis();

  get_input();

  if( ( millis() - StartMs) >= 10) {
    StartMs = millis();
    switch( gStatus) {
    case kMODE_OFF:
      analogWrite( BUILT_IN_LED_PIN, 0);
      break;

    case kMODE_ON:
      analogWrite( BUILT_IN_LED_PIN, 255);
      break;

    case kMODE_BLINK_PB:
    case kMODE_BLINK_MB:
      /* We arrived here every 10 milliseconds */
      Pwm += Dir; /* increment or decrement PWM depending of sign of Dir */

      switch( gStatus) {
      case kMODE_BLINK_PB:
        {
          if( Pwm < 10) {
            analogWrite( BUILT_IN_LED_PIN, 255);
          } 
          else {
            analogWrite( BUILT_IN_LED_PIN, 0);
          }
          if( Pwm == 200) Pwm = 0;
          break;
        }

      case kMODE_BLINK_MB:
        if(Pwm < kPWM_OFFSET) {
          analogWrite( BUILT_IN_LED_PIN, 0);
        } 
        else {
          analogWrite( BUILT_IN_LED_PIN, Pwm - kPWM_OFFSET);
        }
        if( Pwm == 255) Dir = -1; /* if PWM reaches the maximum: change direction */
        if( Pwm == 0)   Dir = +1; /* if PWM reaches the minimum: change direction */
        break;
      }
      break;        
    }
  }
}



