
#include "Human.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Your code here to define the struct */

void *new_Human(char *string)
{
    Human *human = (Human*)malloc(sizeof(Human));
    if (!human)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(0);
    }

    human->impl = (GenericTraits*)malloc(sizeof(GenericTraits));
    if (!human->impl)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(0);
    }

    human->name = (char*)malloc(sizeof(char) * strlen(string) + 1);
    if (!human->name)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(0);
    }

    human->impl->new = new_Human;
    human->impl->dump = dump_Human;
    human->impl->cmp = cmp_Human;
    human->impl->drop = drop_Human;

    // remove extra input & newline character
    int strLen = strlen(string);
    for (int i = 0; i < strLen; i++)
    {
        if ((string[i] == 32) || (i == strLen - 1))
        {
            string[i] = 0;
        }
    }

    strcpy(human->name, string);

    return human;
}

void dump_Human(void *self, FILE *fp)
{
    fprintf(fp, "%s\n", ((Human*)self)->name);
}

int cmp_Human(void *self, void *other)
{
    return strcmp(((Human*)self)->name, ((Human*)other)->name);
}

void drop_Human(void *self)
{
    if (self)
    {
        free(((Human*)self)->impl);
        free(((Human*)self)->name);
        free(self);
    }
}

void __attribute__((constructor)) register_Human()
{
    add_ctor_dtor("Human", new_Human, drop_Human);
}
