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
  for (auto& move : moves)
  {
    LOG_INFO(move);
  }

  // board position of white knight on (0,1)
  BoardPosition wk(0, 1);
  std::vector<Move> knightMoves = testAi.GetLegalPieceMoves(wk);
  LOG_INFO("Testing legal moves of single piece, in this case white knight on (0,1)");
  for (auto& move : knightMoves)
  {
    LOG_INFO(move);
  }
}
