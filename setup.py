#!/usr/bin/env python
from distutils.core import setup, Extension
from glob import glob
from sdl import VERSION, get_version

INCLUDE_DIRS = ['/usr/local/include']
LIBS = ['SDL2']
LIB_DIRS = ['/usr/local/lib']

extensions = [
    Extension(
        '_sdl',
        define_macros = [('PYTHON_SDL_MAJOR', VERSION[0]),
                         ('PYTHON_SDL_MINOR', VERSION[1]),
                         ('PYTHON_SDL_REVISION', VERSION[2])],
        sources = glob("src/*.c"),
        include_dirs = INCLUDE_DIRS,
        libraries = LIBS,
        library_dirs = LIB_DIRS,
    ),
    Extension(
        '_sdl_video', 
        sources = glob("src/video/*.c"),
        include_dirs = INCLUDE_DIRS,
        libraries = LIBS,
        library_dirs = LIB_DIRS,
    )
]

setup(
    name = "python-SDL", 
    version = get_version(),
    description = "Python bindings for SDL 2.0",
    author = "Micah Carrick",
    author_email = "micah@quixotix.com",
    packages = ['sdl', 'sdl.video'],
    ext_modules = extensions
)
