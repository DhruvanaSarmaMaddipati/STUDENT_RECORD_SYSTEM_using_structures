#include <stdio.h>
#include <string.h>
#include "student.h"

void stud_mod() {
    if (student_count == 0) {
        printf("\nOperation cancelled. Database array empty.\n");
        return;
    }

    char choice, mod_choice;
    char target_id[15] = "";
    int found = 0;

    printf("\n[Step 1: Search Record]\n");
    printf("I/i : Student ID\n");
    printf("N/n : Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'I' || choice == 'i') {
        printf("Enter target Student ID: ");
        scanf(" %s", target_id);
    }
    else if (choice == 'N' || choice == 'n') {
        char search_name[50];
        printf("Enter Name to query: ");
        scanf(" %[^\n]s", search_name);

        printf("\nMatching Catalog Records:\n");
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
            printf("\nQuery yielded zero tracking elements.\n");
            return;
        }
        printf("Enter Student ID to alter from listing above: ");
        scanf(" %s", target_id);
    } else {
        printf("\nInvalid searching methodology parameters.\n");
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
        printf("\nTarget reference block structure missing.\n");
        return;
    }

    printf("\n[Step 2: Modify Field]\n");
    printf("1 : Name\n");
    printf("2 : DOB\n");
    printf("3 : Matriculation Percentage\n");
    printf("4 : Inter/Diploma Percentage\n");
    printf("5 : Graduation Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &mod_choice);

    switch (mod_choice) {
        case '1':
            printf("Enter New Name String: ");
            scanf(" %[^\n]s", students[index_pos].name);
            printf("\nModification successful. Name field updated.\n");
            break;
        case '2':
            printf("Enter New DOB: ");
            scanf(" %s", students[index_pos].dob);
            printf("\nModification successful. DOB field updated.\n");
            break;
        case '3':
            printf("Enter New Matriculation Percent: ");
            scanf("%f", &students[index_pos].perc_matric);
            printf("\nModification successful. Matriculation percentage updated.\n");
            break;
        case '4':
            printf("Enter New Inter/Diploma Percent: ");
            scanf("%f", &students[index_pos].perc_inter);
            printf("\nModification successful. Inter/Diploma percentage updated.\n");
            break;
        case '5':
            printf("Enter New Graduation Percent: ");
            scanf("%f", &students[index_pos].perc_grad);
            printf("\nModification successful. Graduation percentage updated.\n");
            break;
        default:
            printf("\nIllegal targeting assignment criteria.\n");
    }
}
