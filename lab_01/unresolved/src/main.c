#include "io.h"
#include "algorithm.h"
#include "util.h"

int main() {
  int a = doComputation(5, 7);
  int b = 5;
  max(a, b);
  logDebug('!');
  return 0;
}