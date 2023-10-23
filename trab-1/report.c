#include "report.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void full_requirements(ForwardList * courses){
    Course * course;
    int course_idx;
    char id[10];

    scanf("%*c");
    scanf("%[^\n]", id);

    course_idx = forward_list_find(courses, id, course_eq_id);
    course = forward_list_get(courses, course_idx);

    Node * node_it, * next;
    Course * aux;

    node_it = course->requisites->head;

    while(node_it != NULL){
        next = node_it->next;
        aux = node_it->value;

        course_print_name(node_it->value);

        if(aux->requisites->size > 0){
            forward_list_print(aux->requisites, course_print_name);
        }
        node_it = next;
    }
}

//disciplinas matriculadas pelo aluno
void enrolled_courses(ForwardList * courses){
    char student_id[10];

    scanf("%*c");
    scanf("%[^\n]", student_id);

    Node * node_it_c, * node_it_e, * next_c, *next_e;
    Course * aux_c;
    Enrollment * aux_e;

    node_it_c = courses->head;
    
    while(node_it_c != NULL){
        next_c = node_it_c->next;
        aux_c = node_it_c->value;
        node_it_e = aux_c->enrollments->head;

        while(node_it_e != NULL){
            next_e = node_it_e->next;
            aux_e = node_it_e->value;
            if(!strcmp(aux_e->student->id, student_id)){
                course_print_name(aux_c);
                break;
            }
            node_it_e = next_e;
        }

        node_it_c = next_c;
    }
}

//aprovações por aluno
void approvals_per_student(ForwardList * courses){
    char student_id[10];

    scanf("%*c");
    scanf("%[^\n]", student_id);

    ForwardList * auxiliar = forward_list_construct();

    Node * node_it_c, * node_it_e, * next_c, *next_e;
    Course * aux_c;
    Enrollment * aux_e;

    node_it_c = courses->head;
    
    while(node_it_c != NULL){
        next_c = node_it_c->next;
        aux_c = node_it_c->value;
        node_it_e = aux_c->enrollments->head;

        while(node_it_e != NULL){
            next_e = node_it_e->next;
            aux_e = node_it_e->value;
            if(!strcmp(aux_e->student->id, student_id) && (aux_e->approved == 1 || (aux_e->score >= 5 && aux_e->attendance_percent >= 0.75))){
                forward_list_push_front(auxiliar, aux_c);
                break;
            }
            node_it_e = next_e;
        }

        node_it_c = next_c;
    }

    forward_list_sort(auxiliar, course_cmp_name);
    forward_list_print(auxiliar, course_print_name);
    forward_list_clear(auxiliar);
    free(auxiliar);
}

//status inconsistente 
void inconsistent_enrollment(ForwardList * enrollments){
    Node * node_it, * next;
    Enrollment * aux_e;

    node_it = enrollments->head;

    while(node_it != NULL){
        next = node_it->next;
        aux_e = node_it->value;

        if(aux_e->approved == 0 && (aux_e->score >= 5 && aux_e->attendance_percent >= 0.75)){
            enrollment_print(aux_e);
        }

        node_it = next;
    }
}