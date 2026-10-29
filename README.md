# STUDENT_RECORD_SYSTEM_using_structures
Modular Student Record Management System in C. Features structured profiles, alphanumeric duplicate ID checking, search/modify logic, and Bubble Sort logic. Uses binary file I/O (fread/fwrite) for automatic local data persistence.
//readme_file for c mini project student database
# Student Record System

A modular and persistent **Student Record Management System** implemented in C. This project allows users to manage student profiles, perform administrative database operations, track academic performance metrics, and persist data across executions using disk storage.

## Features
- **Add Records:** Append new profiles with structural field validations and alphanumeric duplicate Student ID checking.
- **Delete Records:** Purge rows based on unique Student ID or group filters matched via Name strings.
- **Modify Records:** Target specific nodes to alter specific fields like Name, DOB, or individual academic percentages.
- **Sort Registry:** Reorganize database records sequentially via a Bubble-Sort algorithm dynamically matching Name strings or Graduation percentages.
- **Data Persistence:** Automatically serializes volatile states into standard binary catalog structure files (`student.dat`) during active shutdowns and auto-loads tables during runtime initiations.

## File Structure
- `student.h` - Shared core data structures and function prototypes.
- `main.c` - System orchestrator loop containing UI menus.
- `stud_add.c` - Business logic implementation to validate and add entries.
- `stud_del.c` - Functional routine to delete records.
- `stud_show.c` - Standard formatted table output console renderer.
- `stud_mod.c` - Direct field pointer modifier configuration rules.
- `stud_sort.c` - Bubble-sort implementation.
- `stud_persistence.c` - Binary file streams handlers (`wb`/`rb`).

## How to Build and Run

### Compilation
Compile the system using standard `gcc` tools by running this command in your terminal:
```bash
gcc main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_persistence.c stud_sort.c -o student_system
```

### Run Program
Execute the compiled binary application:
```bash
./student_system
```
