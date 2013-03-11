#include <cstdlib>

#include <iostream>
#include <vector>

#include "Player.hpp"


int main(int argc, char* argv[]) {
  std::vector<std::string> params(argv, argv + argc);

  if(params.size() != 2) {
    std::cerr << "usage: ./audioxx file" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  try {

    Audioxx::Player player(params[1]);
    player.play();

  } catch(const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}
