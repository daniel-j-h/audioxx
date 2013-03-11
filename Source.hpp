#pragma once

#include <cstddef>
#include <cassert>
#include <string>
#include <stdexcept>
#include <AL/alure.h>

#include "Buffer.hpp"
#include "Stream.hpp"
#include "Link.hpp"

namespace Audioxx {

  /**
   * Manages a source, on which various audio functions are invoked.
   */
  class Source final {

    public:
      Source() : isdone(false) {
        alGenSources(1, &source);

        if(alGetError() != AL_NO_ERROR)
          throw std::runtime_error("Error: Unable to create source: " + std::string(alureGetErrorString()));
      }

      ~Source() {
        alureStopSource(source, AL_FALSE);
        alDeleteSources(1, &source);
      }

      ALuint get() const noexcept {
        return source;
      }


      void play(const std::string& filename) {
        Buffer buffer(filename);

        // XXX: link source to buffer in RAII exception-safe manner, in order to make sure it get's unlinked
        Link link(this->get(), buffer.get());

        if(alurePlaySource(source, callback_wrapper, this) == AL_FALSE)
          throw std::runtime_error("Error: Unable to play buffer: " + std::string(alureGetErrorString()));

        eventloop();
      }


      void stream(const std::string& filename, std::size_t numbuffers = 5) {
        // XXX: at least one active, one filling
        assert(numbuffers > 2);

        Stream stream(filename);

        if(alurePlaySourceStream(source, stream.get(), numbuffers, 0, callback_wrapper, this) == AL_FALSE)
          throw std::runtime_error("Error: Unable to play stream: " + std::string(alureGetErrorString()));

        eventloop();
      }


    private:
      ALuint source;

      volatile bool isdone;

      // XXX: static callback wrapper required, pass pointer as userdata to modify object's isdone state
      static void callback_wrapper(void* source, ALuint) noexcept {
        static_cast<Source*>(source)->isdone = true;
      }

      void eventloop(const float interval = 0.125f) const noexcept {
        while(not isdone) {
          alureSleep(interval);
          alureUpdate();
        }
      }

  };

}
