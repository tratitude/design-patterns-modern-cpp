#pragma once

#include <iostream>
#include <ostream>
#include <string>

template <typename IStream, typename OStream>
class IOManager {
 public:
  IOManager(IStream is, OStream os) : is{is}, os{os} {};

  virtual ~IOManager() = default;

  virtual auto input(const std::string &&) -> void = 0;
  virtual auto output() -> void = 0;

 private:
  IStream is;
  OStream os;
};