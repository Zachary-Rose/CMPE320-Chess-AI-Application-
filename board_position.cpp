// local includes
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
  if (Pos_i < 0 || Pos_i > 7)
  {
    LOG_ERROR("Pos_i provided to BoardPosition constructor had illegal value " << Pos_i << ".");
    BoardPosition();
    return;
  }
    
  if (Pos_j < 0 || Pos_j > 7)
  {
    LOG_ERROR("Pos_j provided to BoardPosition constructor had illegal value " << Pos_j << ".");
    BoardPosition();
    return;
  }
    
  this->Pos_i = Pos_i;
  this->Pos_j = Pos_j;
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

bool BoardPosition::operator==(BoardPosition& bp)
{
  if (bp.Pos_i == Pos_i && bp.Pos_j == Pos_j)
  {
    
    return true;
  }
  return false;
}

//--------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream &os, BoardPosition &bp)
{
  LOG_TRACE("operator<<(std::ostream &os, BoardPosition &bp)");
  os << "(" << bp.Pos_i << ", " << bp.Pos_j << ")";
  return os;
}