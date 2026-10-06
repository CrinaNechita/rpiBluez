#include "announce.h"
#include "logger.h"
#include <wiringPi.h> 
#include <softTone.h>

static const char *const TAG = "Announce";
const int leds[4] = {11,13,15}; 

void start_actuator(void){
	log_debug(TAG, "Starting to make noise...");
    if (wiringPiSetupPhys() == -1) {
        log_error(TAG, "Failed to initialise wiringpi");
    }
    start_buzzer();
    light_leds();
    stop_alarm();
    log_debug(TAG, "stopping...");
}

void blink(int led){ 
    digitalWrite(led, HIGH); 
    delay(300); 
    digitalWrite(led, LOW); 
    delay(100);
} 

void light_leds(void){  
    for (int i = 0; i < 3; i++) { 
        pinMode(leds[i],OUTPUT); 
		digitalWrite(leds[i], LOW);
    } 
    
    for (int i = 0; i < REPEAT_COUNT + 1; i++) { 
        for (int j = 0; j < 3; j++) { 
            blink(leds[j]); 
        } 
    } 
}

void start_buzzer(void){
	delay(1000);
	softToneCreate (BUZZER_PIN) ;
    softToneWrite (BUZZER_PIN, 450) ;
}

void stop_alarm(void){
    softToneWrite(BUZZER_PIN, 0);     
	log_debug(TAG, "Shutting up...");
}