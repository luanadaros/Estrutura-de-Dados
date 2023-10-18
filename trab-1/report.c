#include "report.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

//alunos matriculados na disciplina
void enrolled_students(ForwardList * courses){
    Course * course;
    int course_idx;
    char id[10];

    scanf("%*c");
    scanf("%[^\n]", id);

    course_idx = forward_list_find(courses, id, course_eq_id);
    course = forward_list_get(courses, course_idx);

    ForwardList * unique = forward_list_construct();

    Node * node_it = course->enrollments->head, * next, *node_it_2, *next_2;
    Enrollment * aux_e;
    Student * aux_s;
    int duplicate = 0;

    aux_e = node_it->value;
    aux_s = aux_e->student;
    forward_list_push_front(unique, aux_s);

    while(node_it != NULL){
        next = node_it->next;
        aux_e = node_it->value;
        aux_s = aux_e->student;
        node_it_2 = unique->head;

        while(node_it_2 != NULL){
            next_2 = node_it_2->next;
            if(student_eq_id(aux_s->id, node_it_2->value)){
                duplicate = 1;
            }
            node_it_2 = next_2;
        }
        
        if(!duplicate){
            forward_list_push_front(unique, aux_s);
        }

        node_it = next;
        duplicate = 0;
    }

    forward_list_print(unique, student_print_name);
    forward_list_clear(unique);
    free(unique);
}

//pre requisitos diretos 
void direct_requirements(ForwardList * courses){
    Course * course;
    int course_idx;
    char id[10];

    scanf("%*c");
    scanf("%[^\n]", id);

    course_idx = forward_list_find(courses, id, course_eq_id);
    course = forward_list_get(courses, course_idx);

    forward_list_print(course->requisites, course_print_name);
}

//pre requisitos indiretos
void full_requirements(ForwardList * courses);

//disciplinas matriculadas pelo aluno
void enrolled_courses(ForwardList * enrollments){
    char student_id[10];

    scanf("%*c");
    scanf("%[^\n]", student_id);

    ForwardList * unique = forward_list_construct();


    forward_list_clear(unique);
    free(unique);
}
