import sys
import time
import sdl
from sdl import video

print("SDL version (compiled): " + ".".join([str(val) for val in sdl.COMPILED_VERSION]))
print("SDL version (linked): " + ".".join([str(val) for val in sdl.LINKED_VERSION]))
print("python-SDL version: " + ".".join([str(val) for val in sdl.PYTHON_SDL_VERSION]))

if __name__ == "__main__":
    sdl.init(sdl.INIT_VIDEO)

    #window = video.Window("Hello World!", 
    #                      sdl.video.WINDOW_POS_UNDEFINED, 
    #                      sdl.video.WINDOW_POS_UNDEFINED, 
    #                      800, 600, 
    #                      sdl.video.WINDOW_SHOWN | sdl.video.WINDOW_OPENGL)
    window = video.Window("Hello World!")
    print(window)
    #time.sleep(5000)
    
    # clean-up
    # window.destroy()
    sdl.quit()
