#include <Python.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include "sdl.h"

PyObject *PythonSDL_Error;
PyObject *PythonSDL_InitError;

/* SDL_Init() */
static PyObject*
sdl_init(PyObject *self, PyObject *args)
{
    Uint32 flags;
    int r;
    
    if (!PyArg_ParseTuple(args, "I", &flags)) return NULL;

    r = SDL_Init(flags);
    
    if (r != 0) {
        PyErr_SetString(PythonSDL_InitError, SDL_GetError());
        return NULL;
    }
    
    return Py_BuildValue("i", r);
}

/* SDL_InitSubSystem() */
static PyObject*
sdl_init_subsystem(PyObject *self, PyObject *args)
{
    Uint32 flags;
    int r;
    
    if (!PyArg_ParseTuple(args, "I", &flags)) return NULL;

    r = SDL_InitSubSystem(flags);
    
    if (r != 0) {
        PyErr_SetString(PythonSDL_InitError, SDL_GetError());
        return NULL;
    }
    
    return Py_BuildValue("i", r);
}

/* SDL_WasInit() */
static PyObject*
sdl_was_init(PyObject *self, PyObject *args)
{
    Uint32 flags;
    int r;
    
    if (!PyArg_ParseTuple(args, "I", &flags)) return NULL;

    r = SDL_WasInit(flags);

    return Py_BuildValue("i", r);
}

/* SDL_Quit() */
static PyObject*
sdl_quit(PyObject *self, PyObject *args)
{
    SDL_Quit();
    Py_RETURN_NONE;
}

/* Method table definition */
static PyMethodDef sdl_methods[] = {
    {"init", sdl_init, METH_VARARGS, 
        "Initialize the SDL library."},
    {"init_subsystem", sdl_init_subsystem, METH_VARARGS, 
        "Initialize specific SDL subsystems."},
    {"was_init", sdl_was_init, METH_VARARGS, 
        "Return a mask of the specified subsystems which have previously been" \
        " initialized."},
    {"quit", sdl_quit, METH_VARARGS, 
        "Clean up initialized subsystems."},
    {NULL, NULL, 0, NULL}
};

#ifdef PY3
/* Module definition for PyModule_Create() */
static struct PyModuleDef sdl_module = {
        PyModuleDef_HEAD_INIT,
        "_sdl",
        "Python implementation of the SDL 2.0 API.",
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
PyInit__sdl(void)
#else
PyMODINIT_FUNC
init_sdl(void)
#endif
{
#ifdef PY3
    PyObject *module = PyModule_Create(&sdl_module);
    if (module == NULL) return NULL;
#else
    PyObject *module = Py_InitModule("sdl", sdl_methods);
    if (module == NULL) return;
#endif

    /* define exceptions */
    PythonSDL_Error = PyErr_NewException("sdl.Error", PyExc_Exception, NULL);
    PythonSDL_InitError = PyErr_NewException("sdl.InitError", PyExc_Exception, NULL);
    
    /* add the constants defined in SDL.h */
    PY_MODULE_ADD_LONG(module, "INIT_TIMER", SDL_INIT_TIMER);
    PY_MODULE_ADD_LONG(module, "INIT_AUDIO", SDL_INIT_AUDIO);
    PY_MODULE_ADD_LONG(module, "INIT_VIDEO", SDL_INIT_VIDEO);
    PY_MODULE_ADD_LONG(module, "INIT_JOYSTICK", SDL_INIT_JOYSTICK);
    PY_MODULE_ADD_LONG(module, "INIT_HAPTIC", SDL_INIT_HAPTIC);
    PY_MODULE_ADD_LONG(module, "INIT_GAMECONTROLLER", SDL_INIT_GAMECONTROLLER);
    PY_MODULE_ADD_LONG(module, "INIT_NOPARACHUTE", SDL_INIT_NOPARACHUTE);
    PY_MODULE_ADD_LONG(module, "INIT_EVERYTHING", SDL_INIT_EVERYTHING);
    
    /* add version information */
    SDL_version compiled;
    SDL_version linked;
    PyObject *version;
    
    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);
    
    version = Py_BuildValue("iii", compiled.major, compiled.minor, 
                            compiled.patch);
    PyModule_AddObject(module, "COMPILED_VERSION", version);
    
    version = Py_BuildValue("iii", compiled.major, compiled.minor, 
                            compiled.patch);
    PyModule_AddObject(module, "LINKED_VERSION", version);
    
    version = Py_BuildValue("iii", PYTHON_SDL_MAJOR, PYTHON_SDL_MINOR, 
                            PYTHON_SDL_REVISION);
    PyModule_AddObject(module, "PYTHON_SDL_VERSION", version);
    
#ifdef PY3
    return module;
#endif    
}
