#ifndef COURSE_H
#define COURSE_H

#include "forward-list.h"

typedef struct{
    char name[50];
    char id[10];
    char professor[50];
    ForwardList *enrollments;
    ForwardList *requisites;
} Course;

Course * course_construct(char *name, char *id, char* professor);
void course_destroy(Course *c);

#endif