#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#include <iostream>

#include "GildedRose.h"

inline void update() {
  GildedRose gildedRose{{
      {"Dexterity", 10, 20},
      {"Aged Brie", 2, 0},
      {"Elixir", 5, 7},
      {"Sulfuras", 0, 80},
      {"Backstage pass", 15, 20},
      {"Conjured", 3, 6},
  }};
  gildedRose.updateQuality();
  std::cout << gildedRose.items << std::endl;
}

int main(int argc, char** argv) {
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  int res = ctx.run();
  if (ctx.shouldExit()) {
    return res;
  }

  update();

  return res;
}
