#pragma once

#include <iostream>

#include "CRTP_Singleton.h"

class PrintManager : public CRTP_Singleton<PrintManager> {
  friend PrintManager::CRTP_Singleton<PrintManager>;

 public:
  // Error! Default constructor must be called once in getInstance()
  // PrintManager() = delete;
  ~PrintManager() { std::cout << "PrintManager::~PrintManager\n"; }
  PrintManager& print() {
    std::cout << "sigleton: " << sigleton_ << "\n";

    return *this;
  }
  PrintManager& modify(int x) {
    sigleton_ = x;

    return *this;
  }

 protected:
  // Protected constructor for not allowing client code creating more
  // than one instance
  PrintManager() { std::cout << "PrintManager::PrintManager\n"; }

 private:
  int sigleton_ = 0;
};