Adventures in the land of audio handling
========================================

Libraries
---------

* [OpenAL](http://kcat.strangesoft.net/openal.html)
* [ALURE](http://kcat.strangesoft.net/alure.html)


Documentation
-------------

* [OpenAL Programmer's Guide](http://connect.creativelabs.com/openal/Documentation/OpenAL_Programmers_Guide.pdf)
* [OpenAL Specification and Reference](http://connect.creativelabs.com/openal/Documentation/OpenAL%201.1%20Specification.pdf)


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
