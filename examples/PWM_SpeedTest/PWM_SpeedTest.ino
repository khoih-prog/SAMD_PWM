/****************************************************************************************************************************
  PWM_SpeedTest.ino
  For SAMD21/SAMD51 boards using hardware-based PWM
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/SAMD_PWM
  Licensed under MIT license
*****************************************************************************************************************************/

#define _PWM_LOGLEVEL_       1

#include "SAMD_PWM.h"

#define UPDATE_INTERVAL       1000L

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

float    frequency = 2000.0f;
//float    frequency = 10000.0f;

// Using setPWM_DCPercentage_manual if true
//#define USING_DC_PERCENT      false
#define USING_DC_PERCENT      true

#if USING_DC_PERCENT
float    dutycyclePercent = 0.0f;
float    DCStepPercent    = 5.0f;

// dutycyclePercentInt = dutycyclePercent * 65535 / 100
uint16_t    dutycyclePercentInt = 0;
#else
uint16_t dutycycle        = 0;
uint16_t DCStep;
#endif

uint16_t PWMPeriod;

char dashLine[] = "=================================================================================================";

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

  delay(100);

  Serial.print(F("\nStarting PWM_SpeedTest on "));
  Serial.println(BOARD_NAME);
  Serial.println(SAMD_PWM_VERSION);

  // Create a dummy instance
  PWM_Instance = new SAMD_PWM(pinToUse, frequency, 0);

  if (PWM_Instance)
  {
    if (!PWM_Instance->setPWM())
    {
      Serial.println(F("Stop here"));

      // stop here
      while (true)
        delay(1000);
    }
  }

#if USING_DC_PERCENT
  dutycyclePercent = 50.0f;

  // dutycyclePercentInt = dutycyclePercent * 65535 / 100
  dutycyclePercentInt = MAX_16BIT / 2;
#else
  // 5% steps
  DCStep = round( MAX_16BIT / 20.0f);

  // 50%
  dutycycle = MAX_16BIT / 2;
#endif

  Serial.print(F("Average time of setPWM function"));

#if USING_DC_PERCENT
  Serial.println(F(" USING_DC_PERCENT"));
#else
  Serial.println(F(" not USING_DC_PERCENT"));
#endif
}

void loop()
{
  static unsigned long update_timeout = UPDATE_INTERVAL + millis();
  static uint32_t count = 0;

#if USING_DC_PERCENT
  // Very inefficient, don't use => 499251 ns
  //PWM_Instance->setPWM(pinToUse, frequency, dutycyclePercent);
  // 1259 ns
  //PWM_Instance->setPWM_DCPercentage_manual(pinToUse, dutycyclePercent);
  // 1067 ns
  PWM_Instance->setPWM_DCPercentageInt_manual(pinToUse, dutycyclePercentInt);
#else
  // dutycycle = 0-65535 for 0-100%
  // 1084 ns
  PWM_Instance->setPWM_manual(pinToUse, dutycycle);
#endif

  count++;

  // Update DC every UPDATE_INTERVAL (1000) milliseconds
  if (millis() > update_timeout)
  {
    printPWMInfo(PWM_Instance);

    Serial.print(F("count="));
    Serial.print( count);
    Serial.print(F(", ns="));
    Serial.println( (uint32_t) (UPDATE_INTERVAL * 1000000 / count));

    count = 0;
    update_timeout = millis() + UPDATE_INTERVAL;
  }
}
