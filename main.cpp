#include <cstdlib>

#include <iostream>
#include <vector>

#include "Player.hpp"

/*
 * g++-4.7 -std=c++11 -O0 -g -Wall -Wextra -pedantic main.cpp `pkg-config --cflags --libs alure`
 */

int main(int argc, char* argv[]) {
  std::vector<std::string> params(argv, argv + argc);

  if(params.size() != 2) {
    std::cerr << "usage: ./a.out file" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  try {

    Audio::Player player(params[1]);
    player.play();

  } catch(const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
  }
}
