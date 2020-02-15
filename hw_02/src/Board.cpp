#include "Board.hpp"
#include <algorithm>

Board::Board() {
    for (std::size_t i = 0; i < sz_field; i++) {
        for (std::size_t j = 0; j < sz_field; j++) {
            field[i][j] = fieldState::NONE;
        }
    }
    _state = gameState::IN_PROCESS;
}

bool Board::canMove(int x, int y, fieldState current_player) const {
    (void) current_player;
    return !(x >= sz_field || y >= sz_field || x < 0 || y < 0 || field[x][y] != fieldState::NONE);
}

void Board::move(int x, int y, fieldState current_player) {
    field[x][y] = current_player;
}

fieldState Board::current_player() const {
    int countX = 0;
    int countO = 0;
    for (std::size_t i = 0; i < sz_field; i++) {
        for (std::size_t j = 0; j < sz_field; j++) {
            if (field[i][j] == fieldState::X)
                countX++;
            else if (field[i][j] == fieldState::O)
                countO++;
        }
    }
    if (countO > countX)
        return fieldState::X;
    else if (countX == sz_draw && countO == sz_draw)
        return fieldState::NONE;
    else
        return fieldState::O;
}

void Board::counting(int x, int y, int &count, int *arr_x, int *arr_y, bool is_second, fieldState current_player,
                     size_t i) const {
    while (x >= 0 && y >= 0 && x < Board::sz_field && y < Board::sz_field) {
        if (getFieldState(x, y) != current_player) { break; }
        if (is_second) {
            x += arr_x[i];
            y += arr_y[i];
        } else {
            x -= arr_x[i];
            y -= arr_y[i];
        }
        count++;
    }
}

bool Board::is_finished(int x, int y, fieldState current_player) const {
    int arr_x[sz_win - 1] = {-1, 0, 1, 1};
    int arr_y[sz_win - 1] = {1, 1, 0, 1};
    for (std::size_t i = 0; i < sz_win - 1; i++) {
        int old_x = x, old_y = y, count = -1;
        counting(x, y, count, arr_x, arr_y, 0, current_player, i);
        x = old_x;
        y = old_y;
        counting(x, y, count, arr_x, arr_y, 1, current_player, i);
        if (count >= sz_win) {
            if (current_player == fieldState::X) {
                _state = gameState::WIN_X;
            } else {
                _state = gameState::WIN_O;
            }
            return true;
        }
    }
    return false;
}

gameState Board::getState() const {
    return _state;
}

fieldState Board::getFieldState(const size_t i, const size_t j) const {
    return field[i][j];
}

