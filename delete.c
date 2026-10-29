#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_del() {
    if (student_count == 0) {
        printf("\nDatabase Underflow: Zero student logs recorded.\n");
        return;
    }

    char choice;
    printf("\nI/i : Delete using Student ID\n");
    printf("N/n : Delete using Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    char target_id[15] = "";

    if (choice == 'I' || choice == 'i') {
        printf("Enter Student ID to drop: ");
        scanf(" %s", target_id);
    }
    else if (choice == 'N' || choice == 'n') {
        char search_name[50];
        printf("Enter Target Name: ");
        scanf(" %[^\n]s", search_name);

        int found = 0;
        printf("\nMatching Records Found:\n");
        printf("-----------------------------------------------------------------------------------------\n");
        printf("%-12s %-20s %-12s %-10s %-10s %-10s\n", "Student ID", "Name", "DOB", "Matric%", "Inter%", "Grad%");
        printf("-----------------------------------------------------------------------------------------\n");
        for (int i = 0; i < student_count; i++) {
            if (strcmp(students[i].name, search_name) == 0) {
                printf("%-12s %-20s %-12s %-10.1f %-10.1f %-10.1f\n",
                       students[i].student_id, students[i].name, students[i].dob,
                       students[i].perc_matric, students[i].perc_inter, students[i].perc_grad);
                found = 1;
            }
        }
        printf("-----------------------------------------------------------------------------------------\n");

        if (!found) {
            printf("\nZero active logs matched name criteria '%s'.\n", search_name);
            return;
        }

        printf("Enter Student ID from the list above to delete: ");
        scanf(" %s", target_id);
    } else {
        printf("\nInvalid criteria routing option.\n");
        return;
    }

    int index_pos = -1;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].student_id, target_id) == 0) {
            index_pos = i;
            break;
        }
    }
    
    if (index_pos == -1) {
        printf("\nNo record holds specified Student ID reference key %s.\n", target_id);
        return;
    }

    for (int i = index_pos; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }

    student_count--;
    printf("\nRecord purged and index alignment fixed.\n");
}
