/****************************************************************************************************************************
  PWM_Waveform.ino

  For SAMD21/SAMD51 boards using hardware-based PWM
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/SAMD_PWM
  Licensed under MIT license
*****************************************************************************************************************************/

#define _PWM_LOGLEVEL_       1

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

typedef struct
{
  uint16_t level;
} PWD_Data;

// Data for 0-100%
PWD_Data PWM_data[] =
{
  {    0 },
  { (  5 * 65535 ) / 100 },
  { ( 10 * 65535 ) / 100 },
  { ( 15 * 65535 ) / 100 },
  { ( 20 * 65535 ) / 100 },
  { ( 25 * 65535 ) / 100 },
  { ( 30 * 65535 ) / 100 },
  { ( 35 * 65535 ) / 100 },
  { ( 40 * 65535 ) / 100 },
  { ( 45 * 65535 ) / 100 },
  { ( 50 * 65535 ) / 100 },
  { ( 55 * 65535 ) / 100 },
  { ( 60 * 65535 ) / 100 },
  { ( 65 * 65535 ) / 100 },
  { ( 70 * 65535 ) / 100 },
  { ( 75 * 65535 ) / 100 },
  { ( 80 * 65535 ) / 100 },
  { ( 85 * 65535 ) / 100 },
  { ( 90 * 65535 ) / 100 },
  { ( 95 * 65535 ) / 100 },
  { (100 * 65535 ) / 100 },
  { ( 95 * 65535 ) / 100 },
  { ( 90 * 65535 ) / 100 },
  { ( 85 * 65535 ) / 100 },
  { ( 80 * 65535 ) / 100 },
  { ( 75 * 65535 ) / 100 },
  { ( 70 * 65535 ) / 100 },
  { ( 65 * 65535 ) / 100 },
  { ( 60 * 65535 ) / 100 },
  { ( 55 * 65535 ) / 100 },
  { ( 50 * 65535 ) / 100 },
  { ( 45 * 65535 ) / 100 },
  { ( 40 * 65535 ) / 100 },
  { ( 35 * 65535 ) / 100 },
  { ( 30 * 65535 ) / 100 },
  { ( 25 * 65535 ) / 100 },
  { ( 20 * 65535 ) / 100 },
  { ( 15 * 65535 ) / 100 },
  { ( 10 * 65535 ) / 100 },
  { (  5 * 65535 ) / 100 },
  {    0 },
};

#define NUM_PWM_POINTS      ( sizeof(PWM_data) / sizeof(PWD_Data) )

float frequency = 2000.0f;
float dutyCycle = 0.0f;

uint8_t channel = 0;

// You can select any value
PWD_Data PWM_data_idle = PWM_data[0];

char dashLine[] = "============================================================================================";

void printPWMInfo(SAMD_PWM* PWM_Instance)
{
  Serial.println(dashLine);
  Serial.print("Actual data: pin = ");
  Serial.print(PWM_Instance->getPin());
  Serial.print(", PWM DutyCycle = ");
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

  Serial.print(F("\nStarting PWM_Waveform on "));
  Serial.println(BOARD_NAME);
  Serial.println(SAMD_PWM_VERSION);

  // Create a dummy instance
  PWM_Instance = new SAMD_PWM(pinToUse, frequency, dutyCycle);

  if (PWM_Instance)
  {
    // setPWM_manual(uint8_t pin, uint16_t level)
    PWM_Instance->setPWM(pinToUse, frequency, 0);

    printPWMInfo(PWM_Instance);
  }
}

void updateDC()
{
  static uint16_t index = 0;

  // Mapping data to any other frequency from original data 0-100 to actual Dutycycle
  PWM_Instance->setPWM_manual(pinToUse, PWM_data[index].level );

  // Use at low freq to check
  //printPWMInfo(PWM_Instance);

  index = (index + 1) % NUM_PWM_POINTS;
}

void check_status()
{
#define UPDATE_INTERVAL     100L

  static unsigned long update_timeout = UPDATE_INTERVAL;

  // Update DC every UPDATE_INTERVAL (100) milliseconds
  if (millis() > update_timeout)
  {
    updateDC();
    update_timeout = millis() + UPDATE_INTERVAL;
  }
}

void loop()
{
  check_status();
}
