#pragma once

#include <AL/alure.h>

namespace Audioxx {

  /**
   * Manages the link between a source and a buffer.
   */
  class Link final {

    public:
      Link(ALuint source, ALuint buffer)
        : source(source), buffer(buffer) {

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
