#include "course.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Course * course_construct(char *name, char *id, char* professor){
    Course *c = (Course*)malloc(sizeof(Course));
    strcpy(c->name, name);
    strcpy(c->id, id);
    strcpy(c->professor, professor);
    c->enrollments = forward_list_construct();
    c->requisites = forward_list_construct();

    return c;
}

void course_destroy(Course *c){
    free(c);
}