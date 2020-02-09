#include "Headers/blink.h"
#include "wiringpi.h"

blink::blink()
{
    wiringPiSetup () ;
    pinMode (0, OUTPUT) ;
}

void blink::ledOn(){
    digitalWrite (0, HIGH) ; delay (500) ;
}

void blink::ledOff(){
    digitalWrite (0,  LOW) ; delay (500) ;
}
