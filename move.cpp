// local includes
#include "move.h"
#include "common.h"
#include "board.h"

#define INVALID_POSITION -1

//--------------------------------------------------------------------------------
Move::Move()
{
  LOG_TRACE("Move::Move()");
  BoardPosition invalidBoardPosition;
  this->From = invalidBoardPosition;
  this->To = invalidBoardPosition;
  this->CapturedPiece = EMPTY;
}

//--------------------------------------------------------------------------------
Move::Move(int From_i, int From_j, int To_i, int To_j)
{
  LOG_TRACE("Move::Move(int From_i, int From_j, int To_i, int To_j)");
  this->From = BoardPosition(From_i, From_j);
  this->To = BoardPosition(To_i, To_j);
  this->CapturedPiece = EMPTY;
}

//--------------------------------------------------------------------------------
Move::Move(int From_i, int From_j, int To_i, int To_j, char CapturedPiece)
{
  LOG_TRACE("Move::Move(int From_i, int From_j, int To_i, int To_j, char CapturedPiece)");
  this->From = BoardPosition(From_i, From_j);
  this->To = BoardPosition(To_i, To_j);
  this->CapturedPiece = CapturedPiece;
}

Move::Move(const BoardPosition From, const BoardPosition To)
{
  LOG_TRACE("Move::Move(const BoardPosition& From, const BoardPosition& To)");
  Move(From, To, EMPTY);
}

Move::Move(const BoardPosition From, const BoardPosition To, const char CapturedPiece)
{
  LOG_TRACE("Move::Move(const BoardPosition& From, const BoardPosition& To, const char& CapturedPiece)");
  this->From = From;
  this->To = To;
  this->CapturedPiece = CapturedPiece;
}

Move::~Move()
{
  LOG_TRACE("Move::~Move()");
}

BoardPosition Move::GetFromPiecePosition()
{
  LOG_TRACE("BoardPosition Move::GetFromPiecePosition()");
  return this->From;
}

BoardPosition Move::GetToPiecePosition()
{
  LOG_TRACE("BoardPosition Move::GetToPiecePosition()");
  return this->To;
}

char Move::GetCapturedPiece()
{
  LOG_TRACE("char Move::GetCapturedPiece()");
  return this->CapturedPiece;
}

std::ostream& operator<<(std::ostream& os, Move& m)
{
  LOG_TRACE("operator<<(std::ostream& os, Move& m)");
  BoardPosition from = m.GetFromPiecePosition();
  BoardPosition to = m.GetToPiecePosition();
  char capturedPiece = m.GetCapturedPiece();
  os << "From: (" << from.i() << ", " << from.j() << ") ";
  os << "To: (" << to.i() << ", " << to.j() << ") ";
  os << "Captured piece: ";
  capturedPiece == ' '? os << "None" : os << capturedPiece;
  return os;
}