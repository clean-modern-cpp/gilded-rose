#include <doctest/doctest.h>

#include "GildedRose.h"

TEST_CASE("Quality drop 1 when sellIn greater than 0") {
  GildedRose gildedRose{{
      {"Name", 1, 1},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Name", 0, 0},
                               });
}

TEST_CASE("Quality drop 2 when sellIn equal to 0") {
  GildedRose gildedRose{{
      {"Name", 0, 2},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Name", 0, 0},
                               });
}

TEST_CASE("Quality always greater or equal to 0") {
  GildedRose gildedRose{{
      {"Name", 0, 0},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Name", 0, 0},
                               });
}
