#include <doctest/doctest.h>

#include "GildedRose.h"

TEST_CASE("Quality degrades 1 when sellIn greater than 0") {
  GildedRose gildedRose{{
      {"Name", 1, 1},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Name", 0, 0},
                               });
}

TEST_CASE("Quality degrades 2 when sellIn equal to 0") {
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

TEST_CASE("Aged Brie quality increases by 1") {
  GildedRose gildedRose{{
      {"Aged Brie", 1, 1},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Aged Brie", 0, 2},
                               });
}

TEST_CASE("Quality always less or equal to 50") {
  GildedRose gildedRose{{
      {"Aged Brie", 1, 50},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Aged Brie", 0, 50},
                               });
}

TEST_CASE("SellIn and quality never change for Sulfuras") {
  GildedRose gildedRose{{
      {"Sulfuras", 1, 1},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Sulfuras", 1, 1},
                               });
}

TEST_CASE(
    "Backstage pass quality increase by 1 when there are more than 10 days") {
  GildedRose gildedRose{{
      {"Backstage pass", 11, 1},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Backstage pass", 10, 2},
                               });
}

TEST_CASE(
    "Backstage pass quality increase by 2 when there are 10 days or less") {
  GildedRose gildedRose{{
      {"Backstage pass", 10, 1},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Backstage pass", 9, 3},
                               });
}

TEST_CASE(
    "Backstage pass quality increase by 3 when there are 5 days or less") {
  GildedRose gildedRose{{
      {"Backstage pass", 5, 1},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Backstage pass", 4, 4},
                               });
}

TEST_CASE("Backstage pass quality drops to 0 after the concert") {
  GildedRose gildedRose{{
      {"Backstage pass", 1, 10},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Backstage pass", 0, 0},
                               });
}
