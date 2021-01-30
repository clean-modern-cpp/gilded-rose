#ifndef GILDED_ROSE_ITEM_H
#define GILDED_ROSE_ITEM_H

#include <ostream>
#include <string>
#include <vector>

struct Item {
  std::string name;
  int sellIn;
  int quality;
};

using Items = std::vector<Item>;

inline bool operator==(const Item &lhs, const Item &rhs) {
  return lhs.name == rhs.name && lhs.sellIn == rhs.sellIn &&
         lhs.quality == rhs.quality;
}

namespace std {

inline std::ostream &operator<<(std::ostream &os, const Item &item) {
  os << "{" << item.name << ", " << item.sellIn << ", " << item.quality << "}";
  return os;
}

inline std::ostream &operator<<(std::ostream &os, const Items &items) {
  os << "{\n";
  for (const auto &item : items) {
    os << "    " << item << "\n";
  }
  os << "}\n";
  return os;
}

}  // namespace std

#endif
