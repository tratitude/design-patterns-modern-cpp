#pragma once

#include "Product.hpp"
#include "SpecInterface.hpp"

class ColorSpec : public SpecInterface<Product> {
 public:
  explicit ColorSpec(const Color color) : color{color} {}
  auto is_satisfied(Product* item) -> bool override {
    return item->color == color;
  }

 private:
  Color color;
};