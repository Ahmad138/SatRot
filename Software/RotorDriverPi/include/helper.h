#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <chrono>
#include <thread>

class helper
{
    public:
        helper();
        virtual ~helper();

    /** Map one scale to another
     *
     *  @param
     *  x -> The value you want to rescale
     *  in_min -> Minimum input scale
     *  in_max -> Maximum input scale
     *  out_min -> Minimum ouput scale
     *  out_max -> Maximum output scale
     *
     *  @note This uses a long data type for variablility
     */
    long map(long x, long in_min, long in_max, long out_min, long out_max);

    /** Re-Route Resources
     *
     *  @param t -> The total time for the resource to be re-routed for
     *
     *  @note t must be a valid long data type
     */
    void re_routeResources(long t);

    protected:

    private:
};

#endif // HELPER_H
