SDL 2.0 for Python
==================

Installing SDL 2.0
------------------

Use `Mercurial <http://mercurial.selenic.com/>`_ to clone the repository::

    hg clone hg clone http://hg.libsdl.org/SDL

Create a ``build`` directory from which build SDL::

    cd SDL
    mkdir build
    cd build

Run the standard build process::

    ../configure
    make
    sudo make install
