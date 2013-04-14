from __future__ import print_function
import sdl

print("SDL version (compiled): " + ".".join([str(val) for val in sdl.COMPILED_VERSION]))
print("SDL version (linked): " + ".".join([str(val) for val in sdl.LINKED_VERSION]))
print("python-SDL version: " + ".".join([str(val) for val in sdl.PYTHON_SDL_VERSION]))

print("init(0)")
print(sdl.init(0))

print("init_subsystem(sdl.INIT_VIDEO)")
print(sdl.init_subsystem(sdl.INIT_VIDEO))

print("was_init(sdl.INIT_VIDEO)")
print(bool(sdl.was_init(sdl.INIT_VIDEO)))

print("was_init(sdl.INIT_AUDIO)")
print(bool(sdl.was_init(sdl.INIT_AUDIO)))

print("quit()")
sdl.quit()
