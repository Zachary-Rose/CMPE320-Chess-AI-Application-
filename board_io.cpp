#include "board_io.h"
#include "board.h"

board_io::board_io()
{
}

board_io::~board_io()
{
}

board_io::board_io(Board board)
{

}

board_io::board_io(std::string filename)
{
}



board_io::board_io(Board board, std::string filename)
{

}

Board board_io::getBoard()
{
	return Board.GetBoard;
}

void board_io::setBoard(Board board)
{

}

std::string board_io::getFilePath()
{
	return std::string;
}

bool board_io::ReadBoardFromFile()
{
	return false;
}

bool board_io::WriteBoardToFile()
{
	return false;
}

bool board_io::ReadBoard()
{
	return false;
}

bool board_io::WriteBoard()
{
	return false;
}
