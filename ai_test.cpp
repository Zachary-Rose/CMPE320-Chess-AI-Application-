#include "ai_test.h"
#include "board.h"
#include "common.h"

#include <iostream>

ai_test::ai_test()
{
  LOG_TRACE("ai_test::ai_test()")
}

ai_test::~ai_test()
{
  LOG_TRACE("~ai_test::ai_test()")
}

void ai_test::runAll()
{
  LOG_TRACE("ai_test::runAll()")
  this->test_board();
}

void ai_test::test_board()
{
  LOG_TRACE("ai_test::test_board()");
  Board b1;
  LOG_INFO("Test operator<<. Log standard board")
  LOG_INFO(b1);
  LOG_INFO("Test GetPieceByPosition(int i, int j). Should be 'Q': " << b1.GetPieceByPosition(0, 3));
  LOG_INFO("Test GetPieceByPosition(int rank, char file) with lowercase. Should be 'n': " << b1.GetPieceByPosition(7, 'g'));
  LOG_INFO("Test GetPieceByPosition(int rank, char file) with uppercase. Should be 'n': " << b1.GetPieceByPosition(7, 'G'));
}