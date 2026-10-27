#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int regNo;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

// Function to add a student
void addStudent() {
    struct Student *newNode, *temp;
    int regNo;
    char name[50];

    printf("Enter Registration Number: ");
    scanf("%d", &regNo);

    temp = head;
    while (temp != NULL) {
        if (temp->regNo == regNo) {
            printf("Registration Number already exists!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", name);

    newNode = (struct Student *)malloc(sizeof(struct Student));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->regNo = regNo;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Student is added successfully.\n");
}

// Function to remove a student
void removeStudent() {
    struct Student *temp = head;
    struct Student *prev = NULL;
    int regNo;

    if (head == NULL) {
        printf("No students registered.\n");
        return;
    }

    printf("Enter Registration Number to remove: ");
    scanf("%d", &regNo);

    while (temp != NULL && temp->regNo != regNo) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Student record is deleted successfully.\n");
}

// Function to display all students
void displayStudents() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("No students registered.\n");
        return;
    }
    printf("\n--- Registered Students ---\n");
    printf("%-15s %-30s\n", "Reg. Number", "Student Name");
    printf("-----------------------------------------------\n");

    while (temp != NULL) {
        printf("%-15d %-30s\n", temp->regNo, temp->name);
        temp = temp->next;
    }
}

// Function to count total participants
void countStudents() {
    struct Student *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total participants: %d\n", count);
}

// Function to sort students by Registration Number
void sortStudents() {
    struct Student *i, *j;
    int tempRegNo;
    char tempName[50];

    if (head == NULL || head->next == NULL) {
        printf("List sorted successfully.\n");
        return;
    }
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->regNo > j->regNo) {
                tempRegNo = i->regNo;
                i->regNo = j->regNo;
                j->regNo = tempRegNo;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }
    printf("Students sorted by Registration Number successfully.\n");
}

// Function to reverse the linked list
void reverseList() {
    struct Student *prev = NULL;
    struct Student *current = head;
    struct Student *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("List reversed successfully.\n");
}

// Function to free all allocated memory
void freeList() {
    struct Student *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n===== WORKSHOP ENROLLMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Students\n");
        printf("4. Count Total Participants\n");
        printf("5. Sort Students\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                removeStudent();
                break;

            case 3:
                displayStudents();
                break;

            case 4:
                countStudents();
                break;

            case 5:
                sortStudents();
                break;

            case 6:
                reverseList();
                break;

            case 7:
                freeList();
                printf("Exiting program. Memory released.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}