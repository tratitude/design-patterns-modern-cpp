#include <iostream>
#include <string>
#include <vector>

#include "ColorSpec.hpp"
#include "Product.hpp"
#include "SimpleFilter.hpp"
#include "SizeSpec.hpp"
using namespace std;

int main() {
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  vector<Product*> all{&apple, &tree, &house};
  SimpleFilter filter;
  auto green_and_large = ColorSpec{Color::Green} && SizeSpec{Size::Large};

  auto green_things = filter.filter(all, green_and_large);
  for (auto& result : green_things)
    cout << result->name << " is green and large\n";
}