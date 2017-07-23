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
 * Modified by Grzegorz Miasko
 *
 * DESCRIPTION
 * Example sketch showing how to measue light level using a LM393 photo-resistor
 * https://github.com/gieemek/RFM69_softSPI-for-MySensors-2.1.1
 */

// Enable debug prints to serial monitor
#define MY_DEBUG

// Enables and select radio type (if attached)
//#define MY_RADIO_NRF24
#define MY_RADIO_RFM69
// set frequency of RFM69 radio
//#define MY_RFM69_FREQUENCY RF69_433MHZ
#define MY_RFM69_FREQUENCY RF69_868MHZ
//#define MY_RFM69_FREQUENCY RF69_915MHZ
// Enable this if you're running the RFM69HW model
//#define MY_IS_RFM69HW

#include <MySensors.h>

#define CHILD_ID_LIGHT 0
#define LIGHT_SENSOR_ANALOG_PIN 0

unsigned long SLEEP_TIME = 30000; // Sleep time between reads (in milliseconds)

MyMessage msg(CHILD_ID_LIGHT, V_LIGHT_LEVEL);
int lastLightLevel;


void presentation()
{
	// Send the sketch version information to the gateway and Controller
	sendSketchInfo("Light Sensor", "1.0");

	// Register all sensors to gateway (they will be created as child devices)
	present(CHILD_ID_LIGHT, S_LIGHT_LEVEL);
}

void loop()
{
	int16_t lightLevel = (1023-analogRead(LIGHT_SENSOR_ANALOG_PIN))/10.23;
	Serial.println(lightLevel);
	if (lightLevel != lastLightLevel) {
		send(msg.set(lightLevel));
		lastLightLevel = lightLevel;
	}
	sleep(SLEEP_TIME);
}
