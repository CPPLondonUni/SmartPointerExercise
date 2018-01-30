#ifndef __EXERCISE1_H__
#define __EXERCISE1_H__
#include "ILogger.h"

#include <thread>
#include <chrono>

using namespace std::chrono_literals;   //never do this in an actual implementation (using namespace in a header)

class SuperImportantClass{
public:
    SuperImportantClass(ILogger& logger) : logger{logger} {}
    
public:
    void run(){
        logger.Log(ILogger::LogLevel::Error, "I am running now!"); //Everybody shall now this tidings of joy
        std::this_thread::sleep_for(1s);
        logger.Log(ILogger::LogLevel::Error, "I shall finish!");
    }
    
private:
    ILogger& logger;
};

#endif
