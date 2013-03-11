Adventures in the land of audio handling
========================================


Documentation
-------------

* [OpenAL](http://kcat.strangesoft.net/openal.html)
* [ALURE](http://kcat.strangesoft.net/alure.html)


Building
--------

Opt. adapt the Makefile to your needs; export DEBUG=1 for a debug build.

    make
    ./audioxx -play data/tick.ogg
    ./audioxx -stream data/tick.ogg


Todo
----

* Stream properties handling (chunk size, bytes)
* Explore OpenAL API, ALURE API
