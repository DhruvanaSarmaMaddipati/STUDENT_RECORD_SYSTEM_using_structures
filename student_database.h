#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

typedef struct {
    char student_id[15];     
    char name[50];
    char dob[15];            
    float perc_matric;       
    float perc_inter;        
    float perc_grad;         
} Student;

extern Student students[MAX_STUDENTS];
extern int student_count;

void stud_add();
void stud_del();
void stud_show();
void stud_mod();
void stud_save();
void stud_load();
void stud_sort();

#endif
