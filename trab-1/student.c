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

void student_print_name(data_type student){
    Student * s = student;

    printf("%s\n", s->name);
}

int student_cmp_name(data_type student1, data_type student2){
    Student * s1 = student1;
    Student * s2 = student2;

    return strcmp(s1->name, s2->name);
}