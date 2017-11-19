#pragma once

#include <string>
#include "board.h"

class BoardIO
{
public:
  BoardIO();
  BoardIO(Board board);
  BoardIO(std::string filename);
  BoardIO(Board board, std::string filename);
  ~BoardIO();

	Board GetBoard();
	void SetBoard(Board board);
	std::string GetFilePath();
	bool ReadBoardFromFile();
	bool WriteBoardToFile();

private:
	std::string FilePath;
	Board CurrentBoard;

	bool ReadBoard();
	bool WriteBoard();
};