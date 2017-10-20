#pragma once

#include <fstream>

// chess piece constants
#define B_KING 'k'
#define B_QUEEN 'q'
#define B_BISHOP 'b'
#define B_ROOK 'r'
#define B_KNIGHT 'n'
#define B_PAWN 'p'
#define W_KING 'K'
#define W_QUEEN 'Q'
#define W_BISHOP 'B'
#define W_ROOK 'R'
#define W_KNIGHT 'N'
#define W_PAWN 'P'
#define EMPTY ' '

// logging macros
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

// exception class for the group of errors related to file IO
class FileException : public std::exception
{
public:
  FileException()
  {
    this->message = "File IO error.";
  }

  FileException(const std::string message)
  {
    this->message = message;
  }

  virtual std::string what()
  {
    return this->message;
  }
private:
  std::string message;
};

// what level should we log at?
enum LOG_LEVEL
{
  LOG_LEVEL_TRACE = 0,
  LOG_LEVEL_INFO = 1,
  LOG_LEVEL_WARNING = 2,
  LOG_LEVEL_ERROR = 3,
  LOG_LEVEL_FATAL = 4
};

class Logger
{
private:
  // member variables
  LOG_LEVEL LogLevel;
  std::ofstream LogFile;

public:
  // constructor
  Logger(LOG_LEVEL logLevel);

  // open file to write log to disk
  void OpenLogFileForWriting();

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

  void WriteLogHTMLFooter();
private:
  // helper method to write HTML header for logfile
  void WriteLogHTMLHeader();
};
