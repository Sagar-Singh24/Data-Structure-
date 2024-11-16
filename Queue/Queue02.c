#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = data;
    printf("%d enqueued to the queue.\n", data);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    front++;
}

void traverse() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Nothing to traverse.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nLinear Queue Menu:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}