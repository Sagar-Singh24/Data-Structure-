#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

void push(int stack[], int *top, int data) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = data;
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow.\n");
        exit(1);
    }
    int data = stack[*top];
    *top = *top - 1;
    return data;
}

void enqueue(int data) {
    push(stack1, &top1, data);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty.\n");
        exit(1);
    }
    if (top2 == -1) {
        while (top1 != -1) {
            push(stack2, &top2, pop(stack1, &top1));
        }
    }
    return pop(stack2, &top2);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    enqueue(4);
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    return 0;
}
