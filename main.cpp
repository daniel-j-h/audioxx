#include <cstdlib>

#include <iostream>
#include <vector>

#include "Player.hpp"


int main(int argc, char* argv[]) {
  std::vector<std::string> params(argv, argv + argc);

  if(params.size() != 3) {
    std::cerr << "usage: ./audioxx [ -stream | -play ] file" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  try {

    Audioxx::Player player;

    if(params[1] == "-play")
      player.play(params[2]);
    else if(params[1] == "-stream")
      player.stream(params[2]);

  } catch(const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}
