#include "ai.h"
#include "common.h"

//--------------------------------------------------------------------------------
Ai::Ai()
{
  LOG_TRACE("Ai::Ai()");
}

//--------------------------------------------------------------------------------
Ai::~Ai()
{
  LOG_TRACE("Ai::~Ai()");
}

//--------------------------------------------------------------------------------
Move Ai::GetBestMove(PLAYER WhosTurnIsIt)
{
  LOG_TRACE("Move Ai::GetBestMove(PLAYER WhosTurnIsIt)");
  return Move();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GetLegalPieceMoves(const BoardPosition& bp)
{
  LOG_TRACE("std::vector<Move> Ai::GetLegalPieceMoves(const BoardPosition& bp)");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
Move Ai::ExecuteMove(PLAYER WhosTurnIsIt, Move move)
{
  LOG_TRACE("Move Ai::ExecuteMove(PLAYER WhosTurnIsIt, Move move)");
  return Move();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateRookMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateRookMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateKnightMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateKnightMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateBishopMoves(int Start_i, int Start_j)
{
	std::vector<Move> BishopMoves;
	int temp = 1;
	//r and c are initial Bishop position, which needs to be found
	char pieceTaken;


	//j controls left to right, -1 left, 1 right
	for (int j = -1; j <= 1; j += 2)
	{
		//k controls up and down, -1 down, 1 up
		for (int k = -1; k <= 1; k += 2)
		{
			while (GameBoard.GetPieceByPosition(Start_i + temp * j, Start_j + temp * k) == EMPTY)
			{
				//a king safe function needs to be added here, wrapping the below line in an if statement
				BishopMoves.push_back(Move(Start_i, Start_j, Start_i + temp * j, Start_j + temp * k));
				temp++;
			}

			pieceTaken = GameBoard.GetPieceByPosition(Start_i + temp * j, Start_j + temp * k);
			if (islower(pieceTaken))
			{
				//again a king safe method should be added here, wrapping the below line in an if statement
				BishopMoves.push_back(Move(Start_i, Start_j, Start_i + temp * j, Start_j + temp * k, pieceTaken));
			}
		}
	}
  LOG_TRACE("std::vector<Move> Ai::GenerateBishopMoves()");
  return BishopMoves;
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateKingMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateKingMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateQueenMoves(int Start_i, int Start_j)
{
	std::vector<Move> QueenMoves;
	int temp = 1;
	char pieceTaken;

	//j controls left to right, -1 left, 1 right
	for (int j = -1; j <= 1; j++)
	{
		//k controls up and down, -1 down, 1 up
		for (int k = -1; k <= 1; k++)
		{
			while (GameBoard.GetPieceByPosition( Start_i + temp * j , Start_j + temp * k ) == EMPTY)
			{
				//a king safe function needs to be added here, wrapping the below line in an if statement
				QueenMoves.push_back(Move( Start_i , Start_j , Start_i + temp * j , Start_j + temp * k));
				temp++;
			}

			pieceTaken = GameBoard.GetPieceByPosition(Start_i + temp * j, Start_j + temp * k);
			if (islower(pieceTaken)) 
			{
				//again a king safe method should be added here, wrapping the below line in an if statement
				QueenMoves.push_back(Move(Start_i, Start_j, Start_i + temp * j, Start_j + temp * k, pieceTaken));
			}
		}
	}

  LOG_TRACE("std::vector<Move> Ai::GenerateQueensMoves()");
  return QueenMoves;
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GeneratePawnMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GeneratePawnMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateAllPossibleMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateAllPossibleMoves()");
  return std::vector<Move>();
}