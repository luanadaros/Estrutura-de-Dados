#include "enrollment.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Enrollment * enrollment_construct(Student * s, float score, float percent, float approved){
    Enrollment *e = (Enrollment*)malloc(sizeof(Enrollment));
    e->student = s;
    e->score = score;
    e->attendance_percent = percent;
    e->approved = approved;

    return e;
}

void enrollment_destroy(Enrollment *e){
    free(e);
}