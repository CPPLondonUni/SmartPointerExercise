#ifndef __EXERCISE1_H__
#define __EXERCISE1_H__
#include "ILogger.h"

class SuperImportantClass {
 public:
  SuperImportantClass(ILogger& logger) : logger{logger} {}

 public:
  void run() {
    logger.Log(ILogger::LogLevel::ERROR,
               "I am running now!");  // Everybody shall now this tidings of joy
    auto i = 1 + 1;
    logger.Log(ILogger::LogLevel::ERROR, "I shall finish!");
  }

 private:
  ILogger& logger;
};

#endif
