#pragma once

#include <cstddef>
#include <string>
#include <stdexcept>
#include <AL/alure.h>

namespace Audioxx {

  /**
   * Manages the streaming of a file.
   *
   * Note: This is similar to a Buffer, but instead of mapping the whole file into memory,
   * we load it chunk by chunk into buffers while switching the active one.
   */
  class Stream final {

    public:
      Stream(const std::string& filename, std::size_t chunklength = 250000) {
        // XXX: opt. use bytes instead of microseconds, in order to constrain memory usage
        alureStreamSizeIsMicroSec(AL_TRUE);
        stream = alureCreateStreamFromFile(filename.c_str(), chunklength, 0, nullptr);

        if(not stream)
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
