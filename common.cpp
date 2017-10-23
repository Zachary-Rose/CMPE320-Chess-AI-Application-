// Local includes
#include "common.h"

// System includes
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

// Platform dependent includes
#ifdef _WIN32
  #include <Windows.h>
#else
  #include <sys/stat.h>
  const std::string logPath = "/Users/mark/Class/cisc320-proj/logs";
#endif

//--------------------------------------------------------------------------------
Logger::Logger(const LOG_LEVEL logLevel)
{
  this->LogLevel = logLevel;
}

void Logger::OpenLogFileForWriting()
{
  // create directory if doesn't exist
#ifdef _WIN32
  CreateDirectoryA("logs", NULL);
#else
  mkdir(logPath.c_str(), S_IRWXU);
#endif

  // generate filename & open file
  time_t now = time(0);
  struct tm tstruct;
  char timeCharArr[80];
  tstruct = *localtime(&now);
  strftime(timeCharArr, sizeof(timeCharArr), "_%F_%H.%M.%S", &tstruct);
  std::string timeString(timeCharArr);

#ifdef _WIN32
  std::string filename = "./logs/ChessPP" + timeString + ".html";
#else
  std::string filename = logPath + "/ChessPP" + timeString + ".html";
#endif

  this->LogFile.open(filename.c_str());
  if (!this->LogFile.is_open())
  {
    throw FileException("Cannot open new file for writing with name: " + filename + ".");
  }

  WriteLogHTMLHeader();
}

//--------------------------------------------------------------------------------
void Logger::WriteLogHTMLHeader()
{
  this->LogFile << "<!DOCTYPE html>" << std::endl;
  this->LogFile << "<head>" << std::endl;
  this->LogFile << "  <title>Chess++ Oct  7 2017, 19:48:21</title>" << std::endl;
  this->LogFile << "  <style>" << std::endl;
  this->LogFile << "    body {" << std::endl;
  this->LogFile << "      font-family: monospace;" << std::endl;
  this->LogFile << "      color: #FFFFFF;" << std::endl;
  this->LogFile << "      background-color: #000000;" << std::endl;
  this->LogFile << "    }" << std::endl;
  this->LogFile << "    .t{ Color: #00FFFF; }" << std::endl;
  this->LogFile << "    .i { color: #FF00FF; }" << std::endl;
  this->LogFile << "    .w { color: #FFFF00; }" << std::endl;
  this->LogFile << "    .e { color: #FF0000; }" << std::endl;
  this->LogFile << "    .f {" << std::endl;
  this->LogFile << "      color: #FFFFFF;" << std::endl;
  this->LogFile << "      background-color: #FF0000;" << std::endl;
  this->LogFile << "    }" << std::endl;
  this->LogFile << "    .fl { color: #FFFFFF; }" << std::endl;
  this->LogFile << "  </style>" << std::endl;
  this->LogFile << "</head>" << std::endl;
  this->LogFile << "<html>" << std::endl;
  this->LogFile << "  <body>" << std::endl;
  this->LogFile << "    <h1>Chess++ Logfile</h1>" << std::endl;
  this->LogFile << "    <h4>Oct  7 2017, 19:48:21</h4>" << std::endl;
  this->LogFile << "    <hr>" << std::endl;
  this->LogFile << "    <table>" << std::endl;
}

//--------------------------------------------------------------------------------
void Logger::WriteLogHTMLFooter()
{
  this->LogFile << "    </table>" << std::endl;
  this->LogFile << "  </body>" << std::endl;
  this->LogFile << "</html>" << std::endl;
}

//--------------------------------------------------------------------------------
void Logger::LogTrace(std::string message, std::string file, int line)
{
  if (this->LogLevel <= LOG_LEVEL_TRACE)
  {
    // log to console
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
    std::cout << "\033[36m" << std::setw(7) << std::right << "TRACE"
      << "| " << message << "\033[0m" << " <" << file << ", "
      << line << ">" << std::endl;
#endif

    // log to file
    this->LogFile << "      <tr class='t'>" << std::endl;
    this->LogFile << "        <td align='right'>TRACE|</td>" << std::endl;
    this->LogFile << "        <td>" << message << " <span class='fl'>&lt;" << file << ", " << line << "&gt;</span></td>" << std::endl;
    this->LogFile << "      </tr>" << std::endl;
  }
}

//--------------------------------------------------------------------------------
void Logger::LogInfo(std::string message, std::string file, int line)
{
  if (this->LogLevel <= LOG_LEVEL_INFO)
  {
    // log to console
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
    std::cout << "\033[35m" << std::setw(7) << std::right << "INFO"
      << "| " << message << "\033[0m" << " <" << file << ", "
      << line << ">" << std::endl;
#endif

    // log to file
    this->LogFile << "      <tr class='i'>" << std::endl;
    this->LogFile << "        <td align='right'>INFO|</td>" << std::endl;
    this->LogFile << "        <td>" << message << " <span class='fl'>&lt;" << file << ", " << line << "&gt;</span></td>" << std::endl;
    this->LogFile << "      </tr>" << std::endl;
  }
}

//--------------------------------------------------------------------------------
void Logger::LogWarning(std::string message, std::string file, int line)
{
  if (this->LogLevel <= LOG_LEVEL_WARNING)
  {
    // log to console
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
    std::cout << "\033[33m" << std::setw(7) << std::right << "WARNING"
      << "| " << message << "\03[0m" << " <" << file << ", "
      << line << ">" << std::endl;
#endif

    // log to file
    this->LogFile << "      <tr class='w'>" << std::endl;
    this->LogFile << "        <td align='right'>WARNING|</td>" << std::endl;
    this->LogFile << "        <td>" << message << " <span class='fl'>&lt;" << file << ", " << line << "&gt;</span></td>" << std::endl;
    this->LogFile << "      </tr>" << std::endl;
  }
}

//--------------------------------------------------------------------------------
void Logger::LogError(std::string message, std::string file, int line)
{
  // log to console
  if (this->LogLevel <= LOG_LEVEL_ERROR)
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
    std::cout << "\033[31m" << std::setw(7) << std::right << "ERROR"
      << "| " << message << "\033[0m" << " <" << file << ", "
      << line << ">" << std::endl;
#endif

    // log to file
    this->LogFile << "      <tr class='e'>" << std::endl;
    this->LogFile << "        <td align='right'>ERROR|</td>" << std::endl;
    this->LogFile << "        <td>" << message << " <span class='fl'>&lt;" << file << ", " << line << "&gt;</span></td>" << std::endl;
    this->LogFile << "      </tr>" << std::endl;
  }
}

//--------------------------------------------------------------------------------
void Logger::LogFatal(std::string message, std::string file, int line)
{
  // log to console
  if (this->LogLevel <= LOG_LEVEL_FATAL)
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
    std::cout << "\033[37;41m" << std::setw(7) << std::right << "FATAL"
      << "| " << message << "\033[0m" << " <" << file << ", "
      << line << ">" << std::endl;
#endif

    // log to file
    this->LogFile << "      <tr class='f'>" << std::endl;
    this->LogFile << "        <td align='right'>FATAL|</td>" << std::endl;
    this->LogFile << "        <td>" << message << " <span class='fl'>&lt;" << file << ", " << line << "&gt;</span></td>" << std::endl;
    this->LogFile << "      </tr>" << std::endl;
  }
}
