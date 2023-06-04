#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GenericTraits.h"

/// Use `DECLARE_STRUCT` to declare the struct in less than 5 lines.
/* Your code here to declare the struct */

DECLARE_STRUCT(Rectangle,
{   GenericTraits *impl;
    size_t height;
    size_t width; })

#endif
