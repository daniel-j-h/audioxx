#pragma once

#include <cstddef>
#include <string>
#include <stdexcept>
#include <AL/alure.h>

namespace Audioxx {

  class Stream final {

    public:
      Stream(const std::string& filename, std::size_t chunklength = 250000) {
        // XXX: opt. use bytes instead of microseconds, in order to constrain memory usage
        alureStreamSizeIsMicroSec(AL_TRUE);
        stream = alureCreateStreamFromFile(filename.c_str(), chunklength, 0, nullptr);

        if(!stream)
          throw std::runtime_error("Error: Unable to create stream: " + std::string(alureGetErrorString()));
      }

      ~Stream() {
        alureDestroyStream(stream, 0, nullptr);;
      }

      alureStream* get() const noexcept {
        return stream;
      }


    private:
      alureStream* stream;

  };

}
