#pragma once

#include <string>
#include <stdexcept>
#include <AL/alure.h>

namespace Audioxx {

  class Buffer final {
    public:
      Buffer(const std::string& filename)
        : buffer(alureCreateBufferFromFile(filename.c_str())) {

        if(not buffer)
          throw std::runtime_error("error: unable to create buffer");
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
