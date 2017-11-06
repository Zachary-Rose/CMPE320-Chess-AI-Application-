#pragma once
#include "move_io.h"

Move_IO::Move_IO()
{
	this->Filepath = "games";
}

Move_IO::Move_IO(std::vector<Move> moves)
{
	this->Moves = moves;
	this->Filepath = "games";
}

Move_IO::Move_IO(std::string filename)
{
	this->Filepath = filename;
}

Move_IO::Move_IO(std::vector<Move> moves, std::string filename)
{
	this->Moves = moves;
	this->Filepath = filename;
}

Move_IO::~Move_IO()
{

}

std::vector<Move> Move_IO::GetMoves()
{
	std::vector<Move> moves;
	return moves;
}
void Move_IO::SetMoves(std::vector<Move>)
{

}

std::string Move_IO::GetFilepath()
{
	return "";
}

void Move_IO::setFilepath(std::string filename)
{

}

bool Move_IO::WriteMovesToFile()
{
	return true;
}

std::vector<Move> Move_IO::ReadMovesFromFile()
{
	std::vector<Move> moves;
	return moves;
}

bool Move_IO::ReadMoves()
{
	return true;
}

bool Move_IO::WriteMoves()
{
	return true;
}
