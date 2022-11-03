/****************************************************************************************************************************
  PWM_Multi.ino

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

// Change to use the correct PWM pins from different TCx or TCCx, according to your boards
#if defined(__SAMD51__)
// Pin 5:TCC2_CH1, pin 7: TCC1_CH2, pin 11: TCC0_CH1, pin 25/MOSI: TC2_CH0
uint32_t PWM_Pins[]   = { 5, 7, 11, 25 };
#else
// pin 4: TCC1_CH1, Pin 5:TCC0_CH1, pin 11: TCC2_CH0, pin 12: TC3_CH1
uint32_t PWM_Pins[]   = { 4, 5, 11, 12 };
#endif

#define NUM_OF_PINS   ( sizeof(PWM_Pins) / sizeof(uint32_t) )

float dutyCycle[] = { 10.0f, 30.0f, 50.0f, 90.0f };

float frequency[] = { 2000.0f, 3000.0f, 4000.0f, 8000.0f };

SAMD_PWM* PWM_Instance[NUM_OF_PINS];

char dashLine[] = "=====================================================================================";

void printPWMInfo(SAMD_PWM* PWM_Instance)
{
  Serial.println(dashLine);
  Serial.print("Actual data: pin = ");
  Serial.print(PWM_Instance->getPin());
  Serial.print(", PWM DC = ");
  Serial.print(PWM_Instance->getActualDutyCycle());
  Serial.print(", PWMPeriod = ");
  Serial.print(PWM_Instance->getPWMPeriod());
  Serial.print(", PWM Freq (Hz) = ");
  Serial.println(PWM_Instance->getActualFreq(), 4);
  Serial.println(dashLine);
}

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  delay(500);

  Serial.print(F("\nStarting PWM_Multi on "));
  Serial.println(BOARD_NAME);
  Serial.println(SAMD_PWM_VERSION);

  for (uint8_t index = 0; index < NUM_OF_PINS; index++)
  {
    PWM_Instance[index] = new SAMD_PWM(PWM_Pins[index], frequency[index], dutyCycle[index]);

    if (PWM_Instance[index])
    {
      PWM_Instance[index]->setPWM();
    }
  }

  Serial.println(dashLine);
  Serial.println("Index\tPin\tPWM_freq\tDutyCycle\tActual Freq");
  Serial.println(dashLine);

  for (uint8_t index = 0; index < NUM_OF_PINS; index++)
  {
    if (PWM_Instance[index])
    {
      Serial.print(index);
      Serial.print("\t");
      Serial.print(PWM_Pins[index]);
      Serial.print("\t");
      Serial.print(frequency[index]);
      Serial.print("\t\t");
      Serial.print(dutyCycle[index]);
      Serial.print("\t\t");
      Serial.println(PWM_Instance[index]->getActualFreq(), 4);
    }
    else
    {
      Serial.println();
    }
  }

  for (uint8_t index = 0; index < NUM_OF_PINS; index++)
  {
    printPWMInfo(PWM_Instance[index]);
  }
}

void loop()
{
  //Long delay has no effect on the operation of hardware-based PWM channels
  delay(1000000);
}
