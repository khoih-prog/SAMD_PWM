/****************************************************************************************************************************
  SAMD_PWM.h

  For SAMD21/SAMD51 boards using hardware-based PWM
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/SAMD_PWM
  Licensed under MIT license

  Version: 1.2.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      01/11/2022 Initial coding for SAMD21/SAMD51 boards
  1.0.1   K Hoang      22/01/2023 Add `PWM_StepperControl` example
  1.2.0   K Hoang      28/01/2023 Add `PWM_SpeedTest` and `PWM_manual` examples and faster functions
*****************************************************************************************************************************/

#pragma once

#ifndef SAMD_PWM_H
#define SAMD_PWM_H

#if !( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD51__) || defined(__SAMD51J20A__) \
      || defined(__SAMD51J19A__) || defined(__SAMD51G19A__) || defined(__SAMD51P19A__)  \
      || defined(__SAMD21E15A__) || defined(__SAMD21E16A__) || defined(__SAMD21E17A__) || defined(__SAMD21E18A__) \
      || defined(__SAMD21G15A__) || defined(__SAMD21G16A__) || defined(__SAMD21G17A__) || defined(__SAMD21G18A__) \
      || defined(__SAMD21J15A__) || defined(__SAMD21J16A__) || defined(__SAMD21J17A__) || defined(__SAMD21J18A__) )
#error This code is designed to run on SAMD21/SAMD51 platform! Please check your Tools->Board setting.
#endif

#if ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_NANO_33_IOT) \
   || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) || defined(ARDUINO_SAMD_MKRGSM1400) \
   || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) \
   || defined(__SAMD21E15A__) || defined(__SAMD21E16A__) || defined(__SAMD21E17A__) || defined(__SAMD21E18A__) \
   || defined(__SAMD21G15A__) || defined(__SAMD21G16A__) || defined(__SAMD21G17A__) || defined(__SAMD21G18A__) \
   || defined(__SAMD21J15A__) || defined(__SAMD21J16A__) || defined(__SAMD21J17A__) || defined(__SAMD21J18A__) || defined(__SAMD21__) )

#define PWM_USING_SAMD21      true

#if !defined(BOARD_NAME)

  #if defined(ARDUINO_QWIIC_MICRO)
    #define BOARD_NAME    "Sparkfun SAMD21_QWIIC_MICRO"

    #if (_PWM_LOGLEVEL_ > 3)
      #warning BOARD_NAME == Sparkfun SAMD21_QWIIC_MICRO
    #endif

  #elif defined(__SAMD21E15A__)
    #define BOARD_NAME    "__SAMD21E15A__"
  #elif defined(__SAMD21E16A__)
    #define BOARD_NAME    "__SAMD21E16A__"
  #elif defined(__SAMD21E17A__)
    #define BOARD_NAME    "__SAMD21E17A__"
  #elif defined(__SAMD21E18A__)
    #define BOARD_NAME    "__SAMD21E18A__"
  #elif defined(__SAMD21G15A__)
    #define BOARD_NAME    "__SAMD21G15A__"
  #elif defined(__SAMD21G16A__)
    #define BOARD_NAME    "__SAMD21G16A__"
  #elif defined(__SAMD21G17A__)
    #define BOARD_NAME    "__SAMD21G17A__"
  #elif defined(__SAMD21G18A__)
    #define BOARD_NAME    "__SAMD21G18A__"
  #elif defined(__SAMD21J15A__)
    #define BOARD_NAME    "__SAMD21J15A__"
  #elif defined(__SAMD21J16A__)
    #define BOARD_NAME    "__SAMD21J16A__"
  #elif defined(__SAMD21J17A__)
    #define BOARD_NAME    "__SAMD21J17A__"
  #elif defined(__SAMD21J18A__)
    #define BOARD_NAME    "__SAMD21J18A__"
  #else
    #define BOARD_NAME    "Unknown SAMD21"
  #endif

#endif

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using SAMD21 Hardware PWM
#endif

#elif ( defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) )
#define PWM_USING_SAMD51      true

#if !defined(BOARD_NAME)

  #if defined(ARDUINO_SAMD51_THING_PLUS)
    #define BOARD_NAME    "Sparkfun SAMD51_THING_PLUS"

    #if (_PWM_LOGLEVEL_ > 3)
      #warning BOARD_NAME == Sparkfun SAMD51_THING_PLUS
    #endif

  #elif defined(ARDUINO_SAMD51_MICROMOD)
    #define BOARD_NAME    "Sparkfun SAMD51_MICROMOD"

    #if (_PWM_LOGLEVEL_ > 3)
      #warning BOARD_NAME == Sparkfun SAMD51_MICROMOD
    #endif

  #elif defined(__SAMD51J20A__)
    #define BOARD_NAME    "__SAMD51J20A__"
  #elif defined(__SAMD51J19A__)
    #define BOARD_NAME    "__SAMD51J19A__"
  #elif defined(__SAMD51G19A__)
    #define BOARD_NAME    "__SAMD51G19A__"
  #elif defined(__SAMD51P19A__)
    #define BOARD_NAME    "__SAMD51P19A__"
  #else
    #define BOARD_NAME    "Unknown SAMD51"
  #endif

