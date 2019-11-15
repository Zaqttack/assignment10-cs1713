#include<stdio.h>
#include<string.h>
#include"student.h"

int main(int argc, char *argv[]){
    // Write code such that user can keep on providing the input. Consider a stop case – ask the user if s/he wants to continue or stop.
    Student* charHead = NULL;
    Student* numHead = NULL;
    int ID;
    char userInput, name[20];

    while(userInput != 'n') {
        printf("Do you wish to add a student (y/n):");
        scanf("%c", &userInput);

        switch(userInput) {
            case 'y':
                printf("ID: ");
                scanf("%d", &ID);
                printf("Name: ");
                scanf("%s", name);

                // Create a new node for each user input (student ID and fName). Insert this node in the linked list in alphabetical order of the fName by calling the “insertStudentByName()” function written in “student.c”
                charHead = insertStudentByName(charHead, ID, name);
                numHead = sortListByID(numHead, ID, name);
                fflush(stdin);
                break;
            case 'n':
            default:
                break;
        }
    }


    // Print the original list by calling the “print()” function in “student.c”. This print should have the list sorted by fName.
    printf("Students in the original linked list (sorted by fName) are –\n");
    printStudent(charHead);

    // Sort the linked list in increasing order of the student ID by calling the “sortListByID()” function written in the “student.c” file.
    printf("\nSorting the linked list by student ID\n\n");

    // Print the sorted list by calling the “print()” function in “student.c”. This print should have the list sorted by ID.
    printf("Students in the sorted linked list (sorted by ID) are –\n");
    printStudent(numHead);

    return 0;
}