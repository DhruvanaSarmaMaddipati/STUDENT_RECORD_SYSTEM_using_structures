#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_sort() {
    if (student_count < 2) {
        printf("\nInsufficient element volume to organize metrics.\n");
        return;
    }
    char choice;
    printf("\nN/n : Sort by Name\n");
    printf("G/g : Sort by Graduation Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            int swap_flag = 0;
            if (choice == 'N' || choice == 'n') {
                if (strcmp(students[j].name, students[j + 1].name) > 0) swap_flag = 1;
            } else {
                if (students[j].perc_grad > students[j + 1].perc_grad) swap_flag = 1;
            }
            if (swap_flag) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("\nArray indexes reorganized successfully. Select 'S' to verify layout matrix.\n");
}
