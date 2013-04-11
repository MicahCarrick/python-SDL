#!/usr/bin/env python
from distutils.core import setup, Extension

sdl = Extension(
    'sdl', 
    sources = ['src/sdl.c'],
    include_dirs = ['/usr/local/include'],
    libraries = ['SDL2'],
    library_dirs = ['/usr/local/lib'],
)

setup(
    name = "python-SDL", 
    version = "0.1",
    description = "Python bindings for SDL 2.0",
    author = "Micah Carrick",
    author_email = "micah@quixotix.com",
    ext_modules = [sdl]
)
