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
std::vector<Move> Ai::GenerateRookMoves(int Start_i, int Start_j) {
	LOG_TRACE("Board::RookMechanics(int Start_i, int Start_j)");

	if (GetPieceByPosition(Start_i, Start_j) != B_ROOK &&
		GetPieceByPosition(Start_i, Start_j) != W_ROOK)
	{
		LOG_WARNING("Invalid index: Not a Rook");
	}

	bool bw = this->GetPieceByPosition(Start_i, Start_j) == W_ROOK;   //white rook is true, black rook is false
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
			(Start_i + iOffset > 7) ||
			(Start_i + iOffset < 0) ||
			(Start_j + jOffset > 7) ||
			(Start_j + jOffset < 0))
		{
			count++;
			iOffset = 0;
			jOffset = 0;
		}
		else if (getPieceByPosition(Start_i + iOffset, Start_j + jOffset) == EMPTY)
		{
			Move tempMove(Start_i, Start_j, Start_i + iOffset, Start_j + jOffset, EMPTY);
			moves.push_back(tempMove);
		}
		else if (
			(bw &&  getPieceByPosition(Start_i + iOffset, Start_j + jOffset) >= B_BISHOP) ||
			(!bw &&  getPieceByPosition(Start_i + iOffset, Start_j + jOffset) <= W_ROOK))
		{
			Move tempMove(Start_i, Start_j, Start_i + iOffset, Start_j + jOffset, getPieceByPosition(Start_i + iOffset, Start_j + jOffset));
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

std::vector<Move> Ai::GenerateKnightMoves(int Start_i, int Start_j) {
	LOG_TRACE("Board::KnightMechanics(int Start_i, int Start_j)");

	if (GetPieceByPosition(Start_i, Start_j) != B_KNIGHT &&
		GetPieceByPosition(Start_i, Start_j) != W_KNIGHT)
	{
		LOG_WARNING("Invalid index: Not a Knight");
	}

	bool bw = getPieceByPosition(Start_i, Start_j) == W_KNIGHT;
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
			(Start_i + pos[k][0] > 7) ||
			(Start_i + pos[k][0] < 0) ||
			(Start_j + pos[k][1] > 7) ||
			(Start_j + pos[k][1] < 0))
		{
			continue;
		}
		else if (getPieceByPosition(Start_i + pos[k][0], Start_j + pos[k][1]) == EMPTY) {
			Move tempMove(Start_i, Start_j, Start_i + pos[k][0], Start_j + pos[k][1], EMPTY);
			moves.push_back(tempMove);
		}
		else if (
			(bw &&  getPieceByPosition(Start_i + pos[k][0], Start_j + pos[k][1]) >= B_BISHOP) ||
			(!bw &&  getPieceByPosition(Start_i + pos[k][0], Start_j + pos[k][1]) <= W_ROOK))
		{
			Move tempMove(Start_i, Start_j, Start_i + pos[k][0], Start_j + pos[k][1], getPieceByPosition(Start_i + pos[k][0], Start_j + pos[k][1]));
			moves.push_back(tempMove);
		}
	}
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateBishopMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateBishopMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateKingMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateKingMoves()");
  return std::vector<Move>();
}

//--------------------------------------------------------------------------------
std::vector<Move> Ai::GenerateQueenMoves()
{
  LOG_TRACE("std::vector<Move> Ai::GenerateQueensMoves()");
  return std::vector<Move>();
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