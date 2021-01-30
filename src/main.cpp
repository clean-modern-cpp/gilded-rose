#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#include <iostream>

int main(int argc, char** argv) {
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  int res = ctx.run();
  if (ctx.shouldExit()) {
    return res;
  }

  std::cout << "Hello world\n";

  return res;
}
