#include "announce.h"
#include "logger.h"
#include <wiringPi.h> 

static const char *const TAG = "Announce";
const int leds[4] = {17,27,22,23}; //DO NOT forget the resistors

void blink (const int led){ 
    digitalWrite(led, HIGH); 
    delay(30); 
    digitalWrite(led, LOW); 
    delay(30);
} 

void light_leds(void){  
    for (int i; i < 4; i++) { 
        pinMode(leds[i],OUTPUT); 
        delay(1); 
    } 
    
    for (int i; i < REPEAT_COUNT + 1; i++) { 
        for (int j = 0; j < 4; j++) { 
            blink(leds[j]); 
        } 
    } 
}

void start_buzzer(void){
    pinMode(BUZZER_PIN,PWM_OUTPUT);
    tone(BUZZER_PIN, 440, 500); 
}

void stop_alarm(void){
    for (int i; i < sizeof(leds); i++) { 
        digitalWrite(led, LOW);
    }
    tone(BUZZER_PIN, 0, 0);    
}

void start_actuator(void){
    log_debug(TAG, "Starting to make noise...");
    wiringPiSetupGpio();
    start_buzzer();
    light_leds();
    stop_alarm();
    log_debug(TAG, "stopping...");
}