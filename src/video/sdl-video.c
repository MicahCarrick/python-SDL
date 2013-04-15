#include <Python.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include "../python-SDL.h"
#include "window.h"

#define PY_MODULE_NAME "_sdl_video"

/* module-level methods */
static PyMethodDef window_methods[] = {
    {NULL, NULL, 0, NULL}
};

#ifdef PY3
/* module definition for Python 3 */
static struct PyModuleDef window_module = {
        PyModuleDef_HEAD_INIT,
        PY_MODULE_NAME,
        "SDL video module",
        -1,
        window_methods
};
#endif

/* 
Python 2 and 3 differ in how extension modules are initialized. 
See: http://docs.python.org/3/howto/cporting.html 
*/
#ifdef PY3
PyObject *
PyInit__sdl_video(void)
#else
PyMODINIT_FUNC
init_sdl_video(void)
#endif
{
    /* create the module */
#ifdef PY3
    PyObject *module = PyModule_Create(&window_module);
    if (module == NULL) return NULL;
#else
    PyObject *module = Py_InitModule(PY_MODULE_NAME, window_methods);
    if (module == NULL) return;
#endif

    /* add types */
    add_window_type_to_module(module);
    
    /* add constants */
    PY_MODULE_ADD_LONG(module, "WINDOW_POS_CENTERED", SDL_WINDOWPOS_CENTERED);
    PY_MODULE_ADD_LONG(module, "WINDOW_POS_UNDEFINED", SDL_WINDOWPOS_UNDEFINED);
    
    PY_MODULE_ADD_LONG(module, "WINDOW_FULLSCREEN", SDL_WINDOW_FULLSCREEN);
    PY_MODULE_ADD_LONG(module, "WINDOW_OPENGL", SDL_WINDOW_OPENGL);
    PY_MODULE_ADD_LONG(module, "WINDOW_SHOWN", SDL_WINDOW_SHOWN);
    PY_MODULE_ADD_LONG(module, "WINDOW_HIDDEN", SDL_WINDOW_HIDDEN);
    PY_MODULE_ADD_LONG(module, "WINDOW_BORDERLESS", SDL_WINDOW_BORDERLESS);
    PY_MODULE_ADD_LONG(module, "WINDOW_RESIZABLE", SDL_WINDOW_RESIZABLE);
    PY_MODULE_ADD_LONG(module, "WINDOW_MINIMIZED", SDL_WINDOW_MINIMIZED);
    PY_MODULE_ADD_LONG(module, "WINDOW_MAXIMIZED", SDL_WINDOW_MAXIMIZED);
    PY_MODULE_ADD_LONG(module, "WINDOW_INPUT_GRABBED", 
                       SDL_WINDOW_INPUT_GRABBED);
    PY_MODULE_ADD_LONG(module, "WINDOW_INPUT_FOCUS", SDL_WINDOW_INPUT_FOCUS);
    PY_MODULE_ADD_LONG(module, "WINDOW_MOUSE_FOCUS", SDL_WINDOW_MOUSE_FOCUS);
    PY_MODULE_ADD_LONG(module, "WINDOW_MOUSE_FOCUS", SDL_WINDOW_MOUSE_FOCUS);
    PY_MODULE_ADD_LONG(module, "WINDOW_FULLSCREEN_DESKTOP", 
                       SDL_WINDOW_FULLSCREEN_DESKTOP);
    PY_MODULE_ADD_LONG(module, "WINDOW_FOREIGN", SDL_WINDOW_FOREIGN);

#ifdef PY3
    return module;
#endif    
}
