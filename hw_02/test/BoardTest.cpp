#include "BoardTest.hpp"

void BoardTest::testMove1() {
    Board b;
    b.move(0, 0, fieldState::X);
    b.move(9, 9, fieldState::O);
    DO_CHECK(!b.canMove(9, 9, fieldState::X));
}

void BoardTest::testMove2() {
    Board b;
    b.move(0, 0, fieldState::X);
    b.move(9, 1, fieldState::O);
    DO_CHECK(b.canMove(5, 7, fieldState::X));
}

void BoardTest::testMove3() {
    Board b;
    b.move(0, 0, fieldState::X);
    b.move(4, 3, fieldState::O);
    b.move(2, 4, fieldState::X);
    b.move(2, 2, fieldState::O);
    b.move(8, 7, fieldState::X);
    DO_CHECK(b.canMove(1, 1, fieldState::O));
}

void BoardTest::testCanMove1() {
    Board b;
    b.move(4, 3, fieldState::O);
    DO_CHECK(!b.canMove(4, 3, fieldState::X));
}

void BoardTest::testCanMove2() {
    Board b;
    DO_CHECK(!b.canMove(-1, 3, fieldState::X));
}

void BoardTest::testCanMove3() {
    Board b;
    DO_CHECK(!b.canMove(1, 13, fieldState::O));
}

void BoardTest::testCanMove4() {
    Board b;
    DO_CHECK(b.canMove(6, 7, fieldState::O));
}

void BoardTest::testCurrentPlayer1() {
    Board b;
    b.move(8, 9, fieldState::O);
    b.move(0, 1, fieldState::X);
    b.move(6, 3, fieldState::O);
    b.move(4, 7, fieldState::X);
    DO_CHECK(b.current_player() == fieldState::O);
}

void BoardTest::testCurrentPlayer2() {
    Board b;
    b.move(8, 9, fieldState::O);
    b.move(3, 1, fieldState::X);
    b.move(9, 7, fieldState::O);
    b.move(3, 9, fieldState::X);
    b.move(6, 0, fieldState::O);
    b.move(7, 6, fieldState::X);
    DO_CHECK(b.current_player() == fieldState::O);
}

void BoardTest::testCurrentPlayer3() {
    Board b;
    b.move(0, 0, fieldState::O);
    b.move(0, 1, fieldState::O);
    b.move(0, 2, fieldState::O);
    b.move(0, 3, fieldState::O);
    b.move(0, 4, fieldState::O);
    b.move(0, 5, fieldState::O);
    b.move(0, 6, fieldState::O);
    b.move(0, 7, fieldState::O);
    b.move(0, 8, fieldState::O);
    b.move(0, 9, fieldState::O);

    b.move(1, 0, fieldState::O);
    b.move(1, 1, fieldState::O);
    b.move(1, 2, fieldState::O);
    b.move(1, 3, fieldState::O);
    b.move(1, 4, fieldState::O);
    b.move(1, 5, fieldState::O);
    b.move(1, 6, fieldState::O);
    b.move(1, 7, fieldState::O);
    b.move(1, 8, fieldState::O);
    b.move(1, 9, fieldState::O);

    b.move(2, 0, fieldState::O);
    b.move(2, 1, fieldState::O);
    b.move(2, 2, fieldState::O);
    b.move(2, 3, fieldState::O);
    b.move(2, 4, fieldState::O);
    b.move(2, 5, fieldState::O);
    b.move(2, 6, fieldState::O);
    b.move(2, 7, fieldState::O);
    b.move(2, 8, fieldState::O);
    b.move(2, 9, fieldState::O);

    b.move(3, 0, fieldState::O);
    b.move(3, 1, fieldState::O);
    b.move(3, 2, fieldState::O);
    b.move(3, 3, fieldState::O);
    b.move(3, 4, fieldState::O);
    b.move(3, 5, fieldState::O);
    b.move(3, 6, fieldState::O);
    b.move(3, 7, fieldState::O);
    b.move(3, 8, fieldState::O);
    b.move(3, 9, fieldState::O);

    b.move(4, 0, fieldState::O);
    b.move(4, 1, fieldState::O);
    b.move(4, 2, fieldState::O);
    b.move(4, 3, fieldState::O);
    b.move(4, 4, fieldState::O);
    b.move(4, 5, fieldState::O);
    b.move(4, 6, fieldState::O);
    b.move(4, 7, fieldState::O);
    b.move(4, 8, fieldState::O);
    b.move(4, 9, fieldState::O);

    b.move(5, 0, fieldState::X);
    b.move(5, 1, fieldState::X);
    b.move(5, 2, fieldState::X);
    b.move(5, 3, fieldState::X);
    b.move(5, 4, fieldState::X);
    b.move(5, 5, fieldState::X);
    b.move(5, 6, fieldState::X);
    b.move(5, 7, fieldState::X);
    b.move(5, 8, fieldState::X);
    b.move(5, 9, fieldState::X);

    b.move(6, 0, fieldState::X);
    b.move(6, 1, fieldState::X);
    b.move(6, 2, fieldState::X);
    b.move(6, 3, fieldState::X);
    b.move(6, 4, fieldState::X);
    b.move(6, 5, fieldState::X);
    b.move(6, 6, fieldState::X);
    b.move(6, 7, fieldState::X);
    b.move(6, 8, fieldState::X);
    b.move(6, 9, fieldState::X);

    b.move(7, 0, fieldState::X);
    b.move(7, 1, fieldState::X);
    b.move(7, 2, fieldState::X);
    b.move(7, 3, fieldState::X);
    b.move(7, 4, fieldState::X);
    b.move(7, 5, fieldState::X);
    b.move(7, 6, fieldState::X);
    b.move(7, 7, fieldState::X);
    b.move(7, 8, fieldState::X);
    b.move(7, 9, fieldState::X);

    b.move(8, 0, fieldState::X);
    b.move(8, 1, fieldState::X);
    b.move(8, 2, fieldState::X);
    b.move(8, 3, fieldState::X);
    b.move(8, 4, fieldState::X);
    b.move(8, 5, fieldState::X);
    b.move(8, 6, fieldState::X);
    b.move(8, 7, fieldState::X);
    b.move(8, 8, fieldState::X);
    b.move(8, 9, fieldState::X);

    b.move(9, 0, fieldState::X);
    b.move(9, 1, fieldState::X);
    b.move(9, 2, fieldState::X);
    b.move(9, 3, fieldState::X);
    b.move(9, 4, fieldState::X);
    b.move(9, 5, fieldState::X);
    b.move(9, 6, fieldState::X);
    b.move(9, 7, fieldState::X);
    b.move(9, 8, fieldState::X);
    b.move(9, 9, fieldState::X);

    DO_CHECK(b.current_player() == fieldState::NONE);
}

