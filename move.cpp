#include "move.h"
#include "common.h"
#include "board.h"

#define INVALID_POSITION -1
//--------------------------------------------------------------------------------
Move::Move()
{
  this->From_i = INVALID_POSITION;
  this->From_j = INVALID_POSITION;
  this->To_i = INVALID_POSITION;
  this->To_j = INVALID_POSITION;
  this->CapturedPiece = EMPTY;
}

//--------------------------------------------------------------------------------
Move::Move(int From_i, int From_j, int To_i, int To_j)
{
  if (From_i < 0 || From_i > 7)
    throw MoveException("From_i provided to Move constructor had illegal value.");
  if (From_j < 0 || From_j > 7)
    throw MoveException("From_j provided to Move constructor had illegal value.");
  if (To_i < 0 || To_i > 7)
    throw MoveException("To_i provided to Move constructor had illegal value.");
  if (To_j < 0 || To_j > 7)
    throw MoveException("To_j provided to Move constructor had illegal value.");

  this->From_i = From_i;
  this->From_j = From_j;
  this->To_i = To_i;
  this->To_j = To_j;
  this->CapturedPiece = EMPTY;
}

//--------------------------------------------------------------------------------
Move::Move(int From_i, int From_j, int To_i, int To_j, char CapturedPiece)
{
  //TODO: These should be LOG_ERROR calls (remove the exception class)
  if (From_i < 0 || From_i > 7)
    LOG_ERROR("Invalid From_i provided in Move constructor with value " << From_i << ".");
  if (From_j < 0 || From_j > 7)
    throw MoveException("From_j provided to Move constructor had illegal value.");
  if (To_i < 0 || To_i > 7)
    throw MoveException("To_i provided to Move constructor had illegal value.");
  if (To_j < 0 || To_j > 7)
    throw MoveException("To_j provided to Move constructor had illegal value.");


  this->From_i = From_i;
  this->From_j = From_j;
  this->To_i = To_i;
  this->To_j = To_j;
  this->CapturedPiece = CapturedPiece;
}

//--------------------------------------------------------------------------------
Move::~Move()
{
}

//--------------------------------------------------------------------------------
void Move::GetFromPiecePosition(int& From_i, int& From_j)
{
  From_i = this->From_i;
  From_j = this->From_j;
}

//--------------------------------------------------------------------------------
void Move::GetToPiecePosition(int& To_i, int& To_j)
{
  To_i = this->To_i;
  To_j = this->To_j;
}

void Move::GetCapturedPiece(char& CapturedPiece)
{
  CapturedPiece = this->CapturedPiece;
}

std::ostream& operator<<(std::ostream &os, Move &m)
{
  int from_i, from_j, to_i, to_j;
  char capturedPiece;
  m.GetFromPiecePosition(from_i, from_j);
  m.GetToPiecePosition(to_i, to_j);
  m.GetCapturedPiece(capturedPiece);
  os << "From: (" << from_i << ", " << from_j << ") ";
  os << "To: (" << to_i << ", " << to_j << ") ";
  os << "Captured piece: ";
  capturedPiece == ' '? os << "None." : os << capturedPiece << ".";
  return os;
}