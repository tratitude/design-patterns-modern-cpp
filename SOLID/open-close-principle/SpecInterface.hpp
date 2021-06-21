#pragma once

// Forward type declaration for AndSpec
template <typename T>
class AndSpec;

template <typename T>
class SpecInterface {
 public:
  virtual auto is_satisfied(T* item) -> bool = 0;
  auto operator&&(SpecInterface&& other) -> AndSpec<T> {
    return AndSpec<T>(*this, other);
  }
};

// Type implementation for AndSpec
template <typename T>
class AndSpec : public SpecInterface<T> {
 public:
  AndSpec(SpecInterface<T>& first, SpecInterface<T>& second)
      : first{first}, second{second} {}
  auto is_satisfied(T* item) -> bool override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }

 private:
  SpecInterface<T>&first, &second;
};