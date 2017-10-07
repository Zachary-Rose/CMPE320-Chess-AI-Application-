// LOCAL INCLUDES
#include "common.h"

// STL INCLUDES
#include <iomanip>
#include <string>

//--------------------------------------------------------------------------------
Logger::Logger(const LOG_LEVEL logLevel)
{
  this->LogLevel = logLevel;
}

//--------------------------------------------------------------------------------
void Logger::LogTrace(std::string message, std::string file, int line)
{
  if (this->LogLevel <= TRACE)
  {
    std::cout << std::setw(7) << std::right << "TRACE"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
  }
}

//--------------------------------------------------------------------------------
void Logger::LogInfo(std::string message, std::string file, int line)
{
  if (this->LogLevel <= INFO)
  {
    std::cout << std::setw(7) << std::right << "INFO"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
  }
}

//--------------------------------------------------------------------------------
void Logger::LogWarning(std::string message, std::string file, int line)
{
  if (this->LogLevel <= WARNING)
  {
    std::cout << std::setw(7) << std::right << "WARNING"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
  }
}

//--------------------------------------------------------------------------------
void Logger::LogError(std::string message, std::string file, int line)
{
  if (this->LogLevel <= ERROR)
  {
    std::cout << std::setw(7) << std::right << "ERROR"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
  }
}

//--------------------------------------------------------------------------------
void Logger::LogFatal(std::string message, std::string file, int line)
{
  if (this->LogLevel <= FATAL)
  {
    std::cout << std::setw(7) << std::right << "FATAL"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
  }
}