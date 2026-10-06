#include "announce.h"
#include "logger.h"
#include <wiringPi.h> 

static const char *const TAG = "Announce";
const int leds[4] = {11,13,15}; 

void blink(int led){ 
    digitalWrite(led, HIGH); 
    delay(30); 
    digitalWrite(led, LOW); 
    delay(30);
} 

void light_leds(void){  
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
    pinMode(BUZZER_PIN,PWM_OUTPUT);
    pwmWrite(BUZZER_PIN, 500); 
}

void stop_alarm(void){
    for (int i = 0; i < 3; i++) { 
        digitalWrite(leds[i], LOW);
    }
    pwmWrite(BUZZER_PIN, 0);     
}

void start_actuator(void){
    log_debug(TAG, "Starting to make noise...");
    wiringPiSetupPhys();
    start_buzzer();
    light_leds();
    stop_alarm();
    log_debug(TAG, "stopping...");
}