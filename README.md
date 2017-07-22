Files for MySensors 2.1.1 platform for Arduino which alow to build a gateway with W5100 and RFM69 radio modules as MQTT client.
===============================================================================

This repository contains files which alow you to run gateway with W5100 and RFM69 radio modules with software SPI, and should be replaced in original MySensors 2.1.1 library.

Just download it and put to your MySensors library folders:
- MyConfig.h to main MySensors folder,
- RFM69.cpp, RFM69.h to MySensors\drivers\RFM69 folder.

Examples folder contains sketches for:
- GatewayW5100MQTTClient,
- LightSensor,

which are adopted to use with RFM69 radio module.

To use gateway with RFM69 radio modules via software SPI
