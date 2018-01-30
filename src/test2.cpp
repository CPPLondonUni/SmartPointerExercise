#include "exercise2.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  int randomDataBlockSize = (argc > 1) ? std::stoi(argv[1]) : 1000;
  RandomDataProvider provider(randomDataBlockSize);

  std::cerr << "Start testing...\n";
  if (!provider.GetRandomData())
    std::cerr << "GetRandomData wasnt created\n";
  else {
    std::cerr << "Test 1 passed\n";
    if (provider.GetRandomDataAt(randomDataBlockSize) != 0)
      std::cerr << "GetRandomDataAt failed with a too large number\n";
    else {
      std::cerr << "Test 2 passed\n";
      if (provider.GetRandomData()[randomDataBlockSize - 1] !=
              provider.GetRandomDataAt(randomDataBlockSize - 1) ||
          provider.GetRandomData()[0] != provider.GetRandomDataAt(0))
        std::cerr << "GetRandomData and GetRandomDataAt doesnt return the same "
                     "number\n";
      else {
        provider.ResetData(10);
        if (provider.GetRandomDataAt(11) == 0) {
          std::cout << "All test Cases Passed!\n";
          return 0;
        }
      }
    }
  }
  std::cerr << "A test case failed!\n";
  return 1;
}
