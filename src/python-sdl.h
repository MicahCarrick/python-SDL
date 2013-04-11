#if PY_MAJOR_VERSION >= 3
#define PY3
#endif

#define PY_MODULE_CONSTANT(module, name, constant) \
    do { \
        PyObject *object = PyLong_FromLong(constant); \
        PyModule_AddObject(module, name, object); \
    } while(0)