#endif

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using SAMD51 Hardware PWM
#endif

#else
#error Unknown board
#endif

// Too many boards sharing the same ARDUINO_SAMD_ZERO but very different, such as SAMD21 SparkFun RedBoard Turbo
// Have to exclude some from the list
#if ( defined(ARDUINO_SAMD_ZERO) && ! ( defined(ADAFRUIT_FEATHER_M0) || defined(ARDUINO_SAMD_FEATHER_M0) || defined(ADAFRUIT_METRO_M0_EXPRESS) || \
      defined(ARDUINO_SAMD_HALLOWING_M0) || defined(ADAFRUIT_BLM_BADGE) ) )
// Specific for SAMD21 SparkFun RedBoard Turbo
#if !defined(Serial)
  #define Serial    SerialUSB
#endif
#endif

#include "Arduino.h"

#ifndef SAMD_PWM_VERSION
  #define SAMD_PWM_VERSION             "SAMD_PWM v1.2.0"

  #define SAMD_PWM_VERSION_MAJOR       1
  #define SAMD_PWM_VERSION_MINOR       2
  #define SAMD_PWM_VERSION_PATCH       0

  #define SAMD_PWM_VERSION_INT         1002000
#endif

#include "PWM_Generic_Debug.h"

#include "wiring_private.h"

////////////////////////////////////////

// For Arduino SAMD21
// TCC0 has 4 channels (TCC0_CH0-TCC0_CH3 and TCC0_CH4-TCC0_CH7 are the same)
// TCC1 and TCC2 each has 2 channels (TCC1_CH0-TCC1_CH2, TCC1_CH3-TCC1_CH3 are the same)
// TCC3, TCC4 and TCC5 each has 1 channel (TCC3_CH0 and TCC3_CH1 are the same)
// TCC6 and TCC7 each has 1 channel (TCC6_CH0 and TCC6_CH1 are the same) only on __SAMD21J18A__

/*************************************
  // Definitions for PWM channels
  typedef enum _EPWMChannel
  {
  NOT_ON_PWM = -1,
  PWM0_CH0 = TCC0_CH0,
  PWM0_CH1 = TCC0_CH1,
  PWM0_CH2 = TCC0_CH2,
  PWM0_CH3 = TCC0_CH3,
  PWM0_CH4 = TCC0_CH4,
  PWM0_CH5 = TCC0_CH5,
  PWM0_CH6 = TCC0_CH6,
  PWM0_CH7 = TCC0_CH7,
  PWM1_CH0 = TCC1_CH0,
  PWM1_CH1 = TCC1_CH1,
  PWM1_CH2 = TCC1_CH2,
  PWM1_CH3 = TCC1_CH3,
  PWM2_CH0 = TCC2_CH0,
  PWM2_CH1 = TCC2_CH1,
  PWM2_CH2 = TCC2_CH2,
  PWM2_CH3 = TCC2_CH3,
  PWM3_CH0 = TC3_CH0,
  PWM3_CH1 = TC3_CH1,
  PWM4_CH0 = TC4_CH0,
  PWM4_CH1 = TC4_CH1,
  PWM5_CH0 = TC5_CH0,
  PWM5_CH1 = TC5_CH1,
  #if defined __SAMD21J18A__
  PWM6_CH0 = TC6_CH0,
  PWM6_CH1 = TC6_CH1,
  PWM7_CH0 = TC7_CH0,
  PWM7_CH1 = TC7_CH1,
  #endif // __SAMD21J18A__
  } EPWMChannel ;

  // Pin Attributes to be OR-ed

  #define PIN_ATTR_NONE          (0UL<<0)
  #define PIN_ATTR_COMBO         (1UL<<0)
  #define PIN_ATTR_ANALOG        (1UL<<1)
  #define PIN_ATTR_DIGITAL       (1UL<<2)
  #define PIN_ATTR_PWM           (1UL<<3)
  #define PIN_ATTR_TIMER         (1UL<<4)
  #define PIN_ATTR_TIMER_ALT     (1UL<<5)
  #define PIN_ATTR_EXTINT        (1UL<<6)

  // Types used for the table below
  typedef struct _PinDescription
  {
  EPortType       ulPort;
  uint32_t        ulPin;
  EPioType        ulPinType;
  uint32_t        ulPinAttribute ;
  EAnalogChannel  ulADCChannelNumber;   // ADC Channel number in the SAM device
  EPWMChannel     ulPWMChannel;
  ETCChannel      ulTCChannel;
  EExt_Interrupts ulExtInt;
  } PinDescription;

  #define TCC_INST_NUM      3

  #define TC_INST_NUM       3   // For SAMD21E16A, SAMD21E17A, SAMD21E18A, SAMD21G15A, SAMD21G16A, SAMD21G18A
  #define TC_INST_NUM       5   // For SAMD21J15A, SAMD21J16A, SAMD21J17A, SAMD21J18A

  // MKRZero, MKR1000, Nano_33_IoT, MKRFox1200, MKRWAN1300, MKRGSM1400, MKRNB1500, MKRWiFi1010, MKRVidor4000, CircuitPlay
  const void* g_apTCInstances[TCC_INST_NUM + TC_INST_NUM] = { TCC0, TCC1, TCC2, TC3, TC4, TC5 };

  #define GetTCNumber( x )        ( (x) >> 8 )
  #define GetTCChannelNumber( x ) ( (x) & 0xff )
  #define GetTC( x )              ( g_apTCInstances[(x) >> 8] )

  #define GCLK_CLKCTRL_ID_Pos         0
  #define GCLK_CLKCTRL_ID_Msk         (0x3Fu << GCLK_CLKCTRL_ID_Pos)
  #define GCLK_CLKCTRL_ID(value)      ((GCLK_CLKCTRL_ID_Msk & ((value) << GCLK_CLKCTRL_ID_Pos)))

*************************************/

