#ifndef PYTHON_SDL_H
#define PYTHON_SDL_H
#include "Python.h"

#if PY_MAJOR_VERSION >= 3
#define PY3
#endif

/* macros for adding constant objects to Python modules */
#define PY_MODULE_ADD_LONG(module, name, value) \
    do { \
        PyObject *object = PyLong_FromLong(value); \
        PyModule_AddObject(module, name, object); \
    } while(0)

#define PY_MODULE_ADD_STR(module, name, value) \
    do { \
        PyObject *object = PyUnicode_FromString(value); \
        PyModule_AddObject(module, name, object); \
    } while(0)

/* python-SDL exceptions defined in sdl.c */
extern PyObject* PythonSDL_Error;
extern PyObject* PythonSDL_InitError;

#endif /* PYTHON_SDL_H */
