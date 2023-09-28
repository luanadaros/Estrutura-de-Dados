#include "student.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Student * student_construct(char* name, char* id, char* email){
    Student *s = (Student*)malloc(sizeof(Student));
    strcpy(s->name, name);
    strcpy(s->id, id);
    strcpy(s->email, email);

    return s;
}

int student_eq_id(void *id, data_type student){
    char *id = id;
    Student *s = student;

    return !strcmp(id, s->id); 
}

void student_destroy(Student * s){
    free(s);
}