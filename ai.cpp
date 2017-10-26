#include "ai.h"
#include "common.h"

//--------------------------------------------------------------------------------
Ai::Ai()
{
  LOG_TRACE("Ai::Ai()");
}

//--------------------------------------------------------------------------------
Ai::~Ai()
{
  LOG_TRACE("Ai::~Ai()");
}

//--------------------------------------------------------------------------------
Move Ai::GetBestMove(PLAYER WhosTurnIsIt)
{
  LOG_TRACE("Move Ai::GetBestMove(PLAYER WhosTurnIsIt)");
  return Move();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GetLegalPieceMoves(const BoardPosition& bp)
{
  LOG_TRACE("std::vector<Move> Ai::GetLegalPieceMoves(const BoardPosition& bp)");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
Move Ai::ExecuteMove(PLAYER WhosTurnIsIt, Move move)
{
  LOG_TRACE("Move Ai::ExecuteMove(PLAYER WhosTurnIsIt, Move move)");
  return Move();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateRookMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateRookMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateKnightMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateKnightMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateBishopMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateBishopMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateKingMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateKingMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateQueenMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateQueensMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GeneratePawnMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GeneratePawnMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateAllPossibleMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateAllPossibleMoves()");
  return std::vector<Move>();
}