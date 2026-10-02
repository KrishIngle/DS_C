// Linear Queue Implementation in C
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct job {
    int job_id;
    char job_title[20];
};

int front = -1, rear = -1;
void isEmpty(int front, int rear);
void isFull(int rear);
void enqueue(struct job Que[SIZE], struct job j);
void dequeue(struct job Que[SIZE]);
void display(struct job Que[SIZE]);

int main() {
    struct job Que[SIZE];
    struct job j;
    int choice;

    while(1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(rear == SIZE - 1) {
                    isFull(rear);
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
                if (front == -1) {
                    isEmpty(front, rear);
                }
                else {
                    dequeue(Que);
                }
                break;
            case 3:
                display(Que);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void isEmpty(int front, int rear) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue is not empty.\n");
    }
}

void isFull(int rear) {
    if (rear == SIZE - 1) {
        printf("Queue is full.\n");
    }
    else {
        printf("Queue is not full.\n");
    }
}

void enqueue(struct job Que[SIZE], struct job j) {
    if (rear == SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        Que[rear] = j;
        printf("Enqueued: Job ID: %d, Job Title: %s\n", j.job_id, j.job_title);
    }
}

void dequeue(struct job Que[SIZE]) {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else {
        struct job j = Que[front];
        printf("Dequeued: Job ID: %d, Job Title: %s\n", j.job_id, j.job_title);
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
    }
}

void display(struct job Que[SIZE]) {
    if (front == -1) {
        printf("Queue is empty. Nothing to display.\n");
    }
    else {
        printf("Queue contents:\n");
        for (int i = front; i <= rear; i++) {
            printf("Job ID: %d, Job Title: %s\n", Que[i].job_id, Que[i].job_title);
        }
    }
}