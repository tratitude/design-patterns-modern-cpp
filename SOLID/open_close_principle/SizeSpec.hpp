#pragma once

#include "Product.hpp"
#include "SpecInterface.hpp"

class SizeSpec : public SpecInterface<Product> {
 public:
  explicit SizeSpec(const Size size) : size{size} {}
  auto is_satisfied(Product* item) -> bool override {
    return item->size == size;
  }

 private:
  Size size;
};