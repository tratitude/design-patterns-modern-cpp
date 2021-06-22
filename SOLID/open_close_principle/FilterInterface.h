#pragma once

#include <vector>

#include "SpecInterface.hpp"

template <typename T>
class FilterInterface {
 public:
  virtual auto filter(std::vector<T*> items, SpecInterface<T>& spec)
      -> std::vector<T*> = 0;
};