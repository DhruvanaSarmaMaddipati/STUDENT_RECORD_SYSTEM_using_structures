#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void stud_add() {
     if (student_count >= student_capacity) {
        int new_capacity = (student_capacity == 0) ? 5 : student_capacity * 2;
        Student *temp = realloc(students, new_capacity * sizeof(Student));
        
        if (temp == NULL) {
            printf("\nMemory Allocation Error: Heap memory full!\n");
            return;
        }
        students = temp;
        student_capacity = new_capacity;
    }

    char temp_id[15];
    int duplicate;

    while (1) {
        duplicate = 0;
        printf("\nEnter Unique Student ID: ");
        scanf(" %s", temp_id);

        for (int i = 0; i < student_count; i++) {
            if (strcmp(students[i].student_id, temp_id) == 0) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate) {
            break;
        }
        printf("Error: Duplicate Student ID detected. Please try again.\n");
    }

    strcpy(students[student_count].student_id, temp_id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]s", students[student_count].name);

    printf("Enter Date of Birth (DD-MM-YYYY): ");
    scanf(" %s", students[student_count].dob);

    printf("Enter Matriculation Percentage: ");
    scanf("%f", &students[student_count].perc_matric);

    printf("Enter Inter/Diploma Percentage: ");
    scanf("%f", &students[student_count].perc_inter);

    printf("Enter Graduation Percentage: ");
    scanf("%f", &students[student_count].perc_grad);

    student_count++;
    printf("\nRecord appended successfully.\n");
}
