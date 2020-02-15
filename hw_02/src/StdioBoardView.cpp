#include "StdioBoardView.hpp"
#include <iostream>

StdioBoardView::StdioBoardView(Board &newboard) : board(newboard) {}

void StdioBoardView::printBoard() const {
    for (size_t i = 0; i < board.sz_field; i++) {
        for (size_t j = 0; j < board.sz_field; j++) {
            if (board.getFieldState(i, j) == fieldState::NONE)
                std::cout << '.';
            else if (board.getFieldState(i, j) == fieldState::X)
                std::cout << 'X';
            else if (board.getFieldState(i, j) == fieldState::O)
                std::cout << 'O';
            if (j == board.sz_field - 1)
                std::cout << '\n';
        }
    }
}

void StdioBoardView::printPlayerMove(fieldState player) const {
    if (player == fieldState::X)
        std::cout << 'X';
    else if (player == fieldState::O)
        std::cout << 'O';
    else if (player == fieldState::NONE) {
        std::cout << "DRAW\n";
    }
    std::cout << " move: ";
}

bool StdioBoardView::is_input_correct(int &x, int &y, std::string &buffer) const {
    while (buffer.back() == ' ') { buffer.pop_back(); }
    char c, temp;
    return (std::sscanf(buffer.c_str(), "%d%c%d%c", &x, &c, &y, &temp) == 3 && c == ' ');
}

void StdioBoardView::runGame(bool silent) {
    bool game_continues = true;
    if (!silent) {
        std::cout << '\n';
        printBoard();
    }
    printPlayerMove(board.current_player());
    while (game_continues) {
        int x, y;
        std::string buffer;
        std::getline(std::cin, buffer);

        if (!is_input_correct(x, y, buffer)) {
            std::cout << "Bad move!\n";
            printPlayerMove(board.current_player());
            continue;
        }

        fieldState cur_player = board.current_player();

        if (x == -1 && y == -1)
            break;
        if (board.canMove(x, y, cur_player)) {

            board.move(x, y, cur_player);

            if (!silent) {
                std::cout << '\n';
                printBoard();
            }

            if (board.is_finished(x, y, cur_player)) {
                if (silent) {
                    std::cout << '\n';
                    printBoard();
                }
                if (board.getState() == gameState::WIN_X) {
                    std::cout << "X wins!\n";
                } else {
                    std::cout << "O wins!\n";
                }
                break;
            }

            printPlayerMove(board.current_player());
        } else if (board.current_player() == fieldState::NONE) {
            board._state = gameState::DRAW;
            std::cout << "Draw.\n";
            break;
        } else {
            std::cout << "Bad move!\n";
            printPlayerMove(cur_player);
        }
    }
}
