SDL 2.0 for Python
==================

Python bindings for SDL 2.0.

Installing SDL 2.0
------------------

Clone the mercurial repository::

    hg clone hg clone http://hg.libsdl.org/SDL

Create a ``build`` directory from which build SDL::

    cd SDL
    mkdir build
    cd build

Run the standard build process::

    ../configure
    make
    sudo make install


Installing python-SDL
---------------------

Clone the git repository::
    
    git clone https://github.com/MicahCarrick/python-SDL.git

Run the Python setup script (as root)::

    cd python-SDL
    python setup.py install
    
