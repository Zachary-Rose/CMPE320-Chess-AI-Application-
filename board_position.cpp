#include "board_position.h"
#include "common.h"

//--------------------------------------------------------------------------------
BoardPosition::BoardPosition()
{
  LOG_TRACE("BoardPosition::BoardPosition()");
  this->Pos_i = -1;
  this->Pos_j = -1;
}

//--------------------------------------------------------------------------------
BoardPosition::BoardPosition(int Pos_i, int Pos_j)
{
  LOG_TRACE("BoardPosition::BoardPosition(int Pos_i, int Pos_j)");
  this->Pos_i = Pos_i;
  this->Pos_j = Pos_j;
}

//--------------------------------------------------------------------------------
BoardPosition::BoardPosition(int Pos_i, char file)
{
  LOG_TRACE("BoardPosition::BoardPosition(int Pos_i, char Pos_j)");
  int j;
  if ('A' <= file && file <= 'H')
  {
    j = file - 'A';
  }
  else if ('a' <= file && file <= 'h')
  {
    j = file - 'a';
  }

  BoardPosition(Pos_i, j);
}

//--------------------------------------------------------------------------------
BoardPosition::~BoardPosition()
{
  LOG_TRACE("BoardPosition::~BoardPosition()");
}

//--------------------------------------------------------------------------------
int BoardPosition::i()
{
  LOG_TRACE("BoardPosition::i()");
  return this->Pos_i;
}

//--------------------------------------------------------------------------------
int BoardPosition::j()
{
  LOG_TRACE("BoardPosition::j()");
  return this->Pos_j;
}

//--------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream &os, BoardPosition &bp)
{
  LOG_TRACE("operator<<(std::ostream &os, BoardPosition &bp)");
  os << "(" << bp.Pos_i << ", " << bp.Pos_j << ")";
  return os;
}