////////////////////////////////////////

#define INVALID_SAMD_PIN          255

////////////////////////////////////////

#define MAX_16BIT                 65535UL

#define MAX_COUNT_16BIT           65536UL

////////////////////////////////////////


static bool tcEnabled[TCC_INST_NUM + TC_INST_NUM] = { false };

////////////////////////////////////////
////////////////////////////////////////

class SAMD_PWM
{
  public:

    // dutycycle = 0.0f - 100.0f
    SAMD_PWM(const uint8_t& pin, const float& frequency, const float& dutycycle)
    {
      _pinDesc  = g_APinDescription[pin];
      _pinAttr  = _pinDesc.ulPinAttribute;

      _tcNum    = GetTCNumber(_pinDesc.ulPWMChannel);
      _tcChannel = GetTCChannelNumber(_pinDesc.ulPWMChannel);


#if defined(__SAMD51__)

      // For Adafruit SAMD core
      if (_pinAttr & (PIN_ATTR_PWM_E | PIN_ATTR_PWM_F | PIN_ATTR_PWM_G))
#else
      if (_pinAttr & PIN_ATTR_PWM)
#endif
      {
        _pin        = pin;
        _frequency  = frequency;

        _dutycycle  = round(map(dutycycle, 0, 100.0f, 0, MAX_COUNT_16BIT));

        // Calc prescaler and _compareValue
        // Check which timer to use
        if (_tcNum >= TCC_INST_NUM)
        {
          calcTCPrescaler(frequency);
        }
        else
        {
          calcTCCPrescaler(frequency);
        }

        //////////////////////////////////////

        pinMode(pin, OUTPUT);

        return;
      }

      PWM_LOGDEBUG1(F("SAMD_PWM: error not PWM pin ="), pin);
    }

    ///////////////////////////////////////////

    ~SAMD_PWM();

    ///////////////////////////////////////////
    ///////////////////////////////////////////

  private:

    void calcTCCPrescaler(const float& frequency)
    {
      uint32_t period = 1000000 / frequency;

      if (period > 300000)
      {
        // Set prescaler to 1024
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV1024;
        _prescaler = 1024;
      }
      else if (80000 < period && period <= 300000)
      {
        // Set prescaler to 256
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV256;
        _prescaler = 256;
      }
      else if (20000 < period && period <= 80000)
      {
        // Set prescaler to 64
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV64;
        _prescaler = 64;
      }
      else if (10000 < period && period <= 20000)
      {
        // Set prescaler to 16
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV16;
        _prescaler = 16;
      }
      else if (5000 < period && period <= 10000)
      {
        // Set prescaler to 8
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV8;
        _prescaler = 8;
      }
      else if (2500 < period && period <= 5000)
      {
        // Set prescaler to 4
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV4;
        _prescaler = 4;
      }
      else if (1000 < period && period <= 2500)
      {
        // Set prescaler to 2
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV2;
        _prescaler = 2;
      }
      else if (period <= 1000)
      {
        // Set prescaler to 1
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV1;
        _prescaler = 1;
      }

      _compareValue = (uint32_t)( F_CPU / (_prescaler / (period / 1000000.0))) - 1;


      PWM_LOGDEBUG7(F("calcTCCPrescaler: OK pin ="), _pin, F(", period ="), period, F(", _prescaler ="), _prescaler,
                    F(", F_CPU ="), F_CPU);

      PWM_LOGDEBUG7(F("calcTCCPrescaler: _dutycycle ="), _dutycycle, F(", frequency ="), frequency,
                    F(", _prescalerConfigBits ="), _prescalerConfigBits, F(", _compareValue ="), _compareValue);
    }

