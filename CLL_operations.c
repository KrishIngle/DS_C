// CLL operations in C
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

void CLL_create(struct node *head, int *degree);
void CLL_display(struct node *head, int degree);
void CLL_add(struct node *head1, struct node *head2, struct node *head3, int *deg3);

int main() {
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    struct node *head3 = (struct node *)malloc(sizeof(struct node));

    if (!head1 || !head2 || !head3) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    head1->next = head1;
    head2->next = head2;
    head3->next = head3;

    int deg1 = -1, deg2 = -1, deg3 = -1;

    printf("=== Create First Polynomial (P1) ===\n");
    CLL_create(head1, &deg1);

    printf("\n=== Create Second Polynomial (P2) ===\n");
    CLL_create(head2, &deg2);

    CLL_add(head1, head2, head3, &deg3);

    printf("\n=== First Polynomial P1(x) ===\n");
    CLL_display(head1, deg1);

    printf("\n=== Second Polynomial P2(x) ===\n");
    CLL_display(head2, deg2);

    printf("\n=== Resultant Polynomial P3(x) = P1(x) + P2(x) ===\n");
    CLL_display(head3, deg3);

    return 0;
}

void CLL_create(struct node *head, int *degree) {
    struct node *last = head;
    struct node *ptr;
    char ch;

    do {
        ptr = (struct node *)malloc(sizeof(struct node));
        if (!ptr) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter coefficient: ");
        scanf("%d", &ptr->coeff);
        printf("Enter exponent: ");
        scanf("%d", &ptr->exp);

        if (ptr->exp > *degree) {
            *degree = ptr->exp;
        }

        last->next = ptr;
        ptr->next = head;
        last = ptr;

        printf("Do you want to add another term (y/n)? ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void CLL_add(struct node *head1, struct node *head2, struct node *head3, int *deg3) {
    struct node *p1 = head1->next;
    struct node *p2 = head2->next;
    struct node *last3 = head3;
    struct node *ptr;

    while (p1 != head1 && p2 != head2) {
        if (p1->exp == p2->exp) {
            int sum_coeff = p1->coeff + p2->coeff;
            if (sum_coeff != 0) {
                ptr = (struct node *)malloc(sizeof(struct node));
                ptr->coeff = sum_coeff;
                ptr->exp = p1->exp;

                last3->next = ptr;
                ptr->next = head3;
                last3 = ptr;

                if (p1->exp > *deg3) *deg3 = p1->exp;
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->coeff = p1->coeff;
            ptr->exp = p1->exp;

            last3->next = ptr;
            ptr->next = head3;
            last3 = ptr;

            if (p1->exp > *deg3) *deg3 = p1->exp;
            p1 = p1->next;
        } else {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->coeff = p2->coeff;
            ptr->exp = p2->exp;

            last3->next = ptr;
            ptr->next = head3;
            last3 = ptr;

            if (p2->exp > *deg3) *deg3 = p2->exp;
            p2 = p2->next;
        }
    }
    while (p1 != head1) {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->coeff = p1->coeff;
        ptr->exp = p1->exp;

        last3->next = ptr;
        ptr->next = head3;
        last3 = ptr;

        if (p1->exp > *deg3) *deg3 = p1->exp;
        p1 = p1->next;
    }
    while (p2 != head2) {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->coeff = p2->coeff;
        ptr->exp = p2->exp;

        last3->next = ptr;
        ptr->next = head3;
        last3 = ptr;

        if (p2->exp > *deg3) *deg3 = p2->exp;
        p2 = p2->next;
    }
}

void CLL_display(struct node *head, int degree) {
    struct node *temp = head->next;

    if (temp == head) {
        printf("Polynomial is empty.\n");
        return;
    }
    printf("Degree: %d\n", degree);
    printf("P(x) = ");
    while (temp != head) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        temp = temp->next;
        if (temp != head) {
            printf(" + ");
        }
    }
    printf("\n");
}