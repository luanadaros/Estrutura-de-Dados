#include "enrollment.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Enrollment * enrollment_construct(char* course_id, Student * student, float score, float percent, float approved){
    Enrollment *e = (Enrollment*)malloc(sizeof(Enrollment));
    strcpy(e->course_id, course_id);
    e->score = score;
    e->attendance_percent = percent;
    e->approved = approved;
    e->student = student;

    return e;
}

Enrollment * enrollment_read(ForwardList * students){
    char course_id[10], student_id[10];
    char score[7], att[7], apprv[2];

    scanf("%*c");
    scanf("%[^;];", course_id);
    scanf("%[^;];", student_id);
    scanf("%[^;];", score);
    scanf("%[^;];", att);
    scanf("%[^\n]", apprv);

    Student * s;
    int s_idx;

    float scr, attd;
    int apprvd;
    scr = atof(score);
    attd = atof(att);
    apprvd = atoi(apprv);

    s_idx = forward_list_find(students, student_id, student_eq_id);
    s = forward_list_get(students, s_idx);

    Enrollment * e = enrollment_construct(course_id, s, scr, attd, apprvd);

    return e;
}

void enrollment_destroy(void * enrollment){
    Enrollment * e = enrollment;
    free(e);
}

void enrollment_print(data_type enrollment){
    Enrollment * e = enrollment;

    printf("%s;", e->course_id);
    printf("%s;", e->student->id);
    printf("%.2f;", e->score);
    printf("%.2f;", e->attendance_percent);
    printf("%d\n", e->approved);
}