    ///////////////////////////////////////////

    // _compareValue max 8-bit = 255
    void calcTCPrescaler(const float& frequency)
    {
      uint32_t period = 1000000 / frequency;

      uint32_t newPeriod = period / 256;

      if (newPeriod > 300000)
      {
        // Set prescaler to 1024
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV1024;
        _prescaler = 1024;
      }
      else if (80000 < newPeriod && newPeriod <= 300000)
      {
        // Set prescaler to 256
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV256;
        _prescaler = 256;
      }
      else if (20000 < newPeriod && newPeriod <= 80000)
      {
        // Set prescaler to 64
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV64;
        _prescaler = 64;
      }
      else if (10000 < newPeriod && newPeriod <= 20000)
      {
        // Set prescaler to 16
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV16;
        _prescaler = 16;
      }
      else if (5000 < newPeriod && newPeriod <= 10000)
      {
        // Set prescaler to 8
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV8;
        _prescaler = 8;
      }
      else if (2500 < newPeriod && newPeriod <= 5000)
      {
        // Set prescaler to 4
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV4;
        _prescaler = 4;
      }
      else if (1000 < newPeriod && newPeriod <= 2500)
      {
        // Set prescaler to 2
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV2;
        _prescaler = 2;
      }
      else if (newPeriod <= 1000)
      {
        // Set prescaler to 1
        _prescalerConfigBits = TC_CTRLA_PRESCALER_DIV1;
        _prescaler = 1;
      }

      _compareValue = (uint32_t)( F_CPU / (_prescaler / (period / 1000000.0))) - 1;

      PWM_LOGDEBUG7(F("calcTCPrescaler: OK pin ="), _pin, F(", period ="), period, F(", _prescaler ="), _prescaler,
                    F(", F_CPU ="), F_CPU);

      PWM_LOGDEBUG7(F("calcTCPrescaler: _dutycycle ="), _dutycycle, F(", frequency ="), frequency,
                    F(", _prescalerConfigBits ="), _prescalerConfigBits, F(", _compareValue ="), _compareValue);
    }

    ///////////////////////////////////////////
    ///////////////////////////////////////////

  public:

