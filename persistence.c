#include <stdio.h>
#include "student.h"

void stud_save() {
    FILE *fp = fopen("student.dat", "wb");
    if (fp == NULL) {
        printf("\nDisk write protection or descriptor failure error!\n");
        return;
    }
    fwrite(students, sizeof(Student), student_count, fp);
    fclose(fp);
    printf("\nData committed to student.dat array storage catalog.\n");
}

void stud_load() {
    FILE *fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        return;
    }
    student_count = fread(students, sizeof(Student), MAX_STUDENTS, fp);
    fclose(fp);
}
