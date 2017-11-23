#pragma once

#include <ostream>

class BoardPosition
{
public:
  BoardPosition();
  BoardPosition(int Pos_i, int Pos_j);
  ~BoardPosition();

  // accessors
  int i();
  int j();

  bool operator==(BoardPosition& bp);

private:
  // friend functions
  friend std::ostream& operator<<(std::ostream &os, BoardPosition &bp);

  // member variables
  int Pos_i; // row or rank, 0 is bottom row from white's point of view
  int Pos_j; // column or file, 0 is leftmost column from white's point of view
};