#ifndef GILDED_ROSE_GILDED_ROSE_H
#define GILDED_ROSE_GILDED_ROSE_H

#include "Item.h"

struct GildedRose {
  GildedRose(Items items) : items{items} {}

  void updateQuality() {
    for (auto& item : items) {
      if (item.name != "Sulfuras") {
        if (item.sellIn > 0) {
          --item.sellIn;
          if (item.name == "Aged Brie") {
            if (item.quality < 50) {
              ++item.quality;
            }
          } else if (item.name == "Backstage pass") {
            if (item.sellIn >= 10) {
              if (item.quality < 50) {
                ++item.quality;
              }
            } else if (item.sellIn >= 5) {
              if (item.quality < 49) {
                item.quality += 2;
              }
            } else if (item.sellIn > 0) {
              if (item.quality < 48) {
                item.quality += 3;
              }
            } else {
              item.quality = 0;
            }
          } else if (item.quality > 0) {
            --item.quality;
          }
        } else {
          if (item.quality >= 2) {
            item.quality -= 2;
          }
        }
      }
    }
  }

  std::vector<Item> items;
};

#endif
