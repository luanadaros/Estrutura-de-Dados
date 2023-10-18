#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include "forward-list.h"
#include "student.h"

typedef struct {
    Student * student;
    char course_id[10];
    float score;
    float attendance_percent;
    int approved;
} Enrollment;

Enrollment * enrollment_construct(char* course_id, Student * student, float score, float percent, float approved);
Enrollment * enrollment_read(ForwardList * students);
void enrollment_destroy(void *enrollment);

#endif