#include <Python.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include "python-sdl.h"

/* SDL_Init() */
static PyObject *
sdl_init(PyObject *self, PyObject *args)
{
    Uint32 flags;
    int r;
    
    if (!PyArg_ParseTuple(args, "I", &flags)) 
    {
        return NULL;
    }

    /* TODO: raise exception with SDL_GetError() ? */
    r = SDL_Init(flags);
    
    return Py_BuildValue("i", r);
}

/* SDL_Quit() */
static PyObject *
sdl_quit(PyObject *self, PyObject *args)
{
    SDL_Quit();
    Py_RETURN_NONE;
}

/* Method table definition */
static PyMethodDef sdl_methods[] = {
    {"init", sdl_init, METH_VARARGS, "Initialize the SDL library."},
    {"quit", sdl_quit, METH_VARARGS, "Clean up initialized subsystems."},
    {NULL, NULL, 0, NULL}
};

#ifdef PY3
/* Module definition for PyModule_Create() */
static struct PyModuleDef sdl_module = {
        PyModuleDef_HEAD_INIT,
        "sdl",
        NULL,
        -1,
        sdl_methods
};
#endif

/* 
Python 2 and 3 differ in how extension modules are initialized. 
See: http://docs.python.org/3/howto/cporting.html 
*/
#ifdef PY3
PyObject *
PyInit_sdl(void)
#else
PyMODINIT_FUNC
initsdl(void)
#endif
{
#ifdef PY3
    PyObject *module = PyModule_Create(&sdl_module);
#else
    PyObject *module = Py_InitModule("sdl", sdl_methods);
#endif
    /* Add the constants defined in SDL.h to the Python module. */
    /* init flags */
    PY_MODULE_CONSTANT(module, "INIT_TIMER", SDL_INIT_TIMER);
    PY_MODULE_CONSTANT(module, "INIT_AUDIO", SDL_INIT_AUDIO);
    PY_MODULE_CONSTANT(module, "INIT_VIDEO", SDL_INIT_VIDEO);
    PY_MODULE_CONSTANT(module, "INIT_JOYSTICK", SDL_INIT_JOYSTICK);
    PY_MODULE_CONSTANT(module, "INIT_HAPTIC", SDL_INIT_HAPTIC);
    PY_MODULE_CONSTANT(module, "INIT_GAMECONTROLLER", SDL_INIT_GAMECONTROLLER);
    PY_MODULE_CONSTANT(module, "INIT_NOPARACHUTE", SDL_INIT_NOPARACHUTE);
    PY_MODULE_CONSTANT(module, "INIT_EVERYTHING", SDL_INIT_EVERYTHING);
 
#ifdef PY3
    return module;
#endif    
}
