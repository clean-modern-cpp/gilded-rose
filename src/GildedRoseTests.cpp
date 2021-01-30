#include <doctest/doctest.h>

#include "GildedRose.h"

TEST_CASE("Quality degrades 1 when sellIn greater than 0") {
  GildedRose gildedRose{{
      {"Name", 2, 1},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Name", 1, 0},
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

TEST_CASE("Quality is always greater or equal to 0") {
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
  SUBCASE("10 days") {
    GildedRose gildedRose{{
        {"Backstage pass", 10, 1},
    }};
    gildedRose.updateQuality();
    REQUIRE_EQ(gildedRose.items, Items{
                                     {"Backstage pass", 9, 3},
                                 });
  }

  SUBCASE("Less than 10 days") {
    GildedRose gildedRose{{
        {"Backstage pass", 7, 1},
    }};
    gildedRose.updateQuality();
    REQUIRE_EQ(gildedRose.items, Items{
                                     {"Backstage pass", 6, 3},
                                 });
  }
}

TEST_CASE(
    "Backstage pass quality increase by 3 when there are 5 days or less") {
  SUBCASE("5 days") {
    GildedRose gildedRose{{
        {"Backstage pass", 5, 1},
    }};
    gildedRose.updateQuality();
    REQUIRE_EQ(gildedRose.items, Items{
                                     {"Backstage pass", 4, 4},
                                 });
  }

  SUBCASE("Less than 5 days") {
    GildedRose gildedRose{{
        {"Backstage pass", 3, 1},
    }};
    gildedRose.updateQuality();
    REQUIRE_EQ(gildedRose.items, Items{
                                     {"Backstage pass", 2, 4},
                                 });
  }
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

TEST_CASE("More items") {
  GildedRose gildedRose{{
      {"Dexterity", 10, 20},
      {"Aged Brie", 2, 0},
      {"Elixir", 5, 7},
      {"Sulfuras", 0, 80},
      {"Backstage pass", 15, 20},
      {"Conjured", 3, 6},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Dexterity", 9, 19},
                                   {"Aged Brie", 1, 1},
                                   {"Elixir", 4, 6},
                                   {"Sulfuras", 0, 80},
                                   {"Backstage pass", 14, 21},
                                   {"Conjured", 2, 4},
                               });
}

TEST_CASE("Conjured quality degrades 2 when sellIn greater than 0") {
  GildedRose gildedRose{{
      {"Conjured", 2, 2},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Conjured", 1, 0},
                               });
}

TEST_CASE("Conjured quality degrades 4 when sellIn equal to 0") {
  GildedRose gildedRose{{
      {"Conjured", 0, 4},
  }};
  gildedRose.updateQuality();
  REQUIRE_EQ(gildedRose.items, Items{
                                   {"Conjured", 0, 0},
                               });
}
