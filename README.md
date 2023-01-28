# SAMD_PWM Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/SAMD_PWM.svg?)](https://www.ardu-badge.com/SAMD_PWM)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/SAMD_PWM.svg)](https://github.com/khoih-prog/SAMD_PWM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/SAMD_PWM/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/SAMD_PWM.svg)](http://github.com/khoih-prog/SAMD_PWM/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this SAMD_PWM library](#why-do-we-need-this-SAMD_PWM-library)
  * [Features](#features)
  * [Why using hardware-based PWM is better](#why-using-hardware-based-pwm-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Arduino SAMD boards](#1-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [2. For Adafruit SAMD boards](#2-for-adafruit-samd-boards)
  * [3. For Seeeduino SAMD boards](#3-for-seeeduino-samd-boards)
  * [4. For SparkFun SAMD boards](#4-for-SparkFun-samd-boards)
* [Usage](#usage)
  * [1. Create PWM Instance with Pin, Frequency, dutycycle, channel (default = 0) and PWM_resolution (default = 16)](#1-create-pwm-instance-with-pin-frequency-dutycycle-channel-default--0-and-pwm_resolution-default--16)
  * [2. Initialize PWM Instance](#2-Initialize-PWM-Instance)
  * [3. Set or change PWM frequency or dutyCycle](#3-set-or-change-PWM-frequency-or-dutyCycle)
  * [4. Set or change PWM frequency and dutyCycle manually and efficiently in waveform creation](#4-Set-or-change-PWM-frequency-and-dutyCycle-manually-and-efficiently-in-waveform-creation)
* [Examples](#examples)
  * [ 1. PWM_Basic](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Basic)
  * [ 2. PWM_DynamicDutyCycle](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_DynamicDutyCycle) 
  * [ 3. PWM_DynamicDutyCycle_Int](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_DynamicDutyCycle_Int)
  * [ 4. PWM_DynamicFreq](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_DynamicFreq)
  * [ 5. PWM_Multi](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Multi)
  * [ 6. PWM_MultiChannel](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_MultiChannel)
  * [ 7. PWM_Waveform](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Waveform)
  * [ 8. PWM_StepperControl](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_StepperControl) **New**
  * [ 9. PWM_manual](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_manual) **New**
  * [10. PWM_SpeedTest](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_SpeedTest) **New**
* [Example PWM_Multi](#example-PWM_Multi)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. PWM_DynamicDutyCycle on SAMD_NANO_33_IOT](#1-PWM_DynamicDutyCycle-on-SAMD_NANO_33_IOT)
  * [2. PWM_Multi on SAMD_NANO_33_IOT](#2-PWM_Multi-on-SAMD_NANO_33_IOT)
  * [3. PWM_DynamicFreq on ITSYBITSY_M4](#3-PWM_DynamicFreq-on-ITSYBITSY_M4)
  * [4. PWM_Waveform on ITSYBITSY_M4](#4-PWM_Waveform-on-ITSYBITSY_M4)
  * [5. PWM_Basic on ITSYBITSY_M4](#5-PWM_Basic-on-ITSYBITSY_M4)
  * [6. PWM_Basic on SAMD_NANO_33_IOT](#6-PWM_Basic-on-SAMD_NANO_33_IOT)
  * [7. PWM_manual on ITSYBITSY_M4](#7-PWM_manual-on-ITSYBITSY_M4)
  * [8. PWM_SpeedTest on ITSYBITSY_M4](#8-PWM_SpeedTest-on-ITSYBITSY_M4)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---


### Why do we need this [SAMD_PWM library](https://github.com/khoih-prog/SAMD_PWM)

### Features

This hardware-based PWM library enables you to use Hardware-PWM on **SAMD21/SAMD51 boards** such as `NANO_33_IOT`, `ITSYBITSY_M4`, `SEEED_XIAO_M0`, `SparkFun SAMD51_Thing_Plus`, etc., to create and output PWM. These purely hardware-based PWM channels can generate very high PWM frequencies, depending on CPU clock and acceptable accuracy. The maximum resolution can be **16-bit** for better accuracy when using Timer `TCCx`. With Timer `TCx`, only **8-bit** resolution is supported with lower accuracy.

This library is using the **same or similar functions** as other `FastPWM` sibling libraries, as follows, to enable you to **port your PWM code easily between platforms**

 1. [**RP2040_PWM**](https://github.com/khoih-prog/RP2040_PWM)
 2. [**AVR_PWM**](https://github.com/khoih-prog/AVR_PWM)
 3. [**megaAVR_PWM**](https://github.com/khoih-prog/megaAVR_PWM)
 4. [**ESP32_FastPWM**](https://github.com/khoih-prog/ESP32_FastPWM)
 5. [**SAMD_PWM**](https://github.com/khoih-prog/SAMD_PWM)
 6. [**SAMDUE_PWM**](https://github.com/khoih-prog/SAMDUE_PWM)
 7. [**nRF52_PWM**](https://github.com/khoih-prog/nRF52_PWM)
 8. [**Teensy_PWM**](https://github.com/khoih-prog/Teensy_PWM)
 9. [**ATtiny_PWM**](https://github.com/khoih-prog/ATtiny_PWM)
10. [**Dx_PWM**](https://github.com/khoih-prog/Dx_PWM)
11. [**Portenta_H7_PWM**](https://github.com/khoih-prog/Portenta_H7_PWM)
12. [**MBED_RP2040_PWM**](https://github.com/khoih-prog/MBED_RP2040_PWM)
13. [**nRF52_MBED_PWM**](https://github.com/khoih-prog/nRF52_MBED_PWM)
14. [**STM32_PWM**](https://github.com/khoih-prog/STM32_PWM)


---

The most important feature is they're purely hardware-based PWM channels. Therefore, their operations are **not blocked by bad-behaving software functions / tasks**.

This important feature is absolutely necessary for mission-critical tasks. These hardware PWM-channels, still work even if other software functions are blocking. Moreover, they are much more precise (certainly depending on clock frequency accuracy) than other software timers using `millis()` or `micros()`. That's necessary if you need to control external systems (Servo, etc.) requiring better accuracy.

New efficient `setPWM_manual()` function enables waveform creation using PWM.

The [**PWM_Multi**](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Multi) example will demonstrate the usage of multichannel PWM using multiple Hardware-PWM blocks (Timer & Channel). The 4 independent Hardware-PWM channels are used **to control 4 different PWM outputs**, with totally independent frequencies and dutycycles on `SAMD21/SAMD51`.

Being hardware-based PWM, their executions are not blocked by bad-behaving functions / tasks, such as connecting to WiFi, Internet or Blynk services.

This non-being-blocked important feature is absolutely necessary for mission-critical tasks.

---

### Why using hardware-based PWM is better

Imagine you have a system with a **mission-critical** function, controlling a robot or doing something much more important. You normally use a software timer to poll, or even place the function in `loop()`. But what if another function is **blocking** the `loop()` or `setup()`.

So your function **might not be executed, and the result would be disastrous.**

You'd prefer to have your function called, no matter what happening with other functions (busy loop, bug, etc.).

The correct choice is to use `hardware-based PWM`.

These hardware-based PWM channels still work even if other software functions are blocking. Moreover, they are much more **precise** (certainly depending on clock frequency accuracy) than other software-based PWMs, using `millis()` or `micros()`.

Functions using normal software-based PWMs, relying on `loop()` and calling `millis()`, won't work if the `loop()` or `setup()` is blocked by certain operation. For example, certain function is blocking while it's connecting to WiFi or some services.

---

### Currently supported Boards

  - **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**.
  - **Adafruit SAM21 (Itsy-Bitsy M0, Metro M0, Feather M0, Gemma M0, etc.)**.
  - **Adafruit SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
  - **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)** 
  - **Sparkfun SAMD21 boards** such as **SparkFun_RedBoard_Turbo, SparkFun_Qwiic_Micro, etc.**
  - **Sparkfun SAMD51 boards** such as **SparkFun_SAMD51_Thing_Plus, SparkFun_SAMD51_MicroMod, etc.**


---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino SAMD core 1.8.13+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 3. [`Adafruit SAMD core 1.7.11+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 4. [`Seeeduino SAMD core 1.8.3+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
 5. [`Sparkfun SAMD core 1.8.3+`](https://github.com/sparkfun/Arduino_Boards) for SAMD21/SAMD51 boards (SparkFun_RedBoard_Turbo, SparkFun_SAMD51_Thing_Plus, etc.)
 6. [Industruino SAMD core](https://github.com/Industruino/IndustruinoSAMD) for SAMD21/SAMD51 boards

  
---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**SAMD_PWM**](https://github.com/khoih-prog/SAMD_PWM), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/SAMD_PWM.svg?)](https://www.ardu-badge.com/SAMD_PWM) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**SAMD_PWM**](https://github.com/khoih-prog/SAMD_PWM) page.
2. Download the latest release `SAMD_PWM-main.zip`.
3. Extract the zip file to `SAMD_PWM-main` directory 
4. Copy whole `SAMD_PWM-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**SAMD_PWM** library](https://registry.platformio.org/libraries/khoih-prog/SAMD_PWM) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/SAMD_PWM/installation). Search for **SAMD_PWM** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Arduino SAMD boards
 
 ***To be able to compile without error and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.13) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.13).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.13. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.13/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 2. For Adafruit SAMD boards
 
 ***To be able to compile without error and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the files in [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.11) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.11). 

Supposing the Adafruit SAMD core version is 1.7.11. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.11/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 3. For Seeeduino SAMD boards
 
 ***To be able to compile without error and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the files in [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.3) into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3). 

Supposing the Seeeduino SAMD core version is 1.8.3. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.3/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 4. For SparkFun SAMD boards
 
 ***To be able to compile without error and automatically detect and display BOARD_NAME on SparkFun SAMD (XIAO SparkFun_RedBoard_Turbo, SparkFun_SAMD51_Thing_Plus, etc) boards***, you have to copy the file [SparkFun SAMD Packages_Patches](Packages_Patches/SparkFun/hardware/samd/1.8.3) into SparkFun samd directory (~/.arduino15/packages/SparkFun/hardware/samd/1.8.3). 

Supposing the SparkFun SAMD core version is 1.8.3. This file must be copied into the directory:

- `~/.arduino15/packages/SparkFun/hardware/samd/1.8.3/cores/arduino/Print.h`
- `~/.arduino15/packages/SparkFun/hardware/samd/1.8.3/cores/arduino/Print.cpp`
- `~/.arduino15/packages/SparkFun/hardware/samd/1.8.3/cores/arduino51/Print.h`
- `~/.arduino15/packages/SparkFun/hardware/samd/1.8.3/cores/arduino51/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/SparkFun/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/SparkFun/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`
- `~/.arduino15/packages/SparkFun/hardware/samd/x.yy.zz/cores/arduino51/Print.h`
- `~/.arduino15/packages/SparkFun/hardware/samd/x.yy.zz/cores/arduino51/Print.cpp`

---
---


## Usage

Before using any PWM `Timer` and `channel`, you have to make sure the `Timer` and `channel` has not been used by any other purpose.

```cpp
// Not OK for Nano_33_IoT (0, 1, 7, 8, 13, 14, 15 )
// OK for Nano_33_IoT (2, 3, 4, 5, 6, 9, 10, 11, 12, 16, 17)
// TCC OK => pin 4, 5, 6, 8, 9, 10, 11, 16/A2, 17/A3
// TC OK  => pin 12
// For ITSYBITSY_M4 
// 16-bit Higher accuracy, Lower Frequency, PWM Pin OK: TCCx: 0-2, 4, 5, 7, 9-13
//  8-bit Lower  accuracy, Hi Frequency,    PWM Pin OK: TCx: 18-20, 24-25
```

#### 1. Create PWM Instance with Pin, Frequency, dutycycle, channel (default = 0) and PWM_resolution (default = 16)

```cpp
SAMD_PWM* PWM_Instance;

PWM_Instance = new SAMD_PWM(pinToUse, frequency, dutyCycle, channel, PWM_resolution);
```

#### 2. Initialize PWM Instance

```cpp
if (PWM_Instance)
{
  PWM_Instance->setPWM();
}
```

#### 3. Set or change PWM frequency or dutyCycle

To use `float new_dutyCycle`

```cpp
PWM_Instance->setPWM(PWM_Pins, new_frequency, new_dutyCycle);
```

such as 

```cpp
dutyCycle = 10.0f;
  
Serial.print(F("Change PWM DutyCycle to ")); Serial.println(dutyCycle);
PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
```

---

To use `uint32_t new_dutyCycle` = `(real_dutyCycle * 65536) / 100`


```cpp
PWM_Instance->setPWM_Int(PWM_Pins, new_frequency, new_dutyCycle);
```

such as for `real_dutyCycle = 50%`

```cpp
// 50% dutyCycle = (real_dutyCycle * 65536) / 100
dutyCycle = 32768;

Serial.print(F("Change PWM DutyCycle to (%) "));
Serial.println((float) dutyCycle * 100 / 65536);
PWM_Instance->setPWM_Int(pinToUse, frequency, dutyCycle);
```

for `real_dutyCycle = 50%`

```cpp
// 20% dutyCycle = (real_dutyCycle * 65536) / 100
dutyCycle = 13107;

Serial.print(F("Change PWM DutyCycle to (%) "));
Serial.println((float) dutyCycle * 100 / 65536);
PWM_Instance->setPWM_Int(pinToUse, frequency, dutyCycle);
```

#### 4. Set or change PWM frequency and dutyCycle manually and efficiently in waveform creation

Function prototype

```cpp
// Must have same frequency
// From v1.0.1-, DCValue = 0-100
// From v1.2.0+, DCValue = 0-65535
bool setPWM_manual(const uint8_t& pin, const uint16_t& dutyCycle);

// DCPercentage from 0.0f - 100.0f
bool setPWM_DCPercentage_manual(const uint8_t& pin, const float& DCPercentage);

// DCPercentage from 0-65535 for 0.0f - 100.0f
bool setPWM_DCPercentageInt_manual(const uint8_t& pin, const uint16_t& DCPercentage);
```

Need to call only once for each pin


```cpp
PWM_Instance->setPWM(PWM_Pins, frequency, dutyCycle);
```

after that, if just changing `dutyCycle` / `level`, use the `faster`

```cpp
// dutycycle = 0-65535 for 0-100%
// 1084 ns
PWM_Instance->setPWM_manual(pinToUse, dutycycle);
```

or better and much easier to use, but `slowest`

```cpp
// 1259 ns
new_DCPercentage = 50.0f;
PWM_Instance->setPWM_DCPercentage_manual(pinToUse, new_DCPercentage);
```

or the **fastest**

```cpp
// dutycyclePercent = 0-65535 == 0-100%
// 1067 ns
dutycyclePercentInt = 1 << 15;   // 50%
PWM_Instance->setPWM_DCPercentageInt_manual(pinToUse, dutycyclePercentInt);
```

Don't use the extremely inefficient `setPWM()` for this purpose

```cpp
// Very inefficient, don't use => 499251 ns, 500-time slower
//PWM_Instance->setPWM(pinToUse, frequency, dutycyclePercent);
```


---
---

### Examples: 

 1. [PWM_Basic](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Basic)
 2. [PWM_DynamicDutyCycle](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_DynamicDutyCycle)
 3. [PWM_DynamicDutyCycle_Int](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_DynamicDutyCycle_Int)
 4. [PWM_DynamicFreq](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_DynamicFreq)
 5. [PWM_Multi](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Multi)
 6. [PWM_MultiChannel](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_MultiChannel)
 7. [PWM_Waveform](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Waveform)
 8. [PWM_StepperControl](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_StepperControl) **New**
 9. [PWM_manual](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_manual) **New**
10. [PWM_SpeedTest](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_SpeedTest) **New**

 
---
---

### Example [PWM_Multi](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Multi)

https://github.com/khoih-prog/SAMD_PWM/blob/aec5386c6bca3239de15f8e8053cad87f18bc708/examples/PWM_Multi/PWM_Multi.ino#L11-L112


---
---

### Debug Terminal Output Samples

### 1. PWM_DynamicDutyCycle on SAMD_NANO_33_IOT

The following is the sample terminal output when running example [PWM_DynamicDutyCycle](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_DynamicDutyCycle) on **SAMD21 SAMD_NANO_33_IOT**, to demonstrate the ability to provide high PWM frequencies and ability to change DutyCycle `on-the-fly` using **TCC** timer for 16-bit PWM


```cpp
Starting PWM_DynamicDutyCycle on SAMD_NANO_33_IOT
SAMD_PWM v1.0.1
[PWM] calcTCCPrescaler: OK pin = 11 , period = 200 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCCPrescaler: _dutycycle = 32768 , frequency = 5000.00 , _prescalerConfigBits = 0 , _compareValue = 9599
[PWM] SAMD21 setPWM_Int: _tcNum = 2 , _tcChannel = 0 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 4799 , input dutycycle = 32768 , _compareValue = 9599 , frequency = 5000.00
[PWM] SAMD21 setPWM_Int: New TCC => newDC = 4799 , input dutycycle = 32768 , frequency = 5000.00
=====================================================================================
Change PWM DutyCycle to 90.00
[PWM] setPWM: _dutycycle = 58982 , frequency = 5000.00
[PWM] SAMD21 setPWM_Int: _tcNum = 2 , _tcChannel = 0 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 8639 , input dutycycle = 58982 , _compareValue = 9599 , frequency = 5000.00
[PWM] SAMD21 setPWM_Int: Old TCC => newDC = 8639 , input dutycycle = 58982 , frequency = 5000.00
=====================================================================================
Actual data: pin = 11, PWM DC = 90.00, PWMPeriod = 200.00, PWM Freq (Hz) = 5000.0000
=====================================================================================
Change PWM DutyCycle to 20.00
[PWM] setPWM: _dutycycle = 13107 , frequency = 5000.00
[PWM] SAMD21 setPWM_Int: _tcNum = 2 , _tcChannel = 0 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 1919 , input dutycycle = 13107 , _compareValue = 9599 , frequency = 5000.00
[PWM] SAMD21 setPWM_Int: Old TCC => newDC = 1919 , input dutycycle = 13107 , frequency = 5000.00
=====================================================================================
Actual data: pin = 11, PWM DC = 20.00, PWMPeriod = 200.00, PWM Freq (Hz) = 5000.0000
=====================================================================================
Change PWM DutyCycle to 90.00
[PWM] setPWM: _dutycycle = 58982 , frequency = 5000.00
[PWM] SAMD21 setPWM_Int: _tcNum = 2 , _tcChannel = 0 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 8639 , input dutycycle = 58982 , _compareValue = 9599 , frequency = 5000.00
[PWM] SAMD21 setPWM_Int: Old TCC => newDC = 8639 , input dutycycle = 58982 , frequency = 5000.00
=====================================================================================
Actual data: pin = 11, PWM DC = 90.00, PWMPeriod = 200.00, PWM Freq (Hz) = 5000.0000
=====================================================================================
```

---

### 2. PWM_Multi on SAMD_NANO_33_IOT

The following is the sample terminal output when running example [**PWM_Multi**](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Multi) on **SAMD21 SAMD_NANO_33_IOT**, to demonstrate the ability to provide high PWM frequencies on multiple `PWM-capable` pins using **TCC** timer for 16-bit PWM

```cpp
Starting PWM_Multi on SAMD_NANO_33_IOT
SAMD_PWM v1.0.1
[PWM] calcTCCPrescaler: OK pin = 4 , period = 500 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCCPrescaler: _dutycycle = 6553 , frequency = 2000.00 , _prescalerConfigBits = 0 , _compareValue = 23999
[PWM] SAMD21 setPWM_Int: _tcNum = 1 , _tcChannel = 1 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 2399 , input dutycycle = 6553 , _compareValue = 23999 , frequency = 2000.00
[PWM] SAMD21 setPWM_Int: New TCC => newDC= 2399 , input dutycycle = 6553 , frequency = 2000.00
[PWM] calcTCCPrescaler: OK pin = 5 , period = 333 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCCPrescaler: _dutycycle = 19660 , frequency = 3000.00 , _prescalerConfigBits = 0 , _compareValue = 15983
[PWM] SAMD21 setPWM_Int: _tcNum = 0 , _tcChannel = 1 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 4794 , input dutycycle = 19660 , _compareValue = 15983 , frequency = 3000.00
[PWM] SAMD21 setPWM_Int: New TCC => newDC= 4794 , input dutycycle = 19660 , frequency = 3000.00
[PWM] calcTCCPrescaler: OK pin = 11 , period = 250 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCCPrescaler: _dutycycle = 32768 , frequency = 4000.00 , _prescalerConfigBits = 0 , _compareValue = 11999
[PWM] SAMD21 setPWM_Int: _tcNum = 2 , _tcChannel = 0 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 5999 , input dutycycle = 32768 , _compareValue = 11999 , frequency = 4000.00
[PWM] SAMD21 setPWM_Int: New TCC => newDC= 5999 , input dutycycle = 32768 , frequency = 4000.00
[PWM] calcTCPrescaler: OK pin = 12 , period = 125 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCPrescaler: _dutycycle = 58982 , frequency = 8000.00 , _prescalerConfigBits = 0 , _compareValue = 5999
[PWM] SAMD21 setPWM_Int: _tcNum = 3 , _tcChannel = 1 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 5399 , input dutycycle = 58982 , _compareValue = 5999 , frequency = 8000.00
[PWM] SAMD21 setPWM_Int: New TC => newDC = 21 , input dutycycle = 58982 , _compareValue = 23 , frequency = 8000.00
=====================================================================================
Index	Pin	PWM_freq	DutyCycle	Actual Freq
=====================================================================================
0	4	2000.00		10.00		2000.0000
1	5	3000.00		30.00		3000.0000
2	11	4000.00		50.00		4000.0000
3	12	8000.00		90.00		8000.0000
=====================================================================================
Actual data: pin = 4, PWM DC = 10.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=====================================================================================
=====================================================================================
Actual data: pin = 5, PWM DC = 30.00, PWMPeriod = 333.33, PWM Freq (Hz) = 3000.0000
=====================================================================================
=====================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 250.00, PWM Freq (Hz) = 4000.0000
=====================================================================================
=====================================================================================
Actual data: pin = 12, PWM DC = 90.00, PWMPeriod = 125.00, PWM Freq (Hz) = 8000.0000
=====================================================================================
```

---

### 3. PWM_DynamicFreq on ITSYBITSY_M4

The following is the sample terminal output when running example [**PWM_DynamicFreq**](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_DynamicFreq) on **SAMD51 ITSYBITSY_M4**, to demonstrate the ability to change dynamically PWM frequencies on SAMD51 using **TCC** timer for 16-bit PWM

```cpp
Starting PWM_DynamicFreq on ITSYBITSY_M4
SAMD_PWM v1.0.1
[PWM] calcTCCPrescaler: OK pin = 11 , period = 100 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCCPrescaler: _dutycycle = 32768 , frequency = 10000.00 , _prescalerConfigBits = 0 , _compareValue = 11999
[PWM] SAMD51 setPWM_Int: _tcNum = 0 , _tcChannel = 1 , _pinAttr = 512
[PWM] SAMD51 setPWM_Int: newDC = 5999 , input dutycycle = 32768 , _compareValue = 11999 , frequency = 10000.00
[PWM] SAMD51 setPWM_Int: New TCC => newDC = 5999 , input dutycycle = 32768 , _compareValue = 11999 , frequency = 10000.00
=====================================================================================
Change PWM Freq to 20000.00
[PWM] setPWM: _dutycycle = 32768 , frequency = 20000.00
[PWM] setPWM_Int: change frequency to 20000.00 from 10000.00
[PWM] calcTCCPrescaler: OK pin = 11 , period = 50 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCCPrescaler: _dutycycle = 32768 , frequency = 20000.00 , _prescalerConfigBits = 0 , _compareValue = 5999
[PWM] SAMD51 setPWM_Int: _tcNum = 0 , _tcChannel = 1 , _pinAttr = 512
[PWM] SAMD51 setPWM_Int: newDC = 2999 , input dutycycle = 32768 , _compareValue = 5999 , frequency = 20000.00
[PWM] SAMD51 setPWM_Int: New TCC => newDC = 2999 , input dutycycle = 32768 , _compareValue = 5999 , frequency = 20000.00
=====================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 50.00, PWM Freq (Hz) = 20000.0000
=====================================================================================
Change PWM Freq to 10000.00
[PWM] setPWM: _dutycycle = 32768 , frequency = 10000.00
[PWM] setPWM_Int: change frequency to 10000.00 from 20000.00
[PWM] calcTCCPrescaler: OK pin = 11 , period = 100 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCCPrescaler: _dutycycle = 32768 , frequency = 10000.00 , _prescalerConfigBits = 0 , _compareValue = 11999
[PWM] SAMD51 setPWM_Int: _tcNum = 0 , _tcChannel = 1 , _pinAttr = 512
[PWM] SAMD51 setPWM_Int: newDC = 5999 , input dutycycle = 32768 , _compareValue = 11999 , frequency = 10000.00
[PWM] SAMD51 setPWM_Int: New TCC => newDC = 5999 , input dutycycle = 32768 , _compareValue = 11999 , frequency = 10000.00
=====================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 100.00, PWM Freq (Hz) = 10000.0000
=====================================================================================
```

---


### 4. PWM_Waveform on ITSYBITSY_M4

The following is the sample terminal output when running example [**PWM_Waveform**](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Waveform) on **SAMD51 ITSYBITSY_M4**, to demonstrate how to use the `setPWM_manual()` function in wafeform creation using **TCC** timer for 16-bit PWM


```cpp
Starting PWM_Waveform on ITSYBITSY_M4
SAMD_PWM v1.0.1
[PWM] calcTCCPrescaler: OK pin = 11 , period = 1000 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCCPrescaler: _dutycycle = 0 , frequency = 1000.00 , _prescalerConfigBits = 0 , _compareValue = 119999
[PWM] setPWM: _dutycycle = 655 , frequency = 1000.00
[PWM] SAMD51 setPWM_Int: _tcNum = 0 , _tcChannel = 1 , _pinAttr = 512
[PWM] SAMD51 setPWM_Int: newDC = 1199 , input dutycycle = 655 , _compareValue = 119999 , frequency = 1000.00
[PWM] SAMD51 setPWM_Int: New TCC => newDC = 1199 , input dutycycle = 655 , _compareValue = 119999 , frequency = 1000.00
============================================================================================
Actual data: pin = 11, PWM DutyCycle = 0.00, PWMPeriod = 1000.00, PWM Freq (Hz) = 1000.0000
============================================================================================
[PWM] setPWM_manual: DCValue = 0 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 0 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 5 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 5999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 10 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 11999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 15 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 17999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 20 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 23999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 25 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 29999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 30 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 35999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 35 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 41999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 40 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 47999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 45 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 53999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 50 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 59999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 55 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 65999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 60 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 71999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 65 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 77999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 70 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 83999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 75 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 89999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 80 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 95999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 85 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 101999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 90 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 107999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 95 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 113999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 100 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 119999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 95 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 113999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 90 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 107999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 85 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 101999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 80 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 95999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 75 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 89999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 70 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 83999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 65 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 77999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 60 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 71999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 55 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 65999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 50 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 59999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 45 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 53999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 40 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 47999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 35 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 41999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 30 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 35999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 25 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 29999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 20 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 23999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 15 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 17999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 10 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 11999 , _compareValue = 119999
[PWM] setPWM_manual: DCValue = 5 , _frequency = 1000.00
[PWM] setPWM_manual: New DCValue = 5999 , _compareValue = 119999
```

---

### 5. PWM_Basic on ITSYBITSY_M4

The following is the sample terminal output when running example [**PWM_Basic**](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Basic) on **SAMD51 ITSYBITSY_M4**, to demonstrate how to use the basic function, using **TC** timer for 8-bit PWM


```cpp
Starting PWM_Basic on ITSYBITSY_M4
SAMD_PWM v1.0.1
[PWM] calcTCPrescaler: OK pin = 24 , period = 1000 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCPrescaler: _dutycycle = 0 , frequency = 1000.00 , _prescalerConfigBits = 0 , _compareValue = 119999
[PWM] setPWM: _dutycycle = 13107 , frequency = 2000.00
[PWM] setPWM_Int: change frequency to 2000.00 from 1000.00
[PWM] calcTCPrescaler: OK pin = 24 , period = 500 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCPrescaler: _dutycycle = 13107 , frequency = 2000.00 , _prescalerConfigBits = 0 , _compareValue = 59999
[PWM] SAMD51 setPWM_Int: _tcNum = 5 , _tcChannel = 1 , _pinAttr = 8
[PWM] SAMD51 setPWM_Int: newDC = 11999 , input dutycycle = 13107 , _compareValue = 59999 , frequency = 2000.00
[PWM] SAMD51 setPWM_Int: New TC => newDC = 46 , input dutycycle = 13107 , _compareValue = 234 , frequency = 2000.00
[PWM] setPWM: _dutycycle = 58982 , frequency = 5000.00
[PWM] setPWM_Int: change frequency to 5000.00 from 2000.00
[PWM] calcTCPrescaler: OK pin = 24 , period = 200 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCPrescaler: _dutycycle = 58982 , frequency = 5000.00 , _prescalerConfigBits = 0 , _compareValue = 23999
[PWM] SAMD51 setPWM_Int: _tcNum = 5 , _tcChannel = 1 , _pinAttr = 8
[PWM] SAMD51 setPWM_Int: newDC = 21598 , input dutycycle = 58982 , _compareValue = 23999 , frequency = 5000.00
[PWM] SAMD51 setPWM_Int: New TC => newDC = 84 , input dutycycle = 58982 , _compareValue = 93 , frequency = 5000.00
[PWM] setPWM: _dutycycle = 13107 , frequency = 2000.00
[PWM] setPWM_Int: change frequency to 2000.00 from 5000.00
[PWM] calcTCPrescaler: OK pin = 24 , period = 500 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCPrescaler: _dutycycle = 13107 , frequency = 2000.00 , _prescalerConfigBits = 0 , _compareValue = 59999
[PWM] SAMD51 setPWM_Int: _tcNum = 5 , _tcChannel = 1 , _pinAttr = 8
[PWM] SAMD51 setPWM_Int: newDC = 11999 , input dutycycle = 13107 , _compareValue = 59999 , frequency = 2000.00
[PWM] SAMD51 setPWM_Int: New TC => newDC = 46 , input dutycycle = 13107 , _compareValue = 234 , frequency = 2000.00
[PWM] setPWM: _dutycycle = 58982 , frequency = 5000.00
[PWM] setPWM_Int: change frequency to 5000.00 from 2000.00
[PWM] calcTCPrescaler: OK pin = 24 , period = 200 , _prescaler = 1 , F_CPU = 120000000
[PWM] calcTCPrescaler: _dutycycle = 58982 , frequency = 5000.00 , _prescalerConfigBits = 0 , _compareValue = 23999
[PWM] SAMD51 setPWM_Int: _tcNum = 5 , _tcChannel = 1 , _pinAttr = 8
[PWM] SAMD51 setPWM_Int: newDC = 21598 , input dutycycle = 58982 , _compareValue = 23999 , frequency = 5000.00
[PWM] SAMD51 setPWM_Int: New TC => newDC = 84 , input dutycycle = 58982 , _compareValue = 93 , frequency = 5000.00
```

---

### 6. PWM_Basic on SAMD_NANO_33_IOT

The following is the sample terminal output when running example [**PWM_Basic**](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Basic) on **SAMD21 SAMD_NANO_33_IOT**, to demonstrate how to use the basic function, using **TC** timer for 8-bit PWM

```cpp
Starting PWM_Basic on SAMD_NANO_33_IOT
SAMD_PWM v1.0.1
[PWM] calcTCPrescaler: OK pin = 12 , period = 1000 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCPrescaler: _dutycycle = 0 , frequency = 1000.00 , _prescalerConfigBits = 0 , _compareValue = 47999
[PWM] setPWM: _dutycycle = 13107 , frequency = 2000.00
[PWM] setPWM_Int: change frequency to 2000.00 from 1000.00
[PWM] calcTCPrescaler: OK pin = 12 , period = 500 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCPrescaler: _dutycycle = 13107 , frequency = 2000.00 , _prescalerConfigBits = 0 , _compareValue = 23999
[PWM] SAMD21 setPWM_Int: _tcNum = 3 , _tcChannel = 1 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 4799 , input dutycycle = 13107 , _compareValue = 23999 , frequency = 2000.00
[PWM] SAMD21 setPWM_Int: New TC => newDC = 18 , input dutycycle = 13107 , _compareValue = 93 , frequency = 2000.00
[PWM] setPWM: _dutycycle = 58982 , frequency = 5000.00
[PWM] setPWM_Int: change frequency to 5000.00 from 2000.00
[PWM] calcTCPrescaler: OK pin = 12 , period = 200 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCPrescaler: _dutycycle = 58982 , frequency = 5000.00 , _prescalerConfigBits = 0 , _compareValue = 9599
[PWM] SAMD21 setPWM_Int: _tcNum = 3 , _tcChannel = 1 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 8639 , input dutycycle = 58982 , _compareValue = 9599 , frequency = 5000.00
[PWM] SAMD21 setPWM_Int: New TC => newDC = 33 , input dutycycle = 58982 , _compareValue = 37 , frequency = 5000.00
[PWM] setPWM: _dutycycle = 13107 , frequency = 2000.00
[PWM] setPWM_Int: change frequency to 2000.00 from 5000.00
[PWM] calcTCPrescaler: OK pin = 12 , period = 500 , _prescaler = 1 , F_CPU = 48000000
[PWM] calcTCPrescaler: _dutycycle = 13107 , frequency = 2000.00 , _prescalerConfigBits = 0 , _compareValue = 23999
[PWM] SAMD21 setPWM_Int: _tcNum = 3 , _tcChannel = 1 , _pinAttr = 28
[PWM] SAMD21 setPWM_Int: newDC = 4799 , input dutycycle = 13107 , _compareValue = 23999 , frequency = 2000.00
[PWM] SAMD21 setPWM_Int: New TC => newDC = 18 , input dutycycle = 13107 , _compareValue = 93 , frequency = 2000.00
```


---

### 7. PWM_manual on ITSYBITSY_M4

The following is the sample terminal output when running example [**PWM_manual**](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_manual) on **SAMD51 ITSYBITSY_M4**, to demonstrate how to use the `setPWM_manual()` and `setPWM_DCPercentage_manual()` functions in wafeform creation


```cpp
Starting PWM_manual on ITSYBITSY_M4
SAMD_PWM v1.2.0
Not USING_DC_PERCENT
=================================================================================================
Actual data: pin = 11, PWM DC = 0.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 5.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 10.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 15.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 20.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 25.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 30.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 35.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 40.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 45.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 55.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 60.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 65.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 70.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 75.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 80.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 85.01, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 90.01, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 95.01, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 100.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 11, PWM DC = 0.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
...
```

---

### 8. PWM_SpeedTest on ITSYBITSY_M4

The following is the sample terminal output when running example [**PWM_SpeedTest**](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_SpeedTest) on **ITSYBITSY_M4**, to demonstrate how to use new faster `setPWM_manual()` function in wafeform creation, The time is `1084 ns` compared to `499,500 ns` when using `setPWM()` function. The fastest is `setPWM_DCPercentageInt_manual` with `1067 ns`, which is better to be used with pre-calculated values in array


##### USING_DC_PERCENT

```
Starting PWM_SpeedTest on ITSYBITSY_M4
SAMD_PWM v1.2.0
Average time of setPWM function USING_DC_PERCENT
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=937083, ns=1067
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=936335, ns=1067
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=936358, ns=1067
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=936334, ns=1067
...
```

##### USING_DC_PERCENT with extremely slow setPWM()

```
Starting PWM_SpeedTest on ITSYBITSY_M4
SAMD_PWM v1.2.0
Average time of setPWM function USING_DC_PERCENT
=================================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=2002, ns=499500
=================================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=2003, ns=499251
=================================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=2003, ns=499251
=================================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=2003, ns=499251
=================================================================================================
Actual data: pin = 11, PWM DC = 50.00, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=======================================================
```

##### not USING_DC_PERCENT

```cpp
Starting PWM_SpeedTest on ITSYBITSY_M4
SAMD_PWM v1.2.0
Average time of setPWM function not USING_DC_PERCENT
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=922600, ns=1083
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=921932, ns=1084
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=921965, ns=1084
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=921951, ns=1084
=================================================================================================
Actual data: pin = 11, PWM DC = 44.86, PWMPeriod = 500.00, PWM Freq (Hz) = 2000.0000
=================================================================================================
count=921942, ns=1084
```


---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level `_PWM_LOGLEVEL_` from 0 to 4

```cpp
// Don't define _PWM_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.
#define _PWM_LOGLEVEL_     0
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---

### Issues

Submit issues to: [SAMD_PWM issues](https://github.com/khoih-prog/SAMD_PWM/issues)

---
---

## TO DO

1. Search for bug and improvement.
2. Similar features for remaining Arduino boards

---

## DONE

 1. Basic hardware PWM-channels for **SAMD21/SAMD51 boards** such as `NANO_33_IOT`, `ITSYBITSY_M4`, `SEEED_XIAO_M0`, `SparkFun SAMD51_Thing_Plus`, etc. using
- [Arduino SAMD core](https://github.com/arduino/ArduinoCore-samd)
- [Adafruit SAMD core](https://github.com/adafruit/ArduinoCore-samd)
- [Seeed-Studio SAMD core](https://github.com/Seeed-Studio/ArduinoCore-samd)
- [Sparkfun SAMD core](https://github.com/sparkfun/Arduino_Boards)
- [Industruino SAMD core](https://github.com/Industruino/IndustruinoSAMD)
- [Industruino SAMx core](https://github.com/Industruino/IndustruinoSAMx)
 2. Add example [PWM_StepperControl](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_StepperControl) to demo how to control Stepper Motor using PWM
 3. Add example [PWM_manual](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_manual) to demo how to correctly use PWM to generate waveform
 4. Add function `setPWM_DCPercentage_manual()` to facilitate the setting PWM DC manually by using DCPercentage, instead of absolute DCValue depending on varying PWMPeriod
 5. Optimize speed with new `setPWM_DCPercentageInt_manual` function to improve speed almost 500 times compared to `setPWM`
 6. Add example [PWM_SpeedTest](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_SpeedTest) to demo the better speed of new `setPWM_DCPercentageInt_manual` function
 7. **Breaking change**: Modify `setPWM_manual` function to take `16-bit` dutycycle instead from merely `0-100` for better accuracy
 8. Modify example [PWM_Waveform](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Waveform) to adapt to breaking change of `setPWM_manual` function
 9. Improve `README.md` so that links can be used in other sites, such as `PIO`


 
---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Thanks to [Paul van Dinther](https://github.com/dinther) for proposing new way to use PWM to drive Stepper-Motor in [Using PWM to step a stepper driver #16](https://github.com/khoih-prog/RP2040_PWM/issues/16), leading to v2.0.3


<table>
  <tr>
    <td align="center"><a href="https://github.com/dinther"><img src="https://github.com/dinther.png" width="100px;" alt="dinther"/><br /><sub><b>Paul van Dinther</b></sub></a><br /></td>
  </tr>
</table>


---

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/SAMD_PWM/blob/main/LICENSE)

---

## Copyright

Copyright (c) 2022- Khoi Hoang


