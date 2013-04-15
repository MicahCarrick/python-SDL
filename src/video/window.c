#include <Python.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "window.h"

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

int
add_window_type_to_module(PyObject *module)
{
    WindowType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&WindowType) < 0)
        return false;
    
    Py_INCREF(&WindowType);
    PyModule_AddObject(module, "Window", (PyObject *)&WindowType);
    
    return true;
}

