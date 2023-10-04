#include "enrollment.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Enrollment * enrollment_construct(char* course_id, char* student_id, float score, float percent, float approved){
    Enrollment *e = (Enrollment*)malloc(sizeof(Enrollment));
    strcpy(e->student_id, student_id);
    strcpy(e->course_id, course_id);
    e->score = score;
    e->attendance_percent = percent;
    e->approved = approved;

    return e;
}

Enrollment * enrollment_read();

void enrollment_destroy(void * enrollment){
    Enrollment * e = enrollment;
    free(e);
}