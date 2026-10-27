// CLL creation in C
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void CLL_create(struct node *head);
void CLL_display(struct node *head);

int main() {
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = head; // Initialize circular linked list
    CLL_create(head);
    printf("Circular Linked List: ");
    CLL_display(head);
    return 0;
}

void CLL_create(struct node *head) {
    struct node *last;
    last = head;
    char ch;
    do {
        struct node *ptr;
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &ptr->data);
        last->next = ptr;
        ptr->next = head;
        last = ptr;
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');
}

void CLL_display(struct node *head) {
    struct node *ptr;
    ptr = head->next; // Start from the first node
    while(ptr != head) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}