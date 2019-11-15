#ifndef STUDENT_H
#define STUDENT_H

// Create a linked list Node named “Student”
typedef struct Student {
    // Define elements for each Student Node
    int ID;
    char name[20];
    struct Student *next;
} Student;

// Print the linked list in order starting from “head”. Print all elements for each node.
void printStudent(Student*);

// Create and insert new nodes in the linked list. The insertion should happen in alphabetical order of the first-name. The values for the ID and fName are to be taken from user.
Student* insertStudentByName(Student*, int, char*);

// Sort the linked list in increasing order of the student-id (integer). You can use any sorting algorithm – bubble, selection, insertion, merge.
Student* sortListByID(Student*, int, char*);

#endif