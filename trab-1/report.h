#ifndef REPORTS_H
#define REPORTS_H

#include "forward-list.h"
#include "student.h"
#include "course.h"
#include "enrollment.h"

void enrolled_students(ForwardList * courses);
void direct_requirements(ForwardList * courses);
void full_requirements(ForwardList * courses);
void enrolled_courses(ForwardList * courses);
void approvals_per_student(ForwardList * courses);
void inconsistent_enrollment(ForwardList * enrollments);

void students_overview(ForwardList * students, ForwardList * enrollments);
void courses_overview(ForwardList * courses);

#endif