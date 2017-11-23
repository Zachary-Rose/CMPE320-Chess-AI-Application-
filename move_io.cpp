#pragma once
#include "move_io.h"

MoveIO::MoveIO()
{
	this->Filepath = "games";
}

MoveIO::MoveIO(std::vector<Move> moves)
{
	this->Moves = moves;
	this->Filepath = "games";
}

MoveIO::MoveIO(std::string filename)
{
	this->Filepath = filename;
}

MoveIO::MoveIO(std::vector<Move> moves, std::string filename)
{
	this->Moves = moves;
	this->Filepath = filename;
}

MoveIO::~MoveIO()
{

}

std::vector<Move> MoveIO::GetMoves()
{
	std::vector<Move> moves;
	return moves;
}
void MoveIO::SetMoves(std::vector<Move>)
{

}

std::string MoveIO::GetFilepath()
{
	return "";
}

void MoveIO::setFilepath(std::string filename)
{

}

bool MoveIO::WriteMovesToFile()
{
	return true;
}

std::vector<Move> MoveIO::ReadMovesFromFile()
{
	std::vector<Move> moves;
	return moves;
}

bool MoveIO::ReadMoves()
{
	return true;
}

bool MoveIO::WriteMoves()
{
	return true;
}
