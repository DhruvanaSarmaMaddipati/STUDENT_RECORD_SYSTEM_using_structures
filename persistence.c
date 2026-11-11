#include <stdio.h>
#include <stdlib.h>
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

    //to find file size
fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

//to find no of records
    int records_in_file = file_size / sizeof(Student);

    if (records_in_file > 0) {
//dynamic memory allocation
        students = (Student *)malloc(records_in_file * sizeof(Student));
        if (students == NULL) {
            printf("\nMemory allocation failed during load!\n");
            fclose(fp);
            return;
        }
    
  student_count = fread(students, sizeof(Student), records_in_file, fp);
        student_capacity = records_in_file;
    }

    fclose(fp);
}
