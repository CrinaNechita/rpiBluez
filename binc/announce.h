#ifndef CRINA_ACTUATOR_H
#define CRINA_ACTUATOR_H

#include "logger.h"
#include <wiringPi.h> 

#define REPEAT_COUNT 7
#define BUZZER_PIN 12

void blink (const int led);

void light_leds(void);

void start_buzzer(void);

void stop_alarm(void);

void start_actuator(void);

#endif