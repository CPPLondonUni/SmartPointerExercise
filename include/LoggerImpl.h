#ifndef __LOGGERIMPL_H__
#define __LOGGERIMPL_H__
#include "ILogger.h"

#include <fstream>

class LoggerImpl : public ILogger
{
public:
    LoggerImpl(std::string fileName) : logFile{fileName, std::fstream::ate} {}
    
    ~LoggerImpl()
    {
        logFile.flush();
        logFile.close();
    }
public:
    void Log(ILogger::LogLevel lLevel, std::string msg) override
    {
        if(lLevel & ILogger::LogLevel::ERROR)
        {
            logFile << msg;
        }
    }
    
private:
    std::ofstream logFile;
};

#endif
