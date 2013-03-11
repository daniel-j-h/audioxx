#pragma once

#include <string>
#include <stdexcept>
#include <AL/alure.h>

namespace Audioxx {

  class Device final {

    public:
      Device() {
        if(alureInitDevice(nullptr, nullptr) == AL_FALSE)
          throw std::runtime_error("Error: Unable to create device: " + std::string(alureGetErrorString()));
      }

      ~Device() {
        alureShutdownDevice();
      }

  };

}
