// LOCAL INCLUDES
#include "chesspp.h"
#include "common.h"

// Qt INCLUDES
#include <QtWidgets/QApplication>

Logger chessPPLogger(TRACE);

int main(int argc, char *argv[])
{
  // silly logger testing code :)
  LOG_TRACE("Hello");
  LOG_INFO("To");
  LOG_WARNING("Team");
  LOG_ERROR("Buckhorn");
  LOG_FATAL("!");

  QApplication a(argc, argv);
  chesspp w;
  w.show();
  return a.exec();
}
