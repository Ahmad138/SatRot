#include "main.h"

int main(int argc, char *argv[])
{
    //ctor

    //blink b;
    a4988Driver AzDriver(0, 1, 2, 3, 4, 5);

    helper hh;
    while(true){
        AzDriver.setDirection(CW);
        AzDriver.stepDegrees(90);
        //b.ledOn();
        //ui->ledStatus->setText("Led is ON");
        //AzDriver.setDirection(CW);
        //for(i = 0; i<360; i+=10){
            //AzDriver.stepDegrees(i);
            //hh.re_routeResources(10000);
        //}

        hh.re_routeResources(1000);

        AzDriver.setDirection(CCW);
        AzDriver.stepDegrees(180);
        //b.ledOff();
        //ui->ledStatus->setText("Led is OFF");
        //AzDriver.setDirection(CCW);
        //for(i = 360; i>0; i-=10){
         //   AzDriver.stepDegrees(i);
         //   hh.re_routeResources(10000);
       // }

        hh.re_routeResources(1000);
    }

    return 0;
}
