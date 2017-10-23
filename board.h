#pragma once

// system includes
#include <vector>
#include <ostream>

// chess piece constants
#define B_KING 'k'
#define B_QUEEN 'q'
#define B_BISHOP 'b'
#define B_ROOK 'r'
#define B_KNIGHT 'n'
#define B_PAWN 'p'
#define W_KING 'K'
#define W_QUEEN 'Q'
#define W_BISHOP 'B'
#define W_ROOK 'R'
#define W_KNIGHT 'N'
#define W_PAWN 'P'
#define EMPTY ' '

typedef std::vector<std::vector<char>> boardRepresentation;

class Board
{
public:
  Board();
  ~Board();

  /*
   * Accessors to get pieces from a given board index.
   * (0, 0) and (0, 'a') represent bottom left corner (white rook on home row)
   */
  char GetPieceByPosition(int i, int j);
  char GetPieceByPosition(int rank, char file);

  /*
   *
   */
  boardRepresentation GetBoard();


private:
  // Internal representation of the current state of the board.
  boardRepresentation CurrentBoard;
  friend std::ostream& operator<<(std::ostream &os, Board &b);
};

/*
 * Overloads << operator to provide text based board logging.
 */
std::ostream& operator<<(std::ostream &os, Board &b);