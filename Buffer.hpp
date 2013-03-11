#pragma once

#include <string>
#include <stdexcept>
#include <AL/alure.h>

namespace Audioxx {

  /**
   * Manages the mapping between a file and a memory buffer.
   *
   * Note: The whole file gets mapped into memory.
   * See Stream for a memory efficient alternative.
   */
  class Buffer final {

    public:
      Buffer(const std::string& filename)
        : buffer(alureCreateBufferFromFile(filename.c_str())) {

        if(buffer == AL_NONE)
          throw std::runtime_error("Error: Unable to create buffer: " + std::string(alureGetErrorString()));
      }

      ~Buffer() {
        alDeleteBuffers(1, &buffer);
      }

      ALuint get() const noexcept {
        return buffer;
      }


    private:
      ALuint buffer;

  };

}
