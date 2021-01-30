#ifndef GILDED_ROSE_GILDED_ROSE_H
#define GILDED_ROSE_GILDED_ROSE_H

#include "Item.h"

struct GildedRose {
  GildedRose(Items items) : items{items} {}

  void updateQuality() {
    for (auto& item : items) {
      if (item.sellIn > 0) {
        --item.sellIn;
        if (item.quality > 0) {
          --item.quality;
        }
      } else {
        if (item.quality >= 2) {
          item.quality -= 2;
        }
      }
    }
  }

  std::vector<Item> items;
};

#endif
