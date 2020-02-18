#ifndef API_H
#define API_H

#define BOOST_LOG_DYN_LINK 1 // necessary when linking the boost_log library dynamically

#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup.hpp>

#include <restc-cpp/restc-cpp.h>
#include <restc-cpp/RequestBuilder.h>

class api
{
public:
    api();
    void sample();
};

#endif // API_H
