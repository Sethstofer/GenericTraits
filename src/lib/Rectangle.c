
#include "Rectangle.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Your code here to define the struct */

void *new_Rectangle(char *string)
{
    Rectangle *new_Rect = (Rectangle*)malloc(sizeof(Rectangle));
    if (!new_Rect)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(0);
    }

    new_Rect->impl = (GenericTraits*)malloc(sizeof(GenericTraits));
    if (!new_Rect->impl)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(0);
    }

    new_Rect->impl->new = new_Rectangle;
    new_Rect->impl->dump = dump_Rectangle;
    new_Rect->impl->cmp = cmp_Rectangle;
    new_Rect->impl->drop = drop_Rectangle;

    char *context = NULL;
    char *token = strtok_r(string, " ", &context);
    if (!token)
    {
        fprintf(stderr, "Error: improperly provided Rectangle height and width.\n");
        exit(0);
    }

    new_Rect->height = strtoull(token, NULL, 10);

    token = strtok_r(NULL, " ", &context);
    if (!token)
    {
        fprintf(stderr, "Error: improperly provided Rectangle height and width.\n");
        exit(0);
    }

    new_Rect->width = strtoull(token, NULL, 10);

    return new_Rect;
}

void dump_Rectangle(void *self, FILE *fp)
{
    fprintf(fp, "%zu %zu\n", ((Rectangle*)self)->height, ((Rectangle*)self)->width);
}

int cmp_Rectangle(void *self, void *other)
{
    size_t areaSelf = ((Rectangle*)self)->height * ((Rectangle*)self)->width;
    size_t areaOther = ((Rectangle*)other)->height * ((Rectangle*)other)->width;

    // self is less than other
    if (areaSelf < areaOther)
    {
        return -1;
    }
    // self is greater than other
    else if (areaSelf > areaOther)
    {
        return 1;
    }
    // self is equal to other
    else
    {
        // determine position by height if equal area
        if (((Rectangle*)self)->height < ((Rectangle*)other)->height)
        {
            return -1;
        }
        else if (((Rectangle*)self)->height > ((Rectangle*)other)->height)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

DEFINE_STRUCT(Rectangle)
