#include "Student.h"
#include "Human.h"
#include "stdint.h"
#include "string.h"

/* Your code here to define the struct */

void *new_Student(char *string)
{
    Student *student = (Student*)malloc(sizeof(Student));
    if (!student)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(0);
    }

    student->impl = (GenericTraits*)malloc(sizeof(GenericTraits));
    if (!student->impl)
    {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(0);
    }

    student->impl->new = new_Student;
    student->impl->dump = dump_Student;
    student->impl->cmp = cmp_Student;
    student->impl->drop = drop_Student;

    // string's copy is for proper naming of `human`
    char *string_cpy = (char*)malloc(sizeof(char) * strlen(string) + 1);
    strcpy(string_cpy, string);
    student->human = new_Human(string_cpy);
    free(string_cpy);

    char *context = NULL;
    char *token = strtok_r(string, " ", &context);
    token = strtok_r(NULL, " ", &context);
    if (!token)
    {
        fprintf(stderr, "Error: improperly provided grade.\n");
        exit(0);
    }

    student->grade = atoi(token);

    return student;
}

void dump_Student(void *self, FILE *fp)
{
    fprintf(fp, "%s %d\n", (((Student*)self)->human)->name, ((Student*)self)->grade);
}

int cmp_Student(void *self, void *other)
{
    return cmp_Human(((Student*)self)->human, ((Student*)other)->human);
}

void drop_Student(void *self)
{
    if (self)
    {
        drop_Human(((Student*)self)->human);
        free(self);
    }
}

void __attribute__((constructor)) register_Student()
{
    add_ctor_dtor("Student", new_Student, drop_Student);
}
