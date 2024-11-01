#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if((rear+1)%SIZE == front) {
        printf("Queue is Full!!\n");
    } else {
        if(front == -1)
            front = 0;
        rear = (rear+1)%SIZE;
        queue[rear] = value;
        printf("Inserted -> %d\n", value);
    }
}

void dequeue() {
    if(front == -1) {
        printf("Queue is Empty!!\n");
    } else {
        printf("Deleted -> %d\n", queue[front]);
        front = (front+1)%SIZE;
        if(front == rear) {
            front = rear = -1;
        }
    }
}

void display() {
    int i;
    if(front == -1) {
        printf("Queue is Empty!!\n");
    } else {
        printf("Queue elements are:\n");
        for(i=front; i!=rear; i=(i+1)%SIZE) {
            printf("%d  ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    display();
    enqueue(6);
    enqueue(7);
    display();
    return 0;
}