#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <cstdint>
#include <string>

class ILogger
{
public:
    enum class LogLevel : uint16_t {
      INFO = 1,
      WARNING = (1 << 1),
      DEBUG = (1 << 2),
      ERROR = (1 << 3)
    };
    
public:
    virtual ~ILogger() = default;
    virtual void Log(LogLevel, std::string msg) = 0;
};

#endif
