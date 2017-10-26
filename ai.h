#pragma once

// local includes
#include "board.h"
#include "move.h"

// system includes
#include <vector>

enum PLAYER
{
  WHITE = 0,
  BLACK = 1
};

class Ai
{
public:
  Ai();
  ~Ai();

  // gets best move for provided player
  Move GetBestMove(PLAYER WhosTurnIsIt);

  // generates list of legal piece moves for piece at bp
  std::vector<Move> GetLegalPieceMoves(const BoardPosition& bp);

  // executes move (either made by player via GUI, or by computer via AI)
  Move ExecuteMove(PLAYER WhosTurnIsIt, Move move);

private:
  //member variables
  Board GameBoard;
  PLAYER WhosTurnIsIt; // who's turn is it right now?

  // generates list of all legal rook moves
  std::vector<Move> GenerateRookMoves();

  // generates list of all legal knight moves
  std::vector<Move> GenerateKnightMoves();

  // generates list of all legal bishop moves
  std::vector<Move> GenerateBishopMoves();

  // generates list of all legal king moves
  std::vector<Move> GenerateKingMoves();

  // generates list of all legal queen moves
  std::vector<Move> GenerateQueenMoves();

  // generates list of all legal pawn moves
  std::vector<Move> GeneratePawnMoves();

  // generates list of all possible legal moves
  std::vector<Move> GenerateAllPossibleMoves();
};

