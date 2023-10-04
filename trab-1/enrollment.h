#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include "forward-list.h"
#include "student.h"

typedef struct {
    char student_id[10];
    char course_id[10];
    float score;
    float attendance_percent;
    int approved;
} Enrollment;

Enrollment * enrollment_construct(char* course_id, char* student_id, float score, float percent, float approved);
Enrollment * enrollment_read();
void enrollment_destroy(void *enrollment);

#endif