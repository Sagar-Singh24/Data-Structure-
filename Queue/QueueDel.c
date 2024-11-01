#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted -> %d\n", value);
}

void dequeue() {
    if(front == NULL) {
        printf("Queue is Empty!!\n");
    } else {
        Node* temp = front;
        printf("Deleted -> %d\n", front->data);
        front = front->next;
        if(front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

void display() {
    Node* temp = front;
    if(front == NULL) {
        printf("Queue is Empty!!\n");
    } else {
        printf("Queue elements are:\n");
        while(temp != NULL) {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
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