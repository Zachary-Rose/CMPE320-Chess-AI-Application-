// local includes
#include "common.h"
#include "board.h"
#include "ai.h"
#include "ai_test.h"

// system includes
#include <iostream>
#include <cstdlib>

// Qt includes
#include <QtWidgets/QApplication>
#include "gui_game.h"

// constants
const bool runAiTests = true;

// global logger
Logger chessPPLogger(LOG_LEVEL_INFO);

// global GUI handle
Gui_Game* gui_game;
Ai* gui_ai;

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
  gui_game = new Gui_Game();
  gui_game->show();
  gui_game->displayMainMenu();
  gui_ai = new Ai();
  int retVal = a.exec();
  atexit(closeLogger);
  return retVal;
}
