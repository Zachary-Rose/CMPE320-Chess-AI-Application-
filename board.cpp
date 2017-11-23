// Local includes
#include "board.h"
#include "common.h"
#include "move.h"

// System includes
#include <iostream>
#include <vector>

//--------------------------------------------------------------------------------
Board::Board()
  : CurrentBoard({
    {W_ROOK, W_KNIGHT, W_BISHOP, W_KING  , W_QUEEN, W_BISHOP, W_KNIGHT, W_ROOK},
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
char Board::GetPieceByPosition(BoardPosition& bp)
{
  LOG_TRACE("char Board::GetPieceByPosition(BoardPosition& bp)");
  int i = bp.i();
  int j = bp.j();

  return GetPieceByPosition(i, j);
}

//--------------------------------------------------------------------------------
boardRepresentation Board::GetBoard()
{
  LOG_TRACE("GetBoard()");

  return this->CurrentBoard;
}

//--------------------------------------------------------------------------------
void Board::SetPiece(int i, int j, char piece)
{
  LOG_TRACE("void Board::SetPiece(int i, int j, char piece)");
  CurrentBoard[i][j] = piece;
}

//--------------------------------------------------------------------------------
void Board::SetPiece(BoardPosition& bp, char piece)
{
  LOG_TRACE("void Board::SetPiece(BoardPosition& bp, char piece)");
  int i = bp.i();
  int j = bp.j();
  
  SetPiece(i, j, piece);
}

//--------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream &os, Board &b)
{
  LOG_TRACE("operator<<(std::ostream &os, board &b)");
  os << std::endl;
  for (int i = 7; i >= 0; i--)
  {
    os << "   +---+---+---+---+---+---+---+---+" << std::endl;
    os << " " << i << " ";
    for (int j = 0; j < 8; j++)
    {
      os << "| " << b.CurrentBoard[i][j] << " ";
    }
    os << "|" << std::endl;
  }
  os << "   +---+---+---+---+---+---+---+---+" << std::endl;
  os << "     0   1   2   3   4   5   6   7" << std::endl;
  return os;
}