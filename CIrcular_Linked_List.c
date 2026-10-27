// Implementing Circular Linked List in C
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
    if(head == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    head->next = head;
    CLL_create(head);
    CLL_display(head);

    return 0;
}

void CLL_create(struct node *head) {
    struct node *last = head;
    struct node *ptr;
    char ch;

    do {
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter node data: ");
        scanf("%d", &ptr->data);

        last->next = ptr;
        ptr->next = head;
        last = ptr;

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void CLL_display(struct node *head) {
    struct node *temp = head->next;

    if (temp == head) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("(head)\n");
}