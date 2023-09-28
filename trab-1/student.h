#ifndef STUDENT_H
#define STUDENT_H

#include "forward-list.h"

typedef struct {
    char name[50];
    char id[10];
    char email[50];
} Student;

Student * student_construct(char* name, char* id, char* email);
void student_destroy(Student * s);

#endif