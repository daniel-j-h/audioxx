#pragma once

#include <cassert>
#include <AL/alure.h>

namespace Audioxx {

  /**
   * Manages the link between a source and a buffer.
   */
  class Link final {

    public:
      Link(ALuint source, ALuint buffer)
        : source(source), buffer(buffer) {

        assert(source != 0 && "Error: Source not valid");
        assert(buffer != 0 && "Error: Buffer not valid");

        alSourcei(source, AL_BUFFER, buffer);
      }

      ~Link() {
        alSourcei(source, AL_BUFFER, 0);
      }


    private:
      const ALuint source;
      const ALuint buffer;

  };

}
