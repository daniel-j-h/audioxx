#pragma once

#include <stdexcept>
#include <AL/alure.h>

#include "Buffer.hpp"

namespace Audioxx {

  // XXX: for now creates only one source; for more we have to save an array
  class Source final {
    public:
      Source() : isdone(false) {
        alGenSources(1, &source);

        if(alGetError() != AL_NO_ERROR)
          throw std::runtime_error("error: unable to create source");
      }

      ~Source() {
        alDeleteSources(1, &source);
      }

      ALuint get() const noexcept {
        return source;
      }

      void play(const Buffer& buffer) {
        alSourcei(source, AL_BUFFER, buffer.get());

        // XXX: static wrapper required, pass pointer to modify object's isdone state
        if(alurePlaySource(source, callback_wrapper, this) == AL_FALSE)
          throw std::runtime_error("error: unable to play source");

        while(not isdone)
          alureUpdateInterval(0.125);
      }

    private:
      ALuint source;

      volatile bool isdone;

      static void callback_wrapper(void* source, ALuint) {
        static_cast<Source*>(source)->isdone = true;
      }
  };

}
