#pragma once

#include <string>
#include <stdexcept>

#include <AL/alure.h>

#include "Device.hpp"
#include "Source.hpp"

namespace Audioxx {

  class Player final {

    public:
      explicit Player()
        try : device(), source() {

      } catch(const std::runtime_error&) {
        // XXX: simply rethrow for now, in order to preserve error details
        throw;
      }

      void play(const std::string& filename) {
        source.play(filename);
      }

      void stream(const std::string& filename) {
        source.stream(filename);
      }


    private:
      Device device;
      Source source;

  };

}
