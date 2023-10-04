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

Student * student_read(){
    char name[50], id[10], email[50];

    scanf("%*c");
    scanf("%[^;];", name);
    scanf("%[^;];", id);
    scanf("%[^\n]", email);

    Student * s = student_construct(name, id, email);

    return s;
}

int student_eq_id(void *id, data_type student){
    char * id_2 = id;
    Student *s = student;

    return !strcmp(id_2, s->id); 
}

void student_destroy(void * student){
    Student * s = student;
    free(s);
}