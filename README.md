Files for MySensors 2.1.1 platform for Arduino which alow to build a gateway with W5100 ethernet and RFM69 radio modules.
===============================================================================

This repository contains files which alow you to run gateway with W5100 and RFM69 radio modules with software SPI, and should be replaced in original MySensors 2.1.1 library.

Just download it and put to your MySensors library folders:
- MyConfig.h to main MySensors folder,
- RFM69.cpp, RFM69.h to MySensors\drivers\RFM69 folder.

Examples folder contains sketches for:
- Ethernet Gateway,
- Ethernet Gateway as MQTT client,
- Light sensor node,

which are adopted to use with RFM69 radio module.

To use gateway (ethernet or MQTT) with RFM69 radio modules via software SPI you need to define in gateway sketch:
- select RFM69 radio, set its frequency and type:
<br>#define MY_RADIO_RFM69
<br>#define MY_RFM69_FREQUENCY RF69_868MHZ (or another frequency)
<br>#define MY_IS_RFM69HW
- define SoftSPI:
<br>#define MY_SOFTSPI
- and set pins for soft SPI bus (you can change pins number):
<br>#define MY_SOFT_SPI_SCK_PIN 14
<br>#define MY_SOFT_SPI_MISO_PIN 16
<br>#define MY_SOFT_SPI_MOSI_PIN 15
- set CS pin for RFM69 (you can change pin number)
<br>#define MY_RFM69_CS_PIN 17
- set pin for ATSHA204 (only if you want to use 17 pin for CS)
<br>#define MY_SIGNING_ATSHA204_PIN 18
