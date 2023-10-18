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
    forward_list_clear(c->requisites);
    free(c->requisites);
    forward_list_clear(c->enrollments);
    free(c->enrollments);
    free(c);
}

void course_add_enrollments(ForwardList * courses, ForwardList * enrollments){
    Course * course;
    Node * node_it_e = enrollments->head, * node_it_c = courses->head;
    Node * next_e, * next_c;
    Enrollment * aux;

    while(node_it_c != NULL){
        next_c = node_it_c->next;
        course = node_it_c->value;
        node_it_e = enrollments->head;

        while(node_it_e != NULL){
            next_e = node_it_e->next;
            aux = node_it_e->value;
            if(course_eq_id(aux->course_id, course)){
                forward_list_push_front(course->enrollments, aux);
            }

            node_it_e = next_e;
        }
        node_it_c = next_c;
    }
}

void course_print_name(data_type course){
    Course * c = course;

    printf("%s\n", c->name);
}