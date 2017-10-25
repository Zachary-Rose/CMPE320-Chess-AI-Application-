#pragma once

// system includes
#include <string>
#include <exception>

class MoveException : public std::exception
{
public:
  MoveException()
  {
    this->message = "Move exception has occurred.";
  };

  MoveException(std::string message)
  {
    this->message = message;
  };

  std::string What()
  {
    return this->message;
  };

private:
  std::string message;
};


class Move
{
public:
  Move();
  Move(int From_i, int From_j, int To_i, int To_j);
  Move(int From_i, int From_j, int To_i, int To_j, char TakenPiece);
  ~Move();

  //accessors
  void GetFromPiecePosition(int& From_i, int& From_j);
  void GetToPiecePosition(int& To_i, int& To_j);
  void GetCapturedPiece(char& CapturedPiece);

private:
  friend std::ostream& operator<<(std::ostream &os, Move &m);

  // member variables
  int From_i; // rank - row of piece which is moving, 0 is bottom
  int From_j; // file - column of piece which is moving, 0 is leftmost column
  int To_i; // rank moving piece lands on
  int To_j; // file moving piece lands on
  char CapturedPiece; // piece taken by moving piece (empty if moving piece lands on empty square)
};

