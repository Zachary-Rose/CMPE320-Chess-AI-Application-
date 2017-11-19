#pragma once


#include <string>;
#include "board.h";

class board_io
{


public:
  board_io();
  ~board_io();
	board_io(Board board);
	board_io(std::string filename);
	board_io(Board board, std::string filename);
	Board getBoard();
	void setBoard(Board board);
	std::string getFilePath();
	bool ReadBoardFromFile();
	bool WriteBoardToFile();

private:
	std::string filePath;
	Board Board;

	bool ReadBoard();
	bool WriteBoard();
	
		

};