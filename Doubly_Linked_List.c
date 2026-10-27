// Implementing Doubly Linked List in C
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void DLL_create(struct node *head);
void DLL_display(struct node *head);
void DLL_backward_display(struct node *head);
void Add_at_pos(struct node *head);
void Del_at_pos(struct node *head);

int main() {
    int ch;
    struct node *head;
    head  = (struct node *)malloc(sizeof(struct node));
    head->next = head->prev = NULL;

    printf("Doubly Linked List Operations:\n");
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Backward Display\n");
    printf("4. Add at Position\n");
    printf("5. Delete at Position\n");
    
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch) {
        case 1:
            printf("Creating Doubly Linked List:\n");
            DLL_create(head);
            break;

        case 2:
            printf("Displaying Doubly Linked List:\n");
            DLL_display(head);
            break;

        case 3:
            printf("Displaying Doubly Linked List in Reverse:\n");
            DLL_backward_display(head);
            break;

        case 4:
            printf("Adding at Position:\n");
            Add_at_pos(head);
            break;

        case 5:
            printf("Deleting at Position:\n");
            Del_at_pos(head);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void DLL_create(struct node *head) {
    struct node *last;
    int ch;
    last = head;
    do {
        struct node *ptr;
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter ptr data: ");
        scanf("%d", &ptr->data);
        last->next = ptr;
        ptr->next = NULL;
        ptr->prev = last;
        last = ptr;
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');
}

void DLL_display(struct node *head) {
    struct node *temp;
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void DLL_backward_display(struct node *head) {
    struct node *temp;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    while(temp->prev != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void Add_at_pos(struct node *head) {
    struct node *temp;
    struct node *ptr;
    int pos;
    int count = 0;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to add: ");
    scanf("%d", &ptr->data);
    printf("Enter position to add: ");
    scanf("%d", &pos);
    temp = head;
    while(temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }
    ptr->next = temp;
    ptr->prev = temp->prev;
    temp->prev = ptr;
    temp->next = ptr;
}

void Del_at_pos(struct node *head) {
    struct node *ptr;
    struct node *temp;
    int pos;
    int count = 0;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    temp = head;
    while(temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }
    if(temp == NULL) {
        printf("Position not found!\n");
        return;
    }
    if(temp->prev != NULL) {
        ptr = temp->prev;
        ptr->next = temp->next;
    }
    if(temp->next != NULL) {
        ptr = temp->next;
        ptr->prev = temp->prev;
    }
}