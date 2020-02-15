#include <iostream>
#include "Test.hpp"

int Test::failedNum = 0;
int Test::totalNum = 0;

void Test::check(bool expr, const char *func, const char *filename, size_t lineNum) {
    totalNum++;
    if (!expr) {
        failedNum++;
        std::cout << "FAILED in file: " << filename
                  << " in func: " << func << " in line: " << lineNum << "\n";
    }
}

bool Test::showFinalResult() {
    std::cout << "FAILED: " << failedNum << "/" << totalNum
              << " ACCEPTED: " << totalNum - failedNum << "/" << totalNum << "\n";
    return failedNum == 0;
}