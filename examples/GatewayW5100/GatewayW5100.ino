/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * Modified by Grzegorz Miasko (23.07.2017)
 * for working with SoftSPI library in MySensors platform for Arduino
 * Documentation: https://github.com/gieemek/RFM69_softSPI-for-MySensors-2.1.1
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * REVISION HISTORY
 * Version 1.0 - Henrik EKblad
 * Contribution by a-lurker and Anticimex,
 * Contribution by Norbert Truchsess <norbert.truchsess@t-online.de>
 * Contribution by Tomas Hozza <thozza@gmail.com>
 * Modified by Grzegorz Miasko
 *
 *
 * DESCRIPTION
 * The EthernetGateway sends data received from sensors to the ethernet link.
 * The gateway also accepts input on ethernet interface, which is then sent out to the radio network.
 *
 * The GW code is designed for Arduino 328p / 16MHz.  ATmega168 does not have enough memory to run this program.
 *
 * LED purposes:
 * - To use the feature, uncomment MY_DEFAULT_xxx_LED_PIN in the sketch below
 * - RX (green) - blink fast on radio message recieved. In inclusion mode will blink fast only on presentation recieved
 * - TX (yellow) - blink fast on radio message transmitted. In inclusion mode will blink slowly
 * - ERR (red) - fast blink on error during transmission error or recieve crc error
 *
 * See http://www.mysensors.org/build/ethernet_gateway for wiring instructions.
 *
 */

// Enable debug prints to serial monitor
#define MY_DEBUG

// Enable and select radio type attached
//#define MY_RADIO_NRF24
#define MY_RADIO_RFM69
// set frequency of RFM69 radio
//#define MY_RFM69_FREQUENCY RF69_433MHZ
#define MY_RFM69_FREQUENCY RF69_868MHZ
//#define MY_RFM69_FREQUENCY RF69_915MHZ
// Enable this if you're running the RFM69HW model
//#define MY_IS_RFM69HW

// Enable gateway ethernet module type
#define MY_GATEWAY_W5100

// W5100 Ethernet module SPI enable (optional if using a shield/module that manages SPI_EN signal)
//#define MY_W5100_SPI_EN 4

// Enable Soft SPI for NRF radio (note different radio wiring is required)
// The W5100 ethernet module seems to have a hard time co-operate with
// radio on the same spi bus.
#if !defined(MY_W5100_SPI_EN) && !defined(ARDUINO_ARCH_SAMD)
#define MY_SOFTSPI
#define MY_SOFT_SPI_SCK_PIN 14
#define MY_SOFT_SPI_MISO_PIN 16
#define MY_SOFT_SPI_MOSI_PIN 15
#endif

// When W5100 is connected we have to move CS pins for RFM69 radio
#define MY_RFM69_CS_PIN 17
// if you want to use 17 pin for CS_PIN, you need to define diffrent MY_SIGNING_ATSHA204_PIN (not 17)
#define MY_SIGNING_ATSHA204_PIN 18

// Enable to UDP
//#define MY_USE_UDP

#define MY_IP_ADDRESS 192,168,178,66   // If this is disabled, DHCP is used to retrieve address
// Renewal period if using DHCP
//#define MY_IP_RENEWAL_INTERVAL 60000
// The port to keep open on node server mode / or port to contact in client mode
#define MY_PORT 5003

// Controller ip address. Enables client mode (default is "server" mode).
// Also enable this if MY_USE_UDP is used and you want sensor data sent somewhere.
//#define MY_CONTROLLER_IP_ADDRESS 192, 168, 178, 254

// The MAC address can be anything you want but should be unique on your network.
// Newer boards have a MAC address printed on the underside of the PCB, which you can (optionally) use.
// Note that most of the Ardunio examples use  "DEAD BEEF FEED" for the MAC address.
#define MY_MAC_ADDRESS 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED

// Enable inclusion mode
#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
//#define MY_INCLUSION_BUTTON_FEATURE
// Set inclusion mode duration (in seconds)
#define MY_INCLUSION_MODE_DURATION 60
// Digital pin used for inclusion mode button
//#define MY_INCLUSION_MODE_BUTTON_PIN  3

// Set blinking period
#define MY_DEFAULT_LED_BLINK_PERIOD 300

// Flash leds on rx/tx/err
// Uncomment to override default HW configurations
//#define MY_DEFAULT_ERR_LED_PIN 7  // Error led pin
//#define MY_DEFAULT_RX_LED_PIN  8  // Receive led pin
//#define MY_DEFAULT_TX_LED_PIN  9  // Transmit led pin


#if defined(MY_USE_UDP)
#include <EthernetUdp.h>
#endif
#include <Ethernet.h>
#include <MySensors.h>


void setup()
{
}

void loop()
{
}
