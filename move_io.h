#pragma once

#include "move.h"
#include <string>
#include <vector>

class MoveIO
{
public:
	MoveIO();
	MoveIO(std::vector<Move>moves );
	MoveIO(std::string filename);
	MoveIO(std::vector<Move> moves, std::string filename);
  ~MoveIO();

	std::vector<Move> GetMoves();
	void SetMoves(std::vector<Move>);

	std::string GetFilepath();
	void setFilepath(std::string filename);

	bool WriteMovesToFile();
	std::vector<Move> ReadMovesFromFile();

private:
	bool ReadMoves();
	bool WriteMoves();

	std::vector<Move> Moves;
	std::string Filepath;

};

