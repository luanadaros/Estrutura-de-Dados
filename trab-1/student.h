#ifndef STUDENT_H
#define STUDENT_H

#include "forward-list.h"

typedef struct {
    char name[50];
    char id[10];
    char email[50];
} Student;

Student * student_construct(char* name, char* id, char* email);
Student * student_read();
int student_eq_id(void *id, data_type student);
void student_destroy(void * student);
void student_print_name(data_type student);
int student_cmp_name(data_type student1, data_type student2);

#endif