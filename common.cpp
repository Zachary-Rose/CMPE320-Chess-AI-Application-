// LOCAL INCLUDES
#include "common.h"

// STL INCLUDES
#include <iomanip>
#include <string>

// PLATFORM DEPENDENT INCLUDES
#ifdef _WIN32
#include <Windows.h>
#endif
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
#ifdef _WIN32
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hstdout, &bufferInfo);
    SetConsoleTextAttribute(hstdout, 0x0B);
    std::cout << std::setw(7) << std::right << "TRACE" << "| " << message;
    SetConsoleTextAttribute(hstdout, 0x0F);
    std::cout << " <" << file << ", " << line << ">" << std::endl;
    SetConsoleTextAttribute(hstdout, bufferInfo.wAttributes);
#else
    std::cout << std::setw(7) << std::right << "TRACE"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
#endif
  }
}

//--------------------------------------------------------------------------------
void Logger::LogInfo(std::string message, std::string file, int line)
{
  if (this->LogLevel <= INFO)
  {
#ifdef _WIN32
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hstdout, &bufferInfo);
    SetConsoleTextAttribute(hstdout, 0x0D);
    std::cout << std::setw(7) << std::right << "INFO" << "| " << message;
    SetConsoleTextAttribute(hstdout, 0x0F);
    std::cout << " <" << file << ", " << line << ">" << std::endl;
    SetConsoleTextAttribute(hstdout, bufferInfo.wAttributes);
#else
    std::cout << std::setw(7) << std::right << "INFO"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
#endif
  }
}

//--------------------------------------------------------------------------------
void Logger::LogWarning(std::string message, std::string file, int line)
{
  if (this->LogLevel <= WARNING)
  {
#ifdef _WIN32
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hstdout, &bufferInfo);
    SetConsoleTextAttribute(hstdout, 0x0E);
    std::cout << std::setw(7) << std::right << "WARNING" << "| " << message;
    SetConsoleTextAttribute(hstdout, 0x0F);
    std::cout << " <" << file << ", " << line << ">" << std::endl;
    SetConsoleTextAttribute(hstdout, bufferInfo.wAttributes);
#else
    std::cout << std::setw(7) << std::right << "WARNING"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
#endif
  }
}

//--------------------------------------------------------------------------------
void Logger::LogError(std::string message, std::string file, int line)
{
  if (this->LogLevel <= ERROR)
  {
#ifdef _WIN32
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hstdout, &bufferInfo);
    SetConsoleTextAttribute(hstdout, 0x0C);
    std::cout << std::setw(7) << std::right << "ERROR" << "| " << message;
    SetConsoleTextAttribute(hstdout, 0x0F);
    std::cout << " <" << file << ", " << line << ">" << std::endl;
    SetConsoleTextAttribute(hstdout, bufferInfo.wAttributes);
#else
    std::cout << std::setw(7) << std::right << "ERROR"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
#endif
  }
}

//--------------------------------------------------------------------------------
void Logger::LogFatal(std::string message, std::string file, int line)
{
  if (this->LogLevel <= FATAL)
  {
#ifdef _WIN32
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hstdout, &bufferInfo);
    SetConsoleTextAttribute(hstdout, 0xCF);
    std::cout << std::setw(7) << std::right << "FATAL" << "| " << message;
    std::cout << " <" << file << ", " << line << ">" << std::endl;
    SetConsoleTextAttribute(hstdout, bufferInfo.wAttributes);
#else
    std::cout << std::setw(7) << std::right << "FATAL"
      << "| " << message << " <" << file << ", "
      << line << ">" << std::endl;
#endif
  }
}