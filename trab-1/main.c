
#include <stdio.h>

#include "forward-list.h"
#include "student.h"
#include "course.h"
#include "enrollment.h"
#include "report.h"

int main(){
    int n, i;

    ForwardList * students = forward_list_construct();
    ForwardList * courses = forward_list_construct();
    ForwardList * enrollments = forward_list_construct();

    Student * aux_s;
    Course * aux_c;
    Enrollment * aux_e;

    scanf("%d", &n); //numero de alunos

    for(i = 0; i < n; i++){
        aux_s = student_read();
        forward_list_push_front(students, aux_s);
    }

    scanf("%d", &n); //numero de disciplinas

    for(i = 0; i < n; i++){
        aux_c = course_read();
        forward_list_push_front(courses, aux_c);
    }

    scanf("%d", &n); //numero de pre-requisitos

    for(i = 0; i < n; i++){
        course_read_and_add_requisite(courses);
    }

    scanf("%d", &n); //numero de matriculas

    for(i = 0; i < n; i++){
        aux_e = enrollment_read(students);
        forward_list_push_front(enrollments, aux_e);
    }

    //adiciona as matriculas em seus determinados cursos
    course_add_enrollments(courses, enrollments);

    int option;


    scanf("%d", &option);

    if(option == 1){
        enrolled_students(courses);
    }
    else if(option == 2){
        direct_requirements(courses);
    }
    else if(option == 3){
        full_requirements(courses);
    }
    else if(option == 4){
        enrolled_courses(courses);
    }
    else if(option == 6){
        approvals_per_student(courses);
    }
    else if(option == 7){
        inconsistent_enrollment(enrollments);
    }

    forward_list_destroy(students, student_destroy);
    forward_list_destroy(courses, course_destroy);
    forward_list_destroy(enrollments, enrollment_destroy);

    return 0;
}