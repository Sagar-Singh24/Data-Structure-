#include <stdio.h>
#define max 100

int front = -1, rear = -1;
 int queue[max];
   
    void insert(int element)
    {
        if (rear == max - 1)
        {
            printf("Queue is overflow");
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
        printf("1.Insert\n2.Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int element;
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &element);
            insert(element);
            break;
            case 2:
            display();
            break;
        }
    } while (choice);
    return 0;
}