    // dutycycle from 0-65535 for 0%-100%
    bool setPWM_Int(const uint8_t& pin, const float& frequency, const uint16_t& dutycycle)
    {
      bool freqChange = false;

      // Reprogram freq if necessary
      if ( frequency != _frequency)
      {
        PWM_LOGDEBUG3(F("setPWM_Int: change frequency to"), frequency, F("from"), _frequency);

        _frequency = frequency;
        freqChange = true;

        // Recalc _compareValue
        // Check which timer to use
        if (_tcNum >= TCC_INST_NUM)
        {
          calcTCPrescaler(frequency);
        }
        else
        {
          calcTCCPrescaler(frequency);
        }
      }

      _dutycycle = dutycycle;

      ////////////////////////////////////////

#if defined(__SAMD51__)

      ////////////////////////////////////////

      if (_pinAttr & (PIN_ATTR_PWM_E | PIN_ATTR_PWM_F | PIN_ATTR_PWM_G))
      {
        PWM_LOGDEBUG5(F("SAMD51 setPWM_Int: _tcNum ="), _tcNum, F(", _tcChannel ="), _tcChannel,
                      F(", _pinAttr ="), _pinAttr);

        // To avoid uint32_t overflow
        uint32_t newDC = ( (float) dutycycle / MAX_COUNT_16BIT ) * _compareValue;

        PWM_LOGDEBUG7(F("SAMD51 setPWM_Int: newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                      F(", _compareValue ="), _compareValue, F(", frequency ="), frequency);

        // For Adafruit SAMD51
        if (_pinAttr & PIN_ATTR_PWM_E)
        {
          pinPeripheral(pin, PIO_TIMER);
        }
        else if (_pinAttr & PIN_ATTR_PWM_F)
        {
          pinPeripheral(pin, PIO_TIMER_ALT);
        }
        else if (_pinAttr & PIN_ATTR_PWM_G)
        {
          pinPeripheral(pin, PIO_TCC_PDEC);
        }

        if ( (!tcEnabled[_tcNum]) || freqChange )
        {
          // New pin or freqChange
          tcEnabled[_tcNum] = true;

          //use clock generator 0
          GCLK->PCHCTRL[GCLK_CLKCTRL_IDs[_tcNum]].reg = GCLK_PCHCTRL_GEN_GCLK0_Val | (1 << GCLK_PCHCTRL_CHEN_Pos);

          // Check which timer to use
          if (_tcNum >= TCC_INST_NUM)
          {
            // Convert to 8-bit
            newDC = newDC >> 8;

            // Must use 8-bit for old TC PWM
            PWM_LOGDEBUG7(F("SAMD51 setPWM_Int: New TC => newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                          F(", _compareValue ="), _compareValue >> 8, F(", frequency ="), frequency);

            // -- Configure TC
            Tc* TCx = (Tc*) GetTC(_pinDesc.ulPWMChannel);

            //reset
            TCx->COUNT8.CTRLA.bit.SWRST = 1;

            while (TCx->COUNT8.SYNCBUSY.bit.SWRST);

            // Disable TCx
            TCx->COUNT8.CTRLA.bit.ENABLE = 0;

            while (TCx->COUNT8.SYNCBUSY.bit.ENABLE);

            // Set Timer counter Mode to 8 bits, normal PWM, PRESCALER_DIV256
            TCx->COUNT8.CTRLA.reg = TC_CTRLA_MODE_COUNT8 | TC_CTRLA_PRESCALER_DIV256;
            TCx->COUNT8.WAVE.reg = TC_WAVE_WAVEGEN_NPWM;

            while (TCx->COUNT8.SYNCBUSY.bit.CC0);

            // Set the Dutycycle
            TCx->COUNT8.CC[_tcChannel].reg = (uint8_t) newDC;

            while (TCx->COUNT8.SYNCBUSY.bit.CC0);

            // Set PER to _compareValue for PWM frequency
            // convert to 8-bit
            TCx->COUNT8.PER.reg = _compareValue >> 8;

            while (TCx->COUNT8.SYNCBUSY.bit.PER);

            // Enable TCx
            TCx->COUNT8.CTRLA.bit.ENABLE = 1;

            while (TCx->COUNT8.SYNCBUSY.bit.ENABLE);
          }
          else
          {
            PWM_LOGDEBUG7(F("SAMD51 setPWM_Int: New TCC => newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                          F(", _compareValue ="), _compareValue, F(", frequency ="), frequency);

            // -- Configure TCC
            Tcc* TCCx = (Tcc*) GetTC(_pinDesc.ulPWMChannel);

            TCCx->CTRLA.bit.SWRST = 1;

            while (TCCx->SYNCBUSY.bit.SWRST);

            // Disable TCCx
            TCCx->CTRLA.bit.ENABLE = 0;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            // Set prescaler
            TCCx->CTRLA.reg |= _prescalerConfigBits;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            // Set TCx as normal PWM
            TCCx->WAVE.reg = TCC_WAVE_WAVEGEN_NPWM;

            while ( TCCx->SYNCBUSY.bit.WAVE );

            while (TCCx->SYNCBUSY.bit.CC0 || TCCx->SYNCBUSY.bit.CC1);

            // Set the Dutycycle
            TCCx->CC[_tcChannel].reg = (uint32_t) newDC;

            while (TCCx->SYNCBUSY.bit.CC0 || TCCx->SYNCBUSY.bit.CC1);

            // Set PER to _compareValue for PWM frequency
            TCCx->PER.reg = _compareValue;

            while (TCCx->SYNCBUSY.bit.PER);

            // Enable TCCx
            TCCx->CTRLA.bit.ENABLE = 1;

            while (TCCx->SYNCBUSY.bit.ENABLE);
          }
        }
        else
        {
          // Old pin and same freq
          // Check which timer to use
          if (_tcNum >= TCC_INST_NUM)
          {
            // Convert to 8-bit
            newDC = newDC >> 8;

            PWM_LOGDEBUG7(F("SAMD51 setPWM_Int: Old TC => newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                          F(", _compareValue ="), _compareValue >> 8, F(", frequency ="), frequency);

            Tc* TCx = (Tc*) GetTC(_pinDesc.ulPWMChannel);

            // Set the Dutycycle
            TCx->COUNT8.CC[_tcChannel].reg = (uint8_t) newDC;

            while (TCx->COUNT8.SYNCBUSY.bit.CC0 || TCx->COUNT8.SYNCBUSY.bit.CC1);
          }
          else
          {
            PWM_LOGDEBUG7(F("SAMD51 setPWM_Int: Old TCC => newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                          F(", _compareValue ="), _compareValue, F(", frequency ="), frequency);

            Tcc* TCCx = (Tcc*) GetTC(_pinDesc.ulPWMChannel);

            while (TCCx->SYNCBUSY.bit.CTRLB);

            while (TCCx->SYNCBUSY.bit.CC0 || TCCx->SYNCBUSY.bit.CC1);

            // Set the Dutycycle
            TCCx->CCBUF[_tcChannel].reg = (uint32_t) newDC;

            while (TCCx->SYNCBUSY.bit.CC0 || TCCx->SYNCBUSY.bit.CC1);

            TCCx->CTRLBCLR.bit.LUPD = 1;

            while (TCCx->SYNCBUSY.bit.CTRLB);
          }
        }

        return true;
      }

      ////////////////////////////////////////

#else

      ////////////////////////////////////////

      // Arduino or Adafruit SAMD21
      if (_pinAttr & PIN_ATTR_PWM)
      {
        PWM_LOGDEBUG5(F("SAMD21 setPWM_Int: _tcNum ="), _tcNum, F(", _tcChannel ="), _tcChannel,
                      F(", _pinAttr ="), _pinAttr);

        // To avoid uint32_t overflow
        uint32_t newDC = ( (float) dutycycle / MAX_COUNT_16BIT ) * _compareValue;

        PWM_LOGDEBUG7(F("SAMD21 setPWM_Int: newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                      F(", _compareValue ="), _compareValue, F(", frequency ="), frequency);

        if (_pinAttr & PIN_ATTR_TIMER)
        {
          pinPeripheral(pin, PIO_TIMER);
        }
        else
        {
          pinPeripheral(pin, PIO_TIMER_ALT);
        }

        if ( (!tcEnabled[_tcNum]) || freqChange )
        {
          // New pin or freqChange
          tcEnabled[_tcNum] = true;

          uint16_t GCLK_CLKCTRL_IDs[] =
          {
            GCLK_CLKCTRL_ID(GCM_TCC0_TCC1), // TCC0
            GCLK_CLKCTRL_ID(GCM_TCC0_TCC1), // TCC1
            GCLK_CLKCTRL_ID(GCM_TCC2_TC3),  // TCC2
            GCLK_CLKCTRL_ID(GCM_TCC2_TC3),  // TC3
            GCLK_CLKCTRL_ID(GCM_TC4_TC5),   // TC4
            GCLK_CLKCTRL_ID(GCM_TC4_TC5),   // TC5
            GCLK_CLKCTRL_ID(GCM_TC6_TC7),   // TC6
            GCLK_CLKCTRL_ID(GCM_TC6_TC7),   // TC7
          };

          GCLK->CLKCTRL.reg = (uint16_t) (GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN_GCLK0 | GCLK_CLKCTRL_IDs[_tcNum]);

          while (GCLK->STATUS.bit.SYNCBUSY == 1);

          // Check which timer to use
          if (_tcNum >= TCC_INST_NUM)
          {
            // Convert to 8-bit
            newDC = newDC >> 8;

            // Must use 8-bit for old TC PWM
            PWM_LOGDEBUG7(F("SAMD21 setPWM_Int: New TC => newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                          F(", _compareValue ="), _compareValue >> 8, F(", frequency ="), frequency);

            // -- Configure TC
            Tc* TCx = (Tc*) GetTC(_pinDesc.ulPWMChannel);

            //reset
            TCx->COUNT8.CTRLA.bit.SWRST = 1;

            while (TCx->COUNT16.STATUS.bit.SYNCBUSY);

            // Disable TCx
            TCx->COUNT8.CTRLA.bit.ENABLE = 0;

            while (TCx->COUNT16.STATUS.bit.SYNCBUSY);

            // Set Timer counter Mode to 8 bits, normal PWM, PRESCALER_DIV256
            TCx->COUNT16.CTRLA.reg |= TC_CTRLA_MODE_COUNT8 | TC_CTRLA_WAVEGEN_NPWM | TC_CTRLA_PRESCALER_DIV256;

            while (TCx->COUNT16.STATUS.bit.SYNCBUSY);

            // Set the Dutycycle
            TCx->COUNT8.CC[_tcChannel].reg = (uint8_t) newDC;

            while (TCx->COUNT16.STATUS.bit.SYNCBUSY);

            // Set PER to _compareValue to match frequency
            // convert to 8-bit
            TCx->COUNT8.PER.reg = _compareValue >> 8;

            while (TCx->COUNT16.STATUS.bit.SYNCBUSY);

            // Enable TCx
            TCx->COUNT8.CTRLA.bit.ENABLE = 1;

            while (TCx->COUNT16.STATUS.bit.SYNCBUSY);
          }
          else
          {
            PWM_LOGDEBUG5(F("SAMD21 setPWM_Int: New TCC => newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                          F(", frequency ="), frequency);

            // -- Configure TCC
            Tcc* TCCx = (Tcc*) GetTC(_pinDesc.ulPWMChannel);

            // Disable TCCx
            TCCx->CTRLA.bit.ENABLE = 0;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            // Set prescaler
            TCCx->CTRLA.reg |= _prescalerConfigBits;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            // Set TCCx as normal PWM
            TCCx->WAVE.reg |= TCC_WAVE_WAVEGEN_NPWM;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            // Set the Dutycycle
            TCCx->CC[_tcChannel].reg = newDC;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            // Set PER to _compareValue to match frequency
            TCCx->PER.reg = _compareValue;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            // Enable TCCx
            TCCx->CTRLA.bit.ENABLE = 1;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);
          }
        }
        else
        {
          // Old pin and same freq
          // Check which timer to use
          if (_tcNum >= TCC_INST_NUM)
          {
            PWM_LOGDEBUG5(F("SAMD21 setPWM_Int: Old TC => newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                          F(", frequency ="), frequency);

            Tc* TCx = (Tc*) GetTC(_pinDesc.ulPWMChannel);

            // Set the Dutycycle
            TCx->COUNT16.CC[_tcChannel].reg = newDC;

            while (TCx->COUNT16.STATUS.bit.SYNCBUSY);
          }
          else
          {
            PWM_LOGDEBUG5(F("SAMD21 setPWM_Int: Old TCC => newDC ="), newDC, F(", input dutycycle ="), dutycycle,
                          F(", frequency ="), frequency);

            Tcc* TCCx = (Tcc*) GetTC(_pinDesc.ulPWMChannel);
            TCCx->CTRLBSET.bit.LUPD = 1;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            // Set the Dutycycle
            TCCx->CCB[_tcChannel].reg = newDC;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

            TCCx->CTRLBCLR.bit.LUPD = 1;

            while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);
          }
        }

        return true;
      }

#endif    //#if defined(__SAMD51__)     

      ////////////////////////////////////////

      return false;
    }

    ///////////////////////////////////////////

    bool setPWM()
    {
      return setPWM_Int(_pin, _frequency, _dutycycle);
    }

    ///////////////////////////////////////////

    bool setPWM(const uint8_t& pin, const float& frequency, const float& dutycycle)
    {
      //_dutycycle = round(map(dutycycle, 0, 100.0f, 0, MAX_COUNT_16BIT));
      _dutycycle = round(map(dutycycle, 0, 100.0f, 0, MAX_16BIT));

      PWM_LOGDEBUG3(F("setPWM: _dutycycle ="), _dutycycle, F(", frequency ="), frequency);

      return setPWM_Int(pin, frequency, _dutycycle);
    }

    ///////////////////////////////////////////

    bool setPWM_Period(const uint8_t& pin, const float& period_us, const float& dutycycle)
    {
      _dutycycle = round(map(dutycycle, 0, 100.0f, 0, MAX_COUNT_16BIT));

      PWM_LOGDEBUG3(F("setPWM_Period: _dutycycle ="), _dutycycle, F(", period_us ="), period_us);

      return setPWM_Int(pin, round(1000000.0f / period_us), _dutycycle);
    }

    ///////////////////////////////////////////

    // Must have same frequency
    // From v1.0.1-, DCValue = 0-100
    // From v1.2.0+, DCValue = 0-65535
    bool setPWM_manual(const uint8_t& pin, const uint16_t& dutyCycle)
    {
      // Not the same pin or overvalue
      if ( (_pin != pin) || (dutyCycle >=  (1 << _resolution) ) )
        return false;
        
      uint16_t DCValue = ( (uint32_t) dutyCycle * 100 ) / MAX_16BIT;

#if defined(__SAMD51__)
      // Check which timer to use
      if (_tcNum >= TCC_INST_NUM)
      {
        Tc* TCx = (Tc*) GetTC(_pinDesc.ulPWMChannel);

        // Set the DC value, 8-bit
        //TCx->COUNT8.CC[_tcChannel].reg = (DCValue * _compareValue / 100) >> 8;

        //while (TCx->COUNT16.STATUS.bit.SYNCBUSY);
        
        // Set the Dutycycle
        TCx->COUNT8.CC[_tcChannel].reg = (DCValue * _compareValue / 100) >> 8;

        while (TCx->COUNT8.SYNCBUSY.bit.CC0);

        PWM_LOGDEBUG3(F("setPWM_manual TC: DCValue ="), DCValue, F(", _frequency ="), _frequency);
        PWM_LOGDEBUG3(F("setPWM_manual TC: New DCValue ="), DCValue * _compareValue / 100, F(", _compareValue ="),
                      _compareValue);
      }
#else
      // Check which timer to use
      if (_tcNum >= TCC_INST_NUM)
      {
        Tc* TCx = (Tc*) GetTC(_pinDesc.ulPWMChannel);

        // Set the DC value, 8-bit
        TCx->COUNT8.CC[_tcChannel].reg = (DCValue * _compareValue / 100) >> 8;

        while (TCx->COUNT16.STATUS.bit.SYNCBUSY);

        PWM_LOGDEBUG3(F("setPWM_manual TC: DCValue ="), DCValue, F(", _frequency ="), _frequency);
        PWM_LOGDEBUG3(F("setPWM_manual TC: New DCValue ="), DCValue * _compareValue / 100, F(", _compareValue ="),
                      _compareValue);
      }
#endif      
      else
      {
        Tcc* TCCx = (Tcc*) GetTC(_pinDesc.ulPWMChannel);

        // DCValue from 0-100
        TCCx->CC[_tcChannel].reg = DCValue * _compareValue / 100;

        while (TCCx->SYNCBUSY.reg & TCC_SYNCBUSY_MASK);

        PWM_LOGDEBUG3(F("setPWM_manual TCC: DCValue ="), DCValue, F(", _frequency ="), _frequency);
        PWM_LOGDEBUG3(F("setPWM_manual TCC: New DCValue ="), DCValue * _compareValue / 100, F(", _compareValue ="),
                      _compareValue);                               
      }

      _dutycycle = dutyCycle;

      return true;
    }
    
    ///////////////////////////////////////////
       
    // Faster than setPWM_DCPercentage_manual by not using float
    // DCPercentage from 0-65535 for 0.0f - 100.0f
    bool setPWM_DCPercentageInt_manual(const uint8_t& pin, const uint16_t& DCPercentage)
    {    
      _dutycycle = DCPercentage;
      
      // Convert to DCValue based on resolution = MAX_16BIT
      PWM_LOGDEBUG3(F("setPWM_DCPercentage_manual: DCPercentage ="), DCPercentage, F(", dc ="), ( DCPercentage * MAX_16BIT ) / 100.0f);
      
      return setPWM_manual(pin, _dutycycle);
    }
    
    ///////////////////////////////////////////
    
    // DCPercentage from 0.0f - 100.0f
    bool setPWM_DCPercentage_manual(const uint8_t& pin, const float& DCPercentage)
    {
      // Convert to 0-65535
      _dutycycle = ( DCPercentage * MAX_16BIT ) / 100.0f;
      
      // Convert to DCValue based on resolution = MAX_16BIT
      PWM_LOGDEBUG3(F("setPWM_DCPercentage_manual: DCPercentage ="), DCPercentage, F(", dc ="), ( DCPercentage * MAX_16BIT ) / 100.0f);
      
      return setPWM_manual(pin, _dutycycle);
    }

    ///////////////////////////////////////////

    inline float getActualDutyCycle()
    {
      return ( ( (float) _dutycycle ) * 100 / (1 << _resolution) );
    }

    ///////////////////////////////////////////

    inline float getActualFreq()
    {
      return _frequency;
    }

    ///////////////////////////////////////////

    inline float getPWMPeriod()
    {
      return (1000000.0f / _frequency);
    }

    ///////////////////////////////////////////

    inline uint32_t get_freq_CPU()
    {
      return F_CPU;
    }

    ///////////////////////////////////////////

    inline uint32_t getPin()
    {
      return _pin;
    }

    ///////////////////////////////////////////

    void setResolution(const uint8_t& resolution)
    {
      // Must be <= 16-bit and >= 8-bit
      if ( (resolution <= 16) && (resolution >= 8) )
        _resolution = resolution;
    }

    ///////////////////////////////////////////////////////////////////

  private:

    PinDescription _pinDesc;
    uint32_t      _pinAttr;

    float         _frequency;

    // For PWM frequency TOP register
    uint32_t      _compareValue;

    // dutycycle from 0-65535 for 0%-100% to make use of full 16-bit TOP register
    uint32_t      _dutycycle;

    uint32_t      _prescalerConfigBits;
    uint16_t      _prescaler = 1;

    // Timer info
    uint32_t      _tcNum;
    uint8_t       _tcChannel;

    uint8_t       _pin = INVALID_SAMD_PIN;

    // In number of bits
    uint8_t       _resolution = 16;

    ///////////////////////////////////////////
};

///////////////////////////////////////////


#endif    // SAMD_PWM_H

