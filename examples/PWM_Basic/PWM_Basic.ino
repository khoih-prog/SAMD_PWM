/****************************************************************************************************************************
  PWM_Basic.ino

  For SAMD21/SAMD51 boards using hardware-based PWM
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/SAMD_PWM
  Licensed under MIT license
*****************************************************************************************************************************/

#define _PWM_LOGLEVEL_       4

#include "SAMD_PWM.h"

// Not OK for Nano_33_IoT (0, 1, 7, 8, 13, 14, 15 )
// OK for Nano_33_IoT (2, 3, 4, 5, 6, 9, 10, 11, 12, 16, 17)
// TCC OK => pin 4, 5, 6, 8, 9, 10, 11, 16/A2, 17/A3
// TC OK  => pin 12
// For ITSYBITSY_M4
// 16-bit Higher accuracy, Lower Frequency, PWM Pin OK: TCCx: 0-2, 4, 5, 7, 9-13
//  8-bit Lower  accuracy, Hi Frequency,    PWM Pin OK: TCx: 18-20, 24-25

#define pinToUse       11

//creates pwm instance
SAMD_PWM* PWM_Instance;

float frequency = 1000.0f;

float dutyCycle = 0.0f;

uint8_t channel = 0;

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  delay(500);

  Serial.print(F("\nStarting PWM_Basic on "));
  Serial.println(BOARD_NAME);
  Serial.println(SAMD_PWM_VERSION);

  //assigns PWM frequency of 1.0 KHz and a duty cycle of 0%
  PWM_Instance = new SAMD_PWM(pinToUse, frequency, dutyCycle);
}

void loop()
{
  // You can change frequency here, anytime
  frequency = 2000.0f;
  dutyCycle = 20.0f;

  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);

  delay(10000);

  // You can change frequency here, anytime
  frequency = 5000.0f;
  dutyCycle = 90.0f;

  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);

  //while (1)
  delay(10000);
}
