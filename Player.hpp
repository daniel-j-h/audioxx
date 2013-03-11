#pragma once

#include <string>
#include <stdexcept>

#include <AL/alure.h>

#include "Device.hpp"
#include "Source.hpp"
#include "Buffer.hpp"

namespace Audioxx {

  class Player final {

    public:
      explicit Player(const std::string& filename)
        try : device(), source(), buffer(filename) {

      } catch(const std::runtime_error&) {
        // XXX: simply rethrow for now, in order to preserve error details
        throw;
      }

      void play() {
        source.play(buffer);
      }

    private:
      Device device;
      Source source;
      Buffer buffer;
  };

}
