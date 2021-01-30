#ifndef ITEMUPDATER_H
#define ITEMUPDATER_H

#include <memory>

#include "Item.h"

class ItemUpdater {
 public:
  ItemUpdater(Item& item) : item{&item} {}

  virtual void update() {
    decreaseSellIn();
    updateQualityFor();
  }

  virtual void updateQualityFor() {
    if (item->sellIn > 0) {
      decreaseBy(1);
    } else {
      decreaseBy(2);
    }
  }

 protected:
  void increaseBy(int quality) {
    item->quality += quality;
    if (item->quality > maxQuality) {
      item->quality = maxQuality;
    }
  }

  void decreaseBy(int quality) {
    item->quality -= quality;
    if (item->quality < minQuality) {
      item->quality = minQuality;
    }
  }

  void decreaseSellIn() {
    --item->sellIn;
    if (item->sellIn < 0) {
      item->sellIn = 0;
    }
  }

  Item* item;

 private:
  constexpr static int minQuality = 0;
  constexpr static int maxQuality = 50;
};

class AgedBrieUpdater : public ItemUpdater {
 public:
  using ItemUpdater::ItemUpdater;

  void updateQualityFor() override { increaseBy(1); }
};

class BackstagePassUpdater : public ItemUpdater {
 public:
  using ItemUpdater::ItemUpdater;

  void updateQualityFor() override {
    if (item->sellIn >= 10) {
      increaseBy(1);
    } else if (item->sellIn >= 5) {
      increaseBy(2);
    } else if (item->sellIn > 0) {
      increaseBy(3);
    } else {
      item->quality = 0;
    }
  }
};

class SulfurasUpdater : public ItemUpdater {
 public:
  using ItemUpdater::ItemUpdater;

  void update() override {}
};

class ConjuredUpdater : public ItemUpdater {
 public:
  using ItemUpdater::ItemUpdater;

  void updateQualityFor() override {
    if (item->sellIn > 0) {
      decreaseBy(2);
    } else {
      decreaseBy(4);
    }
  }
};

inline std::unique_ptr<ItemUpdater> makeItemUpdater(Item& item) {
  if (item.name == "Aged Brie") {
    return std::make_unique<AgedBrieUpdater>(item);
  }
  if (item.name == "Backstage pass") {
    return std::make_unique<BackstagePassUpdater>(item);
  }
  if (item.name == "Sulfuras") {
    return std::make_unique<SulfurasUpdater>(item);
  }
  if (item.name == "Conjured") {
    return std::make_unique<ConjuredUpdater>(item);
  }
  return std::make_unique<ItemUpdater>(item);
}

#endif
