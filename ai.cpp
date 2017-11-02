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
std::vector<Move> Ai::GenerateRookMoves(int i, int j) {
	LOG_TRACE("Board::RookMechanics(int i, int j)");

	bool bw = GameBoard.GetPieceByPosition(i, j) == W_ROOK;   //white rook is true, black rook is false
	int iOffset = 0;  //offset from original rook position to destined position
	int jOffset = 0;
	int iDir = 1;     //direction of checking
	int jDir = 0;
	int count = 0;    //# of directions checked
	std::vector<Move> moves;

	while (count < 4) {
		iOffset += iDir;
		jOffset += jDir;

		if (
			(i + iOffset > 7) ||
			(i + iOffset < 0) ||
			(j + jOffset > 7) ||
			(j + jOffset < 0))
		{
			count++;
			iOffset = 0;
			jOffset = 0;
		}
		else if (GameBoard.GetPieceByPosition(i + iOffset, j + jOffset) == EMPTY)
		{
			Move tempMove(i, j, i + iOffset, j + jOffset, EMPTY);
			moves.push_back(tempMove);
		}
		else if (
			(bw &&  GameBoard.GetPieceByPosition(i + iOffset, j + jOffset) >= B_BISHOP) ||
			(!bw &&  GameBoard.GetPieceByPosition(i + iOffset, j + jOffset) <= W_ROOK))
		{
			Move tempMove(i, j, i + iOffset, j + jOffset, GameBoard.GetPieceByPosition(i + iOffset, j + jOffset));
			moves.push_back(tempMove);
			count++;
			iOffset = 0;
			jOffset = 0;
		}
		else
		{
			count++;
			iOffset = 0;
			jOffset = 0;
		}

		switch (count)
		{
		case 1: iDir = -1;
		case 2: iDir = 0;
			jDir = 1;
		case 3: jDir = -1;
		}
	}
	return moves;
}

std::vector<Move> Ai::GenerateKnightMoves(int i, int j) {
	LOG_TRACE("Board::KnightMechanics(int i, int j)");

	bool bw = (GameBoard.GetPieceByPosition(i, j) == W_KNIGHT);
	std::vector<std::vector<int>> pos{
		{ 1, 2 },
		{ 2, 1 },
		{ -1, 2 },
		{ -2, 1 },
		{ 1, -2 },
		{ 2, -1 },
		{ -1, -2 },
		{ -2, -1 } };
	std::vector<Move> moves;

	for (int k = 0; k<pos.size(); k++)
	{
		if (
			(i + pos[k][0] > 7) ||
			(i + pos[k][0] < 0) ||
			(j + pos[k][1] > 7) ||
			(j + pos[k][1] < 0))
		{
			continue;
		}
		else if (GameBoard.GetPieceByPosition(i + pos[k][0], j + pos[k][1]) == EMPTY) {
			Move tempMove(i, j, i + pos[k][0], j + pos[k][1], EMPTY);
			moves.push_back(tempMove);
		}
		else if (
			(bw &&  GameBoard.GetPieceByPosition(i + pos[k][0], j + pos[k][1]) >= B_BISHOP) ||
			(!bw &&  GameBoard.GetPieceByPosition(i + pos[k][0], j + pos[k][1]) <= W_ROOK))
		{
			Move tempMove(i, j, i + pos[k][0], j + pos[k][1], GameBoard.GetPieceByPosition(i + pos[k][0], j + pos[k][1]));
			moves.push_back(tempMove);
		}
	}
	return moves;
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateBishopMoves(int i, int j)
{
  LOG_TRACE("std::vector<Move> Ai::GenerateBishopMoves(int i, int j)");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateKingMoves(int i, int j)
{
  LOG_TRACE("std::vector<Move> Ai::GenerateKingMoves(int i, int j)");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateQueenMoves(int i, int j)
{
  LOG_TRACE("std::vector<Move> Ai::GenerateQueensMoves(int i, int j)");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GeneratePawnMoves(int i, int j)
{
  LOG_TRACE("std::vector<Move> Ai::GeneratePawnMoves(int i, int j)");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateAllPossibleMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateAllPossibleMoves()");

  std::vector<Move> allMoves;

  for (int i = 0; i < 7; i++)
  {
	  for (int j = 0; j < 7; j++)
	  {
		  if (GameBoard.GetPieceByPosition(i, j) == W_KING || GameBoard.GetPieceByPosition(i, j) == B_KING)
		  {
			  std::vector<Move> kingMoves = GenerateKingMoves(i, j);
			  allMoves.insert(allMoves.end(), kingMoves.begin(), kingMoves.end());
		  }
		  else if (GameBoard.GetPieceByPosition(i, j) == W_QUEEN || GameBoard.GetPieceByPosition(i, j) == B_QUEEN)
		  {
			  std::vector<Move> queenMoves = GenerateQueenMoves(i, j);
			  allMoves.insert(allMoves.end(), queenMoves.begin(), queenMoves.end());
		  }
		  else if (GameBoard.GetPieceByPosition(i, j) == W_BISHOP || GameBoard.GetPieceByPosition(i, j) == B_BISHOP)
		  {
			  std::vector<Move> bishopMoves = GenerateKingMoves(i, j);
			  allMoves.insert(allMoves.end(), bishopMoves.begin(), bishopMoves.end());
		  }
		  else if (GameBoard.GetPieceByPosition(i, j) == W_KNIGHT || GameBoard.GetPieceByPosition(i, j) == B_KNIGHT)
		  {
			  std::vector<Move> knightMoves = GenerateKnightMoves(i, j);
			  allMoves.insert(allMoves.end(), knightMoves.begin(), knightMoves.end());
		  }
		  else if (GameBoard.GetPieceByPosition(i, j) == W_ROOK || GameBoard.GetPieceByPosition(i, j) == B_ROOK)
		  {
			  std::vector<Move> rookMoves = GenerateRookMoves(i, j);
			  allMoves.insert(allMoves.end(), rookMoves.begin(), rookMoves.end());
		  }
		  else if (GameBoard.GetPieceByPosition(i, j) == W_PAWN || GameBoard.GetPieceByPosition(i, j) == B_PAWN)
		  {
			  std::vector<Move> pawnMoves = GeneratePawnMoves(i, j);
			  allMoves.insert(allMoves.end(), pawnMoves.begin(), pawnMoves.end());
		  }
	  }
  }

  return allMoves;
}