void BoardTest::testGetState1() {
    Board b;
    b.move(8, 3, fieldState::X);
    b.move(5, 7, fieldState::O);
    b.move(4, 8, fieldState::O);
    DO_CHECK(b.getState() == gameState::IN_PROCESS);
}

void BoardTest::testGetState2() {
    Board b;
    b.move(0, 0, fieldState::O);
    b.move(1, 1, fieldState::O);
    b.move(3, 3, fieldState::O);
    b.move(4, 4, fieldState::O);
    b.move(5, 5, fieldState::O);
    b.move(2, 2, fieldState::O);
    b.is_finished(2, 2, fieldState::O);
    DO_CHECK(b.getState() == gameState::WIN_O);
}

void BoardTest::testGetState3() {
    Board b;
    b.move(4, 1, fieldState::X);
    b.move(4, 3, fieldState::X);
    b.move(4, 4, fieldState::X);
    b.move(4, 5, fieldState::X);
    b.move(4, 7, fieldState::X);
    b.move(4, 8, fieldState::X);
    b.move(4, 9, fieldState::X);
    b.move(4, 6, fieldState::X);
    b.is_finished(4, 6, fieldState::X);
    DO_CHECK(b.getState() == gameState::WIN_X);
}

void BoardTest::testIsFinished1() {
    Board b;
    b.move(7, 1, fieldState::X);
    b.move(7, 3, fieldState::X);
    b.move(7, 4, fieldState::X);
    b.move(4, 4, fieldState::O);
    b.move(7, 5, fieldState::X);
    b.move(7, 7, fieldState::X);
    b.move(7, 2, fieldState::X);
    DO_CHECK(b.is_finished(7, 2, fieldState::X));
}

void BoardTest::testIsFinished2() {
    Board b;
    b.move(1, 0, fieldState::O);
    b.move(3, 0, fieldState::O);
    b.move(4, 0, fieldState::O);
    b.move(4, 7, fieldState::X);
    b.move(5, 0, fieldState::O);
    b.move(7, 0, fieldState::O);
    b.move(2, 0, fieldState::O);
    DO_CHECK(b.is_finished(2, 0, fieldState::O));
}

void BoardTest::testIsFinished3() {
    Board b;
    b.move(3, 4, fieldState::X);
    b.move(4, 5, fieldState::X);
    b.move(5, 2, fieldState::O);
    b.move(0, 0, fieldState::O);
    b.move(5, 6, fieldState::X);
    b.move(6, 7, fieldState::X);
    b.move(7, 8, fieldState::X);
    DO_CHECK(b.is_finished(7, 8, fieldState::X));
}

void BoardTest::testIsFinished4() {
    Board b;
    b.move(4, 4, fieldState::O);
    b.move(9, 8, fieldState::X);
    b.move(3, 5, fieldState::O);
    b.move(3, 0, fieldState::X);
    b.move(2, 6, fieldState::O);
    b.move(1, 7, fieldState::O);
    b.move(4, 0, fieldState::X);
    b.move(0, 8, fieldState::O);
    DO_CHECK(b.is_finished(0, 8, fieldState::O));

}

void BoardTest::runAllTests() {
    testMove1();
    testMove2();
    testMove3();

    testCanMove1();
    testCanMove2();
    testCanMove3();
    testCanMove4();

    testCurrentPlayer1();
    testCurrentPlayer2();
    testCurrentPlayer3();

    testGetState1();
    testGetState2();
    testGetState3();

    testIsFinished1();
    testIsFinished2();
    testIsFinished3();
    testIsFinished4();

}