#include <stdio.h>
#include <string.h>

struct Employee {
    char name[20];
    char designation[20];
    int id;
};

void accept(struct Employee E[], int n);
void display(struct Employee E[], int n);
void bubblesorting(struct Employee E[], int n);

int main() {
    int n;
    printf("Enter the no. of employees: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid");
        return 1;
    }

    struct Employee emp[n];
    printf("\n Enter employee details \n");
    accept(emp, n);

    printf("Employee List \n");
    display(emp, n);

    bubblesorting(emp, n);

    printf("Sorted Employee List \n");
    display(emp, n);

    return 0;
}

void accept(struct Employee E[100], int n) {
    for(int i=0; i<n; i++) {
        printf("\nEmployee %d\n", i+1);
        printf("Employee id: ");
        scanf("%d", &E[i].id);

        printf("\nEmployee name: ");
        scanf("%s", E[i].name);

        printf("\nEmployee Post: ");
        scanf("%s", E[i].designation);
    }
}

void display(struct Employee E[100], int n) {
    for (int i=0; i < n; i++) {
        printf("%d \t %s\t %s \n", E[i].id, E[i].name, E[i].designation);
    }
}

void bubblesorting(struct Employee E[100], int n) {
    struct Employee temp;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++){
            if(E[j].id > E[j+1].id) {
                temp = E[j];
                E[j] = E[j+1];
                E[j+1] = temp;
            }
        }
    }
}