#include "Headers/blink.h"
#include <wiringPi.h>

blink::blink()
{
    wiringPiSetup () ;
    pinMode (0, OUTPUT) ;
}

void blink::ledOn(){
    digitalWrite (0, HIGH) ;
}

void blink::ledOff(){
    digitalWrite (0,  LOW) ;
}
