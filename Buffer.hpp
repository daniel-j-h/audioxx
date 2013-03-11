#pragma once

#include <string>
#include <stdexcept>
#include <AL/alure.h>

namespace Audio {

  // XXX: for now creates only one buffer; for more we have to save an array
  class Buffer final {
    public:
      Buffer(const std::string& filename) {
        buffer = alureCreateBufferFromFile(filename.c_str());

        if(not buffer)
          throw std::runtime_error("error: buffer");
      }

      ~Buffer() {
        alDeleteBuffers(1, &buffer);
      }

      ALuint get() {
        return buffer;
      }

    private:
      ALuint buffer;
  };

}
