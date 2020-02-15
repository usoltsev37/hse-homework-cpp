#pragma once

#include "Board.hpp"
#include <string>

class StdioBoardView {
  public:
    StdioBoardView(Board &newboard);

    void runGame(bool silent);

  private:

    void printBoard() const;

    void printPlayerMove(fieldState player) const;

    bool is_input_correct(int &x, int &y, std::string &buffer) const;

    Board &board;
};