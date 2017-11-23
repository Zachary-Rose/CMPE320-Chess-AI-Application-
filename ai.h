#pragma once

// local includes
#include "board.h"
#include "move.h"
#include "common.h"

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
  std::vector<Move> GetLegalPieceMoves(BoardPosition& bp);

  // executes move (either made by player via GUI, or by computer via AI)
  void ExecuteMove(Move move);

private:
  //member variables
  Board GameBoard;
  PLAYER WhosTurnIsIt; // who's turn is it right now?


	//finds if king is safe or not
	//needs which king we are trying to protect, white is 1, black is 0
	//needs move trying to be executed
	bool isKingSafe(bool blackOrWhite, Move move);

  // generates list of all legal rook moves
  std::vector<Move> GenerateRookMoves(int, int);

  // generates list of all legal knight moves
  std::vector<Move> GenerateKnightMoves(int, int);

  // generates list of all legal bishop moves
  std::vector<Move> GenerateBishopMoves(int Start_i, int Start_j);

  // generates list of all legal king moves
  std::vector<Move> GenerateKingMoves(int Start_i, int Start_j);

  // generates list of all legal queen moves
  std::vector<Move> GenerateQueenMoves(int Start_i, int Start_j);

  // generates list of all legal pawn moves
  std::vector<Move> GeneratePawnMoves(int Start_i, int Start_j);

public: //TODO: for testing move generation
  // generates list of all possible legal moves
  std::vector<Move> GenerateAllPossibleMoves();
  void PrintBoard()
  {
    LOG_INFO(GameBoard);
  };
private:
  std::vector<Move> moveHistory;

  bool PieceIsBlack(char piece);
  bool PieceIsWhite(char piece);
  bool Ai::IndexOffBoard(int value);
  bool IndexOffBoard(int rank, int file);
};

