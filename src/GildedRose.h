#ifndef GILDEDROSE_H
#define GILDEDROSE_H

#include "Item.h"
#include "ItemUpdater.h"

struct GildedRose {
  GildedRose(Items items) : items{items} {}

  void updateQuality() {
    for (auto& item : items) {
      auto updater = makeItemUpdater(item);
      updater->update();
    }
  }

  std::vector<Item> items;
};

#endif
