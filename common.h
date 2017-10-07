#pragma once

#include <iostream>

#define LOG_TRACE(message) \
{ \
  chessPPLogger.LogTrace(message, __FILE__, __LINE__); \
}

#define LOG_INFO(message) \
{ \
  chessPPLogger.LogInfo(message, __FILE__, __LINE__); \
}

#define LOG_WARNING(message) \
{ \
  chessPPLogger.LogWarning(message, __FILE__, __LINE__); \
}

#define LOG_ERROR(message) \
{ \
  chessPPLogger.LogError(message, __FILE__, __LINE__); \
}

#define LOG_FATAL(message) \
{ \
  chessPPLogger.LogFatal(message, __FILE__, __LINE__); \
}


enum LOG_LEVEL
{
  TRACE = 0,
  INFO = 1,
  WARNING = 2,
  ERROR = 3,
  FATAL = 4
};

class Logger
{
private:
  // member variables
  LOG_LEVEL LogLevel;

public:
  // constructor
  Logger(LOG_LEVEL logLevel);

  // log a trace (i.e. method calls, other low importance data)
  void LogTrace(std::string message, std::string file, int line);

  // log info (something small but worth noting has occured)
  void LogInfo(std::string message, std::string file, int line);

  // log warning (something which may eventually cause an error)
  void LogWarning(std::string message, std::string file, int line);

  // log error (something unexpected has happened)
  void LogError(std::string message, std::string file, int line);

  // log fatal (something has happened which prevents the program continuing)
  void LogFatal(std::string message, std::string file, int line);
};