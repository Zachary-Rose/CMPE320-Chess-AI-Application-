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
	LOG_TRACE("std::vector<Move> Ai::GenerateBishopMoves()");
	bool blackOrWhite = (GameBoard.GetPieceByPosition(Start_i, Start_j) == W_BISHOP); //true if white, false if black
	std::vector<Move> BishopMoves;
	int temp = 1;
	char pieceTaken;
	bool outOfBound = false;


	//j controls left to right, -1 left, 1 right
	for (int j = -1; j <= 1; j += 2)
	{
		//k controls up and down, -1 down, 1 up
		for (int k = -1; k <= 1; k += 2)
		{
			temp = 1;

			if (Start_i + temp * j < 0 || Start_i + temp * j > 7
				|| Start_j + temp * k < 0 || Start_j + temp * k > 7)
			{
				outOfBound = true;
			}

			while (!outOfBound && GameBoard.GetPieceByPosition(Start_i + temp * j, Start_j + temp * k) == EMPTY)
			{
				//a king safe function needs to be added here, wrapping the below line in an if statement
				BishopMoves.push_back(Move(Start_i, Start_j, Start_i + temp * j, Start_j + temp * k));
				temp++;

				if (Start_i + temp * j < 0 || Start_i + temp * j > 7
					|| Start_j + temp * k < 0 || Start_j + temp * k > 7)
				{
					outOfBound = true;
				}

			}

			if (!outOfBound)
			{
				pieceTaken = GameBoard.GetPieceByPosition(Start_i + temp * j, Start_j + temp * k);
				if (islower(pieceTaken))
				{
					//again a king safe method should be added here, wrapping the below line in an if statement
					BishopMoves.push_back(Move(Start_i, Start_j, Start_i + temp * j, Start_j + temp * k, pieceTaken));
				}
			}
			outOfBound = false;
		}
	}
  
  return BishopMoves;
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateKingMoves(int Start_i, int Start_j)
{
	LOG_TRACE("std::vector<Move> Ai::GenerateKingMoves()");
	bool blackOrWhite = (GameBoard.GetPieceByPosition(Start_i, Start_j) == W_KING); //true if white, false if black
	std::vector<Move> KingMoves;
	char pieceTaken;

	//castling

	//first check if king or rook has moved
	if(blackOrWhite && Start_i == 0 && Start_j == 3)


	//j controls up and down
	for (int j = -1; j <= 1; j++)
	{
		//k controls left and right
		for (int k = -1; k <= 1; k++)
		{
			if (Start_i + j < 0 || Start_i + j > 7
			 || Start_j + k < 0 || Start_j + k > 7)
			{
				pieceTaken = GameBoard.GetPieceByPosition(Start_i + 1 * j, Start_j + 1 * k);
				if (pieceTaken == ' '
					|| (blackOrWhite && islower(pieceTaken))
					|| (!blackOrWhite && isupper(pieceTaken)))
				{
					//again a king safe method should be added here, wrapping the below line in an if statement
					KingMoves.push_back(Move(Start_i, Start_j, Start_i + 1 * j, Start_j + 1 * k, pieceTaken));
				}
			}
		}

		return std::vector<Move>();
	}
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateQueenMoves(int Start_i, int Start_j)
{
	LOG_TRACE("std::vector<Move> Ai::GenerateQueensMoves()");
	std::vector<Move> QueenMoves;
	bool blackOrWhite = (GameBoard.GetPieceByPosition(Start_i, Start_j) == W_QUEEN); //true if white, false if black
	int temp = 1;
	char pieceTaken;
	bool outOfBound = false;

	//j controls up and down
	for (int j = -1; j <= 1; j++)
	{
		//k controls left and right
		for (int k = -1; k <= 1; k++)
		{
			temp = 1;

			if (Start_i + temp * j < 0 || Start_i + temp * j > 7
				|| Start_j + temp * k < 0 || Start_j + temp * k > 7)
			{
				outOfBound = true;
			}


			while (!outOfBound && GameBoard.GetPieceByPosition(Start_i + temp * j, Start_j + temp * k) == EMPTY)
			{
				//a king safe function needs to be added here, wrapping the below line in an if statement
				QueenMoves.push_back(Move(Start_i, Start_j, Start_i + temp * j, Start_j + temp * k));

				temp++;
				if (Start_i + temp * j < 0 || Start_i + temp * j > 7
					|| Start_j + temp * k < 0 || Start_j + temp * k > 7) 
				{
					outOfBound = true;
				}
			}

			if(!outOfBound) 
			{
				pieceTaken = GameBoard.GetPieceByPosition(Start_i + temp * j, Start_j + temp * k);
				if ((blackOrWhite && islower(pieceTaken))
					|| (!blackOrWhite && isupper(pieceTaken)))
				{
					//again a king safe method should be added here, wrapping the below line in an if statement
					QueenMoves.push_back(Move(Start_i, Start_j, Start_i + temp * j, Start_j + temp * k, pieceTaken));
				}
			}
			outOfBound = false;
		}
	}
  
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