#pragma once

#include <stdexcept>
#include <AL/alure.h>

namespace Audio {

  // XXX: for now creates only one source; for more we have to save an array
  class Source final {
    public:
      Source() {
        alGenSources(1, &source);

        if(alGetError() != AL_NO_ERROR)
          throw std::runtime_error("error: sources");
      }

      ~Source() {
        alDeleteSources(1, &source);
      }

      ALuint get() {
        return source;
      }

    private:
      ALuint source;
  };

}
