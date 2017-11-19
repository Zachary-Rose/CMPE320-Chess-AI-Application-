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

bool Ai::isKingSafe(bool blackOrWhite, Move move) {

	int temp = 1;
	bool outOfBound = false;
	char pieceAttack;
	char king;

	if (blackOrWhite) king = W_KING;
	else king = B_KING;


	//get the coordinates of the king we need to keep safe, this is done pretty poorly
	int kingRow;
	int kingCol;
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; i++)
		{
			if (GameBoard.GetPieceByPosition(i, j) == king)
			{
				kingCol = i;
				kingRow = j;
				break;
			}
		}
	}

	//execute the move given
	GameBoard[move.GetToPiecePosition().i][move.GetToPiecePosition().j] = king;
	GameBoard[move.GetFromPiecePosition().i][move.GetFromPiecePosition().j] = EMPTY;

	//check to see if the king is safe
	
	//check if opposite bishop or queen can attack
	for(int j = -1; j <= 1; j += 2)
	{
		//k controls up and down, -1 down, 1 up
		for (int k = -1; k <= 1; k += 2)
		{
			if (kingCol + temp * j < 0 || kingCol + temp * j > 7
				|| kingRow + temp * k < 0 || kingRow + temp * k > 7)
			{
				continue;
			}

			while (!outOfBound && GameBoard.GetPieceByPosition(kingCol + temp * j, kingRow + temp * k) == EMPTY)
			{
				temp++;
				if (kingCol + temp * j < 0 || kingCol + temp * j > 7
					|| kingRow + temp * k < 0 || kingRow + temp * k > 7)
				{

					outOfBound = true;
				}
			}

			if (!outOfBound)
			{
				pieceAttack = GameBoard.GetPieceByPosition(kingCol + temp * j, kingRow + temp * k);
				if ((blackOrWhite && islower(pieceAttack) && (pieceAttack == B_BISHOP || pieceAttack == B_QUEEN))
					|| (!blackOrWhite && isupper(pieceAttack) && (pieceAttack == W_BISHOP || pieceAttack == W_QUEEN)))
				{
					//put that piece back where it came from or so help me
					GameBoard[move.GetFromPiecePosition().i][move.GetFromPiecePosition().j] = king;
					GameBoard[move.GetToPiecePosition().i][move.GetToPiecePosition().j] = move.GetCapturedPiece;
					return false;
				}
			}
			temp = 1;
			outOfBound = false;
		}
	}
		
	//check if opposite rook or queen can attack
	for (int j = -1; j <= 1; j += 2)
	{

		//checks if on the edge/corner because if it is, we can skip half of this
		if (kingCol + temp * j < 0 || kingCol + temp * j > 7
			|| kingRow + temp * j < 0 || kingRow + temp * j > 7)
		{
			continue;
		}

		//handles left and right 
		while (!outOfBound && GameBoard.GetPieceByPosition(kingCol + temp * j, kingRow) == EMPTY)
		{
			temp++;
			if (kingCol + temp * j < 0 || kingCol + temp * j > 7)
			{
				outOfBound = true;
			}
		}

		if (!outOfBound)
		{
			pieceAttack = GameBoard.GetPieceByPosition(kingCol + temp * j, kingRow);
			if ((blackOrWhite && islower(pieceAttack) && (pieceAttack == B_ROOK || pieceAttack == B_QUEEN))
				|| (!blackOrWhite && isupper(pieceAttack) && (pieceAttack == W_ROOK || pieceAttack == W_QUEEN)))
			{
				GameBoard[move.GetFromPiecePosition().i][move.GetFromPiecePosition().j] = king;
				GameBoard[move.GetToPiecePosition().i][move.GetToPiecePosition().j] = move.GetCapturedPiece;
				return false;
			}
		}
		//end of left and right

		temp = 1;
		outOfBound = false;

		//handles up and down
		while (!outOfBound && GameBoard.GetPieceByPosition(kingCol, kingRow + temp * j) == EMPTY)
		{
			temp++;
			if (kingRow + temp * j < 0 || kingRow + temp * j > 7)
			{
				outOfBound = true;
			}
		}

		if (!outOfBound)
		{
			pieceAttack = GameBoard.GetPieceByPosition(kingCol, kingRow + temp * j);
			if ((blackOrWhite && islower(pieceAttack) && (pieceAttack == B_ROOK || pieceAttack == B_QUEEN))
				|| (!blackOrWhite && isupper(pieceAttack) && (pieceAttack == W_ROOK || pieceAttack == W_QUEEN)))
			{
				GameBoard[move.GetFromPiecePosition().i][move.GetFromPiecePosition().j] = king;
				GameBoard[move.GetToPiecePosition().i][move.GetToPiecePosition().j] = move.GetCapturedPiece;
				return false;
			}
		}
		//end of up and down

		temp = 1;
		outOfBound = false;
	}

	//check if opposite knight can attack (stolen from tedd's code and repurposed)
	std::vector<std::vector<int>> pos{
		{ 1, 2 },
		{ 2, 1 },
		{ -1, 2 },
		{ -2, 1 },
		{ 1, -2 },
		{ 2, -1 },
		{ -1, -2 },
		{ -2, -1 } };
	for (int k = 0; k < pos.size(); k++)
	{
		if (
			(kingCol + pos[k][0] > 7) ||
			(kingCol + pos[k][0] < 0) ||
			(kingRow + pos[k][1] > 7) ||
			(kingRow + pos[k][1] < 0))
		{
			continue;
		}
		else if ((blackOrWhite && GameBoard.GetPieceByPosition(kingCol + pos[k][0], kingRow + pos[k][1]) == B_ROOK) ||
						 (!blackOrWhite && GameBoard.GetPieceByPosition(kingCol + pos[k][0], kingRow + pos[k][1]) == W_ROOK))
		{
			GameBoard[move.GetFromPiecePosition().i][move.GetFromPiecePosition().j] = king;
			GameBoard[move.GetToPiecePosition().i][move.GetToPiecePosition().j] = move.GetCapturedPiece;
			return false;
		}
	}
	

	//check if opposite pawn can attack
	if (blackOrWhite && kingRow < 6)
	{
		if (GameBoard.GetPieceByPosition(kingCol + 1, kingRow + 1) == B_PAWN || GameBoard.GetPieceByPosition(kingCol - 1, kingRow + 1) == B_PAWN)
		{
			GameBoard[move.GetFromPiecePosition().i][move.GetFromPiecePosition().j] = king;
			GameBoard[move.GetToPiecePosition().i][move.GetToPiecePosition().j] = move.GetCapturedPiece;
			return false;
		}
	}
	else if (!blackOrWhite && kingRow > 1)
	{
		if (GameBoard.GetPieceByPosition(kingCol + 1, kingRow - 1) == W_PAWN || GameBoard.GetPieceByPosition(kingCol - 1, kingRow - 1) == W_PAWN)
		{
			GameBoard[move.GetFromPiecePosition().i][move.GetFromPiecePosition().j] = king;
			GameBoard[move.GetToPiecePosition().i][move.GetToPiecePosition().j] = move.GetCapturedPiece;
			return false;
		}
	}

	//we made it through the gauntlet, the move is valid
	//put that piece back where it came from or so help me
	GameBoard[move.GetFromPiecePosition().i][move.GetFromPiecePosition().j] = king;
	GameBoard[move.GetToPiecePosition().i][move.GetToPiecePosition().j] = move.GetCapturedPiece;
	return true;
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
			BoardPosition from(i, j);
			BoardPosition to(i + iOffset, j + jOffset);
			Move tempMove(from, to, EMPTY);
			moves.push_back(tempMove);
		}
		else if (
			(bw &&  GameBoard.GetPieceByPosition(i + iOffset, j + jOffset) >= B_BISHOP) ||
			(!bw &&  GameBoard.GetPieceByPosition(i + iOffset, j + jOffset) <= W_ROOK))
		{
			BoardPosition from(i, j);
			BoardPosition to(i + iOffset, j + jOffset);
			Move tempMove(from, to, GameBoard.GetPieceByPosition(i + iOffset, j + jOffset));
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
			break;
		case 2: iDir = 0;
			jDir = 1;
			break;
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
		else if (GameBoard.GetPieceByPosition(i + pos[k][0], j + pos[k][1]) == EMPTY) 
		{
			BoardPosition from(i, j);
			BoardPosition to(i + pos[k][0], j + pos[k][1]);
			Move tempMove(from, to, EMPTY);
			moves.push_back(tempMove);
		}
		else if (
			(bw &&  GameBoard.GetPieceByPosition(i + pos[k][0], j + pos[k][1]) >= B_BISHOP) ||
			(!bw &&  GameBoard.GetPieceByPosition(i + pos[k][0], j + pos[k][1]) <= W_ROOK))
		{
			BoardPosition from(i, j);
			BoardPosition to(i + pos[k][0], j + pos[k][1]);
			Move tempMove(from, to, GameBoard.GetPieceByPosition(i + pos[k][0], j + pos[k][1]));
			moves.push_back(tempMove);
		}
	}
	return moves;
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
				continue;
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

	//first check if king has moved
	if (Start_j == 4 && (Start_i == 0 || Start_i == 7))
	{
		//king's side
		if ((blackOrWhite && GameBoard.GetPieceByPosition(Start_i, 7) == W_ROOK && GameBoard.GetPieceByPosition(Start_i, 6) == EMPTY && GameBoard.GetPieceByPosition(Start_i, 5) == EMPTY)  ||
			(!blackOrWhite && GameBoard.GetPieceByPosition(Start_i, 7) == B_ROOK && GameBoard.GetPieceByPosition(Start_i, 6) == EMPTY && GameBoard.GetPieceByPosition(Start_i, 5) == EMPTY)) 
		{
			//king cannot be put into check
			KingMoves.push_back(Move(Start_i, Start_j, Start_i, Start_j + 2, EMPTY));
		}

		//queen's side
		if ((blackOrWhite && GameBoard.GetPieceByPosition(Start_i, 0) == W_ROOK && GameBoard.GetPieceByPosition(Start_i, 1) == EMPTY && GameBoard.GetPieceByPosition(Start_i, 2) == EMPTY && GameBoard.GetPieceByPosition(Start_i, 3) == EMPTY) ||
			(!blackOrWhite && GameBoard.GetPieceByPosition(Start_i, 0) == B_ROOK && GameBoard.GetPieceByPosition(Start_i, 1) == EMPTY && GameBoard.GetPieceByPosition(Start_i, 2) == EMPTY && GameBoard.GetPieceByPosition(Start_i, 3) == EMPTY))
		{
			//king cannot be put into check
			KingMoves.push_back(Move(Start_i, Start_j, Start_i, Start_j - 3, EMPTY));
		}

	}


	


	//j controls up and down
	for (int j = -1; j <= 1; j++)
	{
		//k controls left and right
		for (int k = -1; k <= 1; k++)
		{
			if (Start_i + j < 0 || Start_i + j > 7
				|| Start_j + k < 0 || Start_j + k > 7)
			{
				continue;
			}

			pieceTaken = GameBoard.GetPieceByPosition(Start_i + 1 * j, Start_j + 1 * k);
			if (pieceTaken == ' '
				|| (blackOrWhite && islower(pieceTaken))
				|| (!blackOrWhite && isupper(pieceTaken)))
			{
				//again a king safe method should be added here, wrapping the below line in an if statement
				KingMoves.push_back(Move(Start_i, Start_j, Start_i + 1 * j, Start_j + 1 * k, pieceTaken));
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
				continue;
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

  for (int i = 0; i < 8; i++)
  {
	  for (int j = 0; j < 8; j++)
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