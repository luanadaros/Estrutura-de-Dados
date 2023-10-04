
#include <stdio.h>

#include "forward-list.h"
#include "student.h"
#include "course.h"
#include "enrollment.h"

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

    forward_list_destroy(students, student_destroy);
    forward_list_destroy(courses, course_destroy);
    forward_list_destroy(enrollments, enrollment_destroy);

    return 0;
}