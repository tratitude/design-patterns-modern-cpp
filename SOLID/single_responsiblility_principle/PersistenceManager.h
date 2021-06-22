#pragma once

#include <fstream>
#include <string>

#include "Journal.hpp"

//#include "IOManager.hpp"

class PersistenceManager {
 public:
  static auto save(const Journal& j, const std::string& fileName) {
    std::ofstream ofs(fileName);
    for (auto& str : j.entries) {
      ofs << str << std::endl;
    }
  }
};