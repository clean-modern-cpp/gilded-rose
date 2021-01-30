#include <string>
#include <vector>

struct Item {
 public:
  std::string name;
  int sellIn;
  int quality;
};

class GildedRose {
 public:
  GildedRose(std::vector<Item> items);

  void updateQuality();

 private:
  std::vector<Item> items;
};
