#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include "forward-list.h"
#include "student.h"

typedef struct {
    Student * student;
    float score;
    float attendance_percent;
    int approved;
} Enrollment;

Enrollment * enrollment_construct(Student * s, float score, float percent, float approved);
void enrollment_destroy(Enrollment *e);

#endif