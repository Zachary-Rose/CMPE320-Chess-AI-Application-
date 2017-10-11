// LOCAL INCLUDES
#include "chesspp.h"
#include "common.h"
#include <iostream>
#include <cstdlib>

// Qt INCLUDES
#include <QtWidgets/QApplication>

// global logger
Logger chessPPLogger(LOG_LEVEL_TRACE);

// writes end of log file on application close
void closeLogger(void)
{
  chessPPLogger.WriteLogHTMLFooter();
}

void initialize()
{
  // open logfile for writing
  try
  {
    chessPPLogger.OpenLogFileForWriting();
  }
  catch (FileException &fe)
  {
    std::cout << fe.what() << std::endl;
  }
}

int main(int argc, char *argv[])
{
  initialize();

  // silly logger testing code :)
  LOG_TRACE("Hello");
  LOG_INFO("To");
  LOG_WARNING("Team");
  LOG_ERROR("Buckhorn");
  LOG_FATAL("!");

  LOG_TRACE("Logger sucessfully initialized.")

  QApplication a(argc, argv);
  chesspp w;
  w.show();
  int retVal = a.exec();
  atexit(closeLogger);
  return retVal;
}
