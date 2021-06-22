#pragma once

#include <vector>

#include "FilterInterface.hpp"
#include "Product.hpp"
#include "SpecInterface.hpp"

class SimpleFilter : public FilterInterface<Product> {
 public:
  auto filter(std::vector<Product*> items, SpecInterface<Product>& spec)
      -> std::vector<Product*> override {
    std::vector<Product*> result;
    for (auto& item : items) {
      if (spec.is_satisfied(item)) result.push_back(item);
    }
    return result;
  }
};