#include "ai_test.h"
#include "board.h"
#include "common.h"
#include "ai.h"
#include <iostream>
#include <vector>

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
  this->test_ai();
}

void ai_test::test_ai()
{
  LOG_TRACE("ai_test::test_board()");

  LOG_INFO("Test move generation:");
  Ai testAi;
  testAi.PrintBoard();
  std::vector<Move> moves = testAi.GenerateAllPossibleMoves();
  for (auto & move : moves)
  {
    LOG_INFO(move);
  }
}
