// Implementing Circular Queue in C
#include <stdio.h>
#define SIZE 5

struct job {
    int job_id;
    char job_title[20];
};

int front = 0, rear = 0;
int isEmpty(int front, int rear);
int isFull(int front, int rear);
void enqueue(struct job Que[SIZE], struct job j);
void dequeue(struct job Que[SIZE]);
void display(struct job Que[SIZE], int front, int rear);

int main() {
    struct job Que[SIZE];
    struct job j;
    int choice;

    while(1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(isFull(front, rear)) {
                    printf("Queue is full. Cannot enqueue.\n");
                }
                else {
                    printf("Enter Job ID: ");
                    scanf("%d", &j.job_id);
                    printf("Enter Job Title: ");
                    scanf("%s", j.job_title);
                    enqueue(Que, j);
                }
                break;
            case 2:
                if (isEmpty(front, rear)) {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                else {
                    dequeue(Que);
                }
                break;
            case 3:
                display(Que, front, rear);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

int isEmpty(int front, int rear) {
    if (front == rear) {
        return 1;
    }
    return 0;
}

int isFull(int front, int rear) {
    if ((rear + 1) % SIZE == front) {
        return 1;
    }
    return 0;
}

void enqueue(struct job Que[SIZE], struct job j) {
    if (isFull(front, rear)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    else {
        rear = (rear + 1) % SIZE;
        Que[rear] = j;
        printf("Enqueued Job ID: %d, Job Title: %s\n", j.job_id, j.job_title);
    }
}

void dequeue(struct job Que[SIZE]) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    else {
        front = (front + 1) % SIZE;
        printf("Dequeued Job ID: %d, Job Title: %s\n", Que[front].job_id, Que[front].job_title);
    }
}

void display(struct job Que[SIZE], int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty.\n");
        return;
    }
    else {
        printf("Queue contents:\n");
        int i = (front + 1) % SIZE;
        while (i != (rear + 1) % SIZE) {
            printf("Job ID: %d, Job Title: %s\n", Que[i].job_id, Que[i].job_title);
            i = (i + 1) % SIZE;
        }
    }
}