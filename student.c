#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"student.h"

// Print the linked list in order starting from “head”. Print all elements for each node.
void printStudent(Student* head) {
    while(head != NULL) {
        printf("(%d,%s) -> ", head->ID, head->name);
        head = head->next;
    }
    printf("\n");
}

// Create and insert new nodes in the linked list. The insertion should happen in alphabetical order of the first-name. The values for the ID and Fname are to be taken from user.
Student* insertStudentByName(Student* head, int ID, char* name) {
    Student* n = (Student*)malloc(sizeof(Student));
    if(n == NULL) {
        printf("Was not able to malloc!\n");
        exit(-1);
    } 

    n->ID = ID;
	strcpy(n->name, name);
    n->next = NULL;

    if(head == NULL)
        return n;

    Student* pHead = head;
    if(strcmp(pHead->name, name) > 0) {
        n->next = pHead;
        return n;
    }

    while(pHead->next != NULL) {
        if(strcmp(pHead->next->name, name) > 0) {
            n->next = pHead->next;
            pHead->next = n;
            return head;
        }
        pHead = pHead->next;
    }

    pHead->next = n;

    return head;
}

// Sort the linked list in increasing order of the student-id (integer). You can use any sorting algorithm – bubble, selection, insertion, merge.
Student* sortListByID(Student* head, int ID, char* name) {
    Student* n = (Student*)malloc(sizeof(Student));
    if(n == NULL) {
        printf("Was not able to malloc!\n");
        exit(-1);
    } 

    n->ID = ID;
	strcpy(n->name, name);
    n->next = NULL;

    if(head == NULL)
        return n;

    Student* pHead = head;
    if(pHead->ID > ID) {
        n->next = pHead;
        return n;
    }

    while(pHead->next != NULL) {
        if(pHead->next->ID > ID) {
            n->next = pHead->next;
            pHead->next = n;
            return head;
        }
        pHead = pHead->next;
    }

    pHead->next = n;

    return head;
}