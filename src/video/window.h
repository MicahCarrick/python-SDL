#ifndef PYTHON_SDL_WINDOW_H
#define PYTHON_SDL_WINDOW_H
#include "Python.h"

typedef struct {
    PyObject_HEAD
} Window;

int 
add_window_type_to_module(PyObject *module);

#endif /* PYTHON_SDL_WINDOW_H */
