#define TYPE int
#define TYPE2 int
#include "dyn_func.h"
#undef TYPE
#undef TYPE2

#define TYPE float
#define TYPE2 float
#include "dyn_func.h"
#undef TYPE
#undef TYPE2

#define TYPE char*
#define TYPE2 str
#include "dyn_func.h"
#undef TYPE
#undef TYPE2