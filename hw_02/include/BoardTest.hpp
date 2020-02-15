#pragma once
#define DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__);

#include "Test.hpp"
#include "Board.hpp"

class BoardTest : public Test {
  private:
    void testMove1();

    void testMove2();

    void testMove3();

    void testCanMove1();

    void testCanMove2();

    void testCanMove3();

    void testCanMove4();

    void testCurrentPlayer1();

    void testCurrentPlayer2();

    void testCurrentPlayer3();

    void testGetState1();

    void testGetState2();

    void testGetState3();

    void testIsFinished1();

    void testIsFinished2();

    void testIsFinished3();

    void testIsFinished4();

  public:
    void runAllTests() override;
};