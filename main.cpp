// LOCAL INCLUDES
#include "chesspp.h"
#include "common.h"
#include <iostream>
#include <cstdlib>
#include "board.h"
#include "ai_test.h"

// Qt INCLUDES
#include <QtWidgets/QApplication>

// constants
const bool runAiTests = true;

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
  LOG_TRACE("Logger sucessfully initialized.");

  if (runAiTests)
  {
    ai_test aiTest;
    aiTest.runAll();
  }

  QApplication a(argc, argv);
  chesspp w;
  w.show();
  int retVal = a.exec();
  atexit(closeLogger);
  return retVal;
}
