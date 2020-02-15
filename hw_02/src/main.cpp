#include "StdioBoardView.hpp"

int main(int argc, char **argv) {
    bool silent = false;
    if (argc == 1) {
        silent = false;
    } else if (strcmp(argv[1], "silent") == 0) {
        silent = true;
    }
    Board board;
    StdioBoardView view(board);
    view.runGame(silent);
}