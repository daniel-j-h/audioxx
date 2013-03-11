#pragma once

#include <stdexcept>
#include <AL/alure.h>

namespace Audioxx {

  class Device final {
    public:
      Device() {
        if(not alureInitDevice(nullptr, nullptr))
          throw std::runtime_error("error: unable to create device");
      }

      ~Device() {
        alureShutdownDevice();
      }
  };

}
