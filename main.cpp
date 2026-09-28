#include <iostream>
#include <fstream>
#include <string>

#include "src/monopoly.hpp"

int main() {
  Monopoly<std::string> m;

  std::ifstream file ("../monopoly_spaces.txt");

  std::string line;
  while (std::getline(file, line)) {
    m.append(line);
  }

  file.close();

  m.step();

  for (int i = 0; i < 41; ++i) {
    std::cout << i + 1 << ". " << m.getCurrent() << std::endl;
    m.step(); // Move to the next space for the next iteration
  }

  std::cout << m.getCurrent() << std::endl;

  m.step();
  m.step();
  m.step();

  std::cout << "\n" << m.getCurrent() << std::endl;

  m.randomMove();



  return 0;
}
