#pragma once

#include <string>
#include <stdexcept>

#include <AL/alure.h>

#include "Device.hpp"
#include "Source.hpp"
#include "Buffer.hpp"

namespace Audio {

  class Player final {

    public:
      explicit Player(std::string filename)
        try : device(), source(), buffer(filename), isdone(false) {

      } catch(const std::runtime_error&) {
        // XXX: pass through: catch any error from low level systems and report as single general one
        throw std::runtime_error("error: player");
      }

      void play() {
        alSourcei(source.get(), AL_BUFFER, buffer.get());

        // XXX: static wrapper required, pass pointer to modify object's isdone state
        if(alurePlaySource(source.get(), callback_wrapper, this) == AL_FALSE)
          throw std::runtime_error("error: play");

        while(not isdone)
          alureUpdateInterval(0.125);
      }

    private:
      Device device;
      Source source;
      Buffer buffer;

      volatile bool isdone;

      static void callback_wrapper(void* player, ALuint) {
        static_cast<Player*>(player)->isdone = true;
      }

  };

}
