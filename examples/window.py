import sys
import time
import sdl
from sdl import video

if __name__ == "__main__":
    sdl.init(sdl.INIT_VIDEO)

    #window = sdl.window.Window("Hello World!", 
    #                           sdl.window.POS_UNDEFINED, 
    #                           sdl.window.POS_UNDEFINED, 
    #                           800, 600, 
    #                           sdl.window.SHOWN | sdl.window.OPENGL)
    window = video.Window()
    print(window)
    #time.sleep(5000)

    # clean-up
    # window.destroy()
    sdl.quit()
