#include "announce.h"
#include "logger.h"
#include <wiringPi.h> 

static const char *const TAG = "Announce";
const int leds[4] = {11,13,15}; 

void blink(int led){ 
    digitalWrite(led, HIGH); 
    delay(1000); 
    digitalWrite(led, LOW); 
    delay(1000);
} 

void light_leds(void){  
	log_debug(TAG, "Lights on...");
    for (int i = 0; i < 3; i++) { 
        pinMode(leds[i],OUTPUT); 
        delay(1); 
    } 
    
    for (int i = 0; i < REPEAT_COUNT + 1; i++) { 
        for (int j = 0; j < 3; j++) { 
            blink(leds[j]); 
        } 
    } 
}

void start_buzzer(void){
	log_debug(TAG, "Buzzer on...");
	delay(1000);
    pinMode(BUZZER_PIN,PWM_OUTPUT);
	pwmSetRange(1024);
    pwmWrite(BUZZER_PIN, 500); 
	log_debug(TAG, "Can you hear me?");
}

void stop_alarm(void){
    pwmWrite(BUZZER_PIN, 0);     
	log_debug(TAG, "Shutting up...");
}

void start_actuator(void){
    log_debug(TAG, "Starting to make noise...");
	delay(100);
    wiringPiSetupPhys();
    start_buzzer();
    light_leds();
    stop_alarm();
    log_debug(TAG, "stopping...");
}