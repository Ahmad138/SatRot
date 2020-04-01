#include "helper.h"

helper::helper()
{
    //ctor
}

helper::~helper()
{
    //dtor
}

long helper::map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void helper::re_routeResources(long t){
    std::this_thread::sleep_for(std::chrono::microseconds(t));
}
