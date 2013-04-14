#include <Python.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include "sdl.h"

typedef struct {
    PyObject_HEAD
    
} Window;

static PyTypeObject WindowType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "Window",                   /* tp_name */
    sizeof(Window),             /* tp_basicsize */
    0,                          /* tp_itemsize */
    0,                          /* tp_dealloc */
    0,                          /* tp_print */
    0,                          /* tp_getattr */
    0,                          /* tp_setattr */
    0,                          /* tp_reserved */
    0,                          /* tp_repr */
    0,                          /* tp_as_number */
    0,                          /* tp_as_sequence */
    0,                          /* tp_as_mapping */
    0,                          /* tp_hash  */
    0,                          /* tp_call */
    0,                          /* tp_str */
    0,                          /* tp_getattro */
    0,                          /* tp_setattro */
    0,                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,         /* tp_flags */
    "An SDL window",            /* tp_doc */
};


/* Method table definition */
static PyMethodDef window_methods[] = {
    {NULL, NULL, 0, NULL}
};

#ifdef PY3
/* Module definition for PyModule_Create() */
static struct PyModuleDef window_module = {
        PyModuleDef_HEAD_INIT,
        "_sdl_window",
        "Create and maniuplate SDL windows.",
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
PyInit__sdl_window(void)
#else
PyMODINIT_FUNC
init_sdl_window(void)
#endif
{
    /* create the Window type */
    WindowType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&WindowType) < 0)
        return NULL;
    
    /* create the module */
#ifdef PY3
    PyObject *module = PyModule_Create(&window_module);
    if (module == NULL) return NULL;
#else
    PyObject *module = Py_InitModule("_sdl_window", window_methods);
    if (module == NULL) return;
#endif

    /* add the Window type to the module */
    Py_INCREF(&WindowType);
    PyModule_AddObject(module, "Window", (PyObject *)&WindowType);
    
    /* add the constants defined in SDL_video.h */
    PY_MODULE_ADD_LONG(module, "POS_CENTERED", SDL_WINDOWPOS_CENTERED);
    PY_MODULE_ADD_LONG(module, "POS_UNDEFINED", SDL_WINDOWPOS_UNDEFINED);

#ifdef PY3
    return module;
#endif    
}
