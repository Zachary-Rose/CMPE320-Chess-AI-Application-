#include "board_io.h"

BoardIO::BoardIO()
{
}

BoardIO::BoardIO(Board brd)
{

}

BoardIO::BoardIO(std::string filename)
{
}

BoardIO::BoardIO(Board brd, std::string filename)
{

}

BoardIO::~BoardIO()
{
}

Board BoardIO::GetBoard()
{
	return CurrentBoard;
}

void BoardIO::SetBoard(Board brd)
{

}

std::string BoardIO::GetFilePath()
{
	return std::string();
}

bool BoardIO::ReadBoardFromFile()
{
	return false;
}

bool BoardIO::WriteBoardToFile()
{
	return false;
}

bool BoardIO::ReadBoard()
{
	return false;
}

bool BoardIO::WriteBoard()
{
	return false;
}
