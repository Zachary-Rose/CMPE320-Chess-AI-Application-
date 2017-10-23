// Local includes
#include "board.h"
#include "common.h"

// System includes
#include <iostream>

//--------------------------------------------------------------------------------
Board::Board()
  : CurrentBoard({
    {W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN , W_KING , W_BISHOP, W_KNIGHT, W_ROOK},
    {W_PAWN, W_PAWN  , W_PAWN  , W_PAWN  , W_PAWN , W_PAWN  , W_PAWN  , W_PAWN},
    {EMPTY , EMPTY   , EMPTY   , EMPTY   , EMPTY  , EMPTY   , EMPTY   , EMPTY },
    {EMPTY , EMPTY   , EMPTY   , EMPTY   , EMPTY  , EMPTY   , EMPTY   , EMPTY },
    {EMPTY , EMPTY   , EMPTY   , EMPTY   , EMPTY  , EMPTY   , EMPTY   , EMPTY },
    {EMPTY , EMPTY   , EMPTY   , EMPTY   , EMPTY  , EMPTY   , EMPTY   , EMPTY },
    {B_PAWN, B_PAWN  , B_PAWN  , B_PAWN  , B_PAWN , B_PAWN  , B_PAWN  , B_PAWN},
    {B_ROOK, B_KNIGHT, B_BISHOP, B_KING  , B_QUEEN, B_BISHOP, B_KNIGHT, B_ROOK}})
{
  LOG_TRACE("board::board()")
}

//--------------------------------------------------------------------------------
Board::~Board()
{
  LOG_TRACE("board::~board()");
}

//--------------------------------------------------------------------------------
char Board::GetPieceByPosition(int i, int j)
{
  LOG_TRACE("board::GetPieceByPosition(int i, int j)");
  if (i < 0 || i > 7 || j < 0 || j > 7)
  {
    LOG_WARNING("Invalid index provided to GetPieceByPosition");
  }
  return CurrentBoard[i][j];
}

//--------------------------------------------------------------------------------
char Board::GetPieceByPosition(int rank, char file)
{
  LOG_TRACE("board::GetPieceByPosition(int rank, char file)");
  int j;
  const int ascii_A = 'A';
  const int ascii_H = 'H';
  const int ascii_a = 'a';
  const int ascii_h = 'h';
  if ('A' <= file && file <= 'H')
  {
    j = file - 'A';
  }
  else if ('a' <= file && file <= 'h')
  {
    j = file - 'a';
  }
  else
  {
    return EMPTY;
  }
  return this->GetPieceByPosition(rank, j);
}

//--------------------------------------------------------------------------------
boardRepresentation Board::GetBoard()
{
  LOG_TRACE("GetBoard()");

  return this->CurrentBoard;
}

//--------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream &os, Board &b)
{
  LOG_TRACE("operator<<(std::ostream &os, board &b)");
  os << std::endl;
  for (int i = 0; i < 8; i++)
  {
    os << "   +---+---+---+---+---+---+---+---+" << std::endl;
    os << " " << 7 - i << " ";
    for (int j = 0; j < 8; j++)
    {
      os << "| " << b.CurrentBoard[i][j] << " ";
    }
    os << "|" << std::endl;
  }
  os << "   +---+---+---+---+---+---+---+---+" << std::endl;
  os << "     A   B   C   D   E   F   G   H" << std::endl;
  return os;
}