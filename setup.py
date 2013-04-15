#!/usr/bin/env python
from distutils.core import setup, Extension

extensions = [
    Extension(
        '_sdl', 
        sources = ['src/sdl.c'],
        include_dirs = ['/usr/local/include'],
        libraries = ['SDL2'],
        library_dirs = ['/usr/local/lib'],
    ),
    Extension(
        '_sdl_video', 
        sources = ['src/video/window.c', 'src/video/sdl-video.c'],
        include_dirs = ['/usr/local/include'],
        libraries = ['SDL2'],
        library_dirs = ['/usr/local/lib'],
    )
]

setup(
    name = "python-SDL", 
    version = "0.1",
    description = "Python bindings for SDL 2.0",
    author = "Micah Carrick",
    author_email = "micah@quixotix.com",
    packages = ['sdl', 'sdl.video'],
    ext_modules = extensions
)
