#include <stdio.h>
#include "student.h"

void stud_show() {
    if (student_count == 0) {
        printf("\nNo records recorded to evaluate.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("%-12s %-20s %-12s %-10s %-10s %-10s\n", "Student ID", "Name", "DOB", "Matric%", "Inter%", "Grad%");
    printf("-----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-12s %-20s %-12s %-10.1f %-10.1f %-10.1f\n",
               students[i].student_id, students[i].name, students[i].dob,
               students[i].perc_matric, students[i].perc_inter, students[i].perc_grad);
    }
    printf("-----------------------------------------------------------------------------------------\n");
}
