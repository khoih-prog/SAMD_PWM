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

* [Changelog](#changelog)
  * [Releases v1.2.0](#Releases-v120)
  * [Releases v1.0.1](#Releases-v101)
  * [Releases v1.0.0](#releases-v100)

---
---

## Changelog

### Releases v1.2.0

1. Optimize speed with new `setPWM_DCPercentageInt_manual` function to improve speed almost 500 times compared to `setPWM`
2. Add example [PWM_manual](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_manual) to demo how to correctly use PWM to generate waveform. Check [About DCValue in setPWM_manual #2](https://github.com/khoih-prog/AVR_PWM/discussions/2)
3. Add example [PWM_SpeedTest](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_SpeedTest) to demo the better speed of new `setPWM_DCPercentageInt_manual` function
4. Breaking change: Modify `setPWM_manual` function to take `16-bit` dutycycle instead from merely `0-100` for better accuracy
5. Modify example [PWM_Waveform](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_Waveform) to adapt to breaking change of `setPWM_manual` function
6. Improve `README.md` so that links can be used in other sites, such as `PIO`
7. Bump up to v1.2.0 to sync with other Fast PWM libraries


### Releases v1.0.1

1. Add example [PWM_StepperControl](https://github.com/khoih-prog/SAMD_PWM/tree/main/examples/PWM_StepperControl) to demo how to control Stepper Motor using PWM. Check [Using PWM to step a stepper driver #16](https://github.com/khoih-prog/RP2040_PWM/issues/16)

### Releases v1.0.0

1. Initial coding for **SAMD21/SAMD51 boards** such as `NANO_33_IOT`, `ITSYBITSY_M4`, `SEEED_XIAO_M0`, `SparkFun SAMD51_Thing_Plus`, etc. using
- [Arduino SAMD core](https://github.com/arduino/ArduinoCore-samd)
- [Adafruit SAMD core](https://github.com/adafruit/ArduinoCore-samd)
- [Seeed-Studio SAMD core](https://github.com/Seeed-Studio/ArduinoCore-samd)
- [Sparkfun SAMD core](https://github.com/sparkfun/Arduino_Boards)
- [Industruino SAMD core](https://github.com/Industruino/IndustruinoSAMD)



---
---

## Copyright

Copyright 2022- Khoi Hoang


