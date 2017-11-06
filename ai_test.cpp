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
  this->test_board();
}

void ai_test::test_board()
{
  LOG_TRACE("ai_test::test_board()");
  Board b1;
  LOG_INFO("Test operator<<. Log standard board")
  LOG_INFO(b1);
	Ai ai;
	std::vector<Move> moves = ai.GenerateBishopMoves(2, 4);
	LOG_INFO("Queens Moves:" );
}
