#pragma once

#include <cstdio>

enum class gameState {
    IN_PROCESS,
    WIN_O,
    WIN_X,
    DRAW,
};

enum class fieldState {
    NONE,
    O,
    X,
};

class Board {
  public:
    Board();

    bool canMove(int x, int y, fieldState current_player) const;

    void move(int x, int y, fieldState current_player);

    bool is_finished(int x, int y, fieldState current_player) const;

    fieldState current_player() const;

    static const int sz_field = 10;
    static const int sz_win = 5;
    static const int sz_draw = sz_field * sz_field / 2;

    gameState getState() const;

    fieldState getFieldState(const size_t i, const size_t j) const;

    void counting(int x, int y, int &count, int *arr_x, int *arr_y, bool is_second, fieldState current_player,
                  size_t i) const;

    mutable gameState _state;

  private:
    fieldState field[sz_field][sz_field];
};