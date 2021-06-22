#include <iostream>

#include "CRTP_Singleton.h"
#include "PrintManager.h"

using namespace std;

int main() {
  cout << "\n\n------------start in main-------------\n\n";

  cout << "\n\n--------getInstance for pm1-----------\n\n";
  auto& pm1 = PrintManager::getInstance();
  pm1.print().modify(1).print();

  cout << "\n\n--------getInstance for pm2-----------\n\n";
  auto& pm2 = PrintManager::getInstance();
  pm2.print().modify(2).print();
}