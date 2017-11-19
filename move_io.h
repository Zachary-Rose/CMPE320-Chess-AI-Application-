#pragma once

#include "move.h"
#include <string>
#include <vector>

class Move_IO
{
public:
	Move_IO();
	Move_IO(std::vector<Move>moves );
	Move_IO(std::string filename);
	Move_IO(std::vector<Move> moves, std::string filename);
	~Move_IO();

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

