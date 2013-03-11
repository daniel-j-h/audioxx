#pragma once

#include <stdexcept>
#include <AL/alure.h>

namespace Audio {

  class Device final {
    public:
      Device() {
        if(not alureInitDevice(nullptr, nullptr))
          throw std::runtime_error("error: device");
      }

      ~Device() {
        alureShutdownDevice();
      }
  };

}
