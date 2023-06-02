
#include "GenericTraits.h"
#include <string.h>

#define MAX_TYPES 256
static char *type_names[MAX_TYPES];
static void *(*constructors[MAX_TYPES])(char *);
static void (*destructors[MAX_TYPES])(void *);
static int num_types = 0;

Constructor get_constructor(char *type_name) {
    /* Your code here to get the constructor of the struct' */
    // find where name is in `type_names`
    int i = 0;
    while(1)
    {
        // Error check
        if (i >= num_types) return 0;

        if (!strcmp(type_names[i], type_name))
        {
            // we have our element position
            break;
        }

        i++;
    }

    return constructors[i];
}

Destructor get_destructor(char *type_name) {
    /* Your code here to get the destructor of the struct' */
    // find where name is in `type_names`
    int i = 0;
    while(1)
    {
        // Error check
        if (i >= num_types) return 0;

        if (!strcmp(type_names[i], type_name))
        {
            // we have our element position
            break;
        }

        i++;
    }

    return destructors[i];
}

void add_ctor_dtor(char *type_name, Constructor ctor, Destructor dtor) {
    /* Your code here to register the struct */
    // register type by name
    type_names[num_types] = type_name;

    // register constructor
    constructors[num_types] = ctor;

    // register destructor
    destructors[num_types] = dtor;

    num_types++;
}
