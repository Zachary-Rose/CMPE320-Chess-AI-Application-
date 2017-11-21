#pragma once

// local includes
#include "board_position.h"

// system includes
#include <string>

class Move
{
public:
  Move();
  Move(int From_i, int From_j, int To_i, int To_j);
  Move(int From_i, int From_j, int To_i, int To_j, char TakenPiece);
  Move(const BoardPosition From, const BoardPosition To);
  Move(const BoardPosition From, const BoardPosition To, const char TakenPiece);
  ~Move();
  
  //accessors
  BoardPosition GetFromPiecePosition();
  BoardPosition GetToPiecePosition();
  char GetCapturedPiece();

private:
  friend std::ostream& operator<<(std::ostream& os, Move& m);

  // member variables
  BoardPosition From;
  BoardPosition To;
  char CapturedPiece; // piece taken by moving piece (empty if moving piece lands on empty square)
};

