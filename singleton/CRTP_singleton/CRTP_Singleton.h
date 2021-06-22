#pragma once

#include <iostream>

template <typename Impl>
class CRTP_Singleton {
 public:
  CRTP_Singleton(const CRTP_Singleton&) = delete;
  CRTP_Singleton& operator=(CRTP_Singleton const&) = delete;
  ~CRTP_Singleton() { std::cout << "CRTP::~CRTP_Singleton\n"; }

  static Impl& getInstance() {
    std::cout << "CRTP::getInstance before impl instance\n";
    static Impl impl;
    std::cout << "CRTP::getInstance after impl instance\n";

    return impl;
  }

 protected:
  // Protected constructor for not allowing client code creating more
  // than one instance
  CRTP_Singleton() { std::cout << "CRTP::CRTP_Singleton\n"; }
};