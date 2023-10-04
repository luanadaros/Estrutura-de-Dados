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
Course * course_read();
int course_eq_id(void *id, data_type course);
void course_read_and_add_requisite(ForwardList *courses);
void course_destroy(void *course);

#endif