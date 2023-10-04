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

Course * course_read(){
    char name[50], id[10], professor[50];

    scanf("%*c");
    scanf("%*c");
    scanf("%[^;];", name);
    scanf("%[^;];", id);
    scanf("%[^\n]", professor);

    Course * c = course_construct(name, id, professor);

    return c;
}

int course_eq_id(void *id, data_type course){
    char * id_2 = id;
    Course *c = course;

    return !strcmp(id_2, c->id); 
}

void course_read_and_add_requisite(ForwardList *courses){
    char course_id[10], requisite_id[10];
    int course_idx, requisite_idx;

    scanf("%*c");
    scanf("%[^;];", course_id);
    scanf("%[^\n]", requisite_id);


    course_idx = forward_list_find(courses, course_id, course_eq_id);
    requisite_idx = forward_list_find(courses, requisite_id, course_eq_id);

    Course * c = forward_list_get(courses, course_idx);
    Course * r = forward_list_get(courses, requisite_idx);

    forward_list_push_front(c->requisites, r);
}

void course_destroy(void * course){
    Course * c = course;
    free(c);
}