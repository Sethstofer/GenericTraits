#include "Int.h"
#include <stdint.h>

/* Your code here to define the struct */

void *new_Int(char *string)
{
    int integer = atoi(string);

    Int *new_Integer = (Int*)malloc(sizeof(Int));
    if (!new_Integer)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(0);
    }

    new_Integer->impl = (GenericTraits*)malloc(sizeof(GenericTraits));
    new_Integer->impl->new = new_Int;
    new_Integer->impl->dump = dump_Int;
    new_Integer->impl->cmp = cmp_Int;
    new_Integer->impl->drop = drop_Int;

    new_Integer->i = integer;

    return new_Integer;
}

void dump_Int(void *self, FILE *fp)
{
    fprintf(fp, "0x%x\n", ((Int*)self)->i);
}

int cmp_Int(void *self, void *other)
{
    // self is less than other
    if (((Int*)self)->i < ((Int*)other)->i)
    {
        return -1;
    }
    // self is greater than other
    else if (((Int*)self)->i > ((Int*)other)->i)
    {
        return 1;
    }
    // self is equal to other
    else
    {
        return 0;
    }
}

void drop_Int(void *self)
{
    if (self)
    {
        free(((Int*)self)->impl);
        free(self);
    }
}

void __attribute__((constructor)) register_Int()
{
    add_ctor_dtor("Int", new_Int, drop_Int);
}
