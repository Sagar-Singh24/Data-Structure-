#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100

int queue[LIMIT];          // Array implementation of the queue
int front = -1, rear = -1; // Front and rear pointers

void insert(int element)
{
    if (rear == LIMIT - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Element %d has been inserted into the queue.\n", element);
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The deleted element in the queue is: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Elements of the queue are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    int choice;

    printf("Array implementation of a queue\n");
    do
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int element;
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted in the queue: ");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}