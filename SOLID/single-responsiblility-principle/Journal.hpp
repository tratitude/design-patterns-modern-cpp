#pragma once

#include <string>
#include <vector>

struct Journal {
  std::string title;
  std::vector<std::string> entries;

  explicit Journal(const std::string&& title) : title(title) {}
};