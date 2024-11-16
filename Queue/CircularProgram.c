#include <stdio.h>
#define max 5
int items[max], front = -1, rear = -1;

void CQINSERT(int element) {
   if (rear == max - 1)
        {
            printf("Queue is overflow\n");
        }
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % max;
    items[rear] = element;
    printf("\nInserted element: %d\n", element);
  }
}

void CQDELETE()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The deleted element in the queue is: %d\n", items[front]);
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
            printf("%d\n", items[i]);
        }
    }
}

int main()
{
    int choice;
    printf("Array implementation of a queue\n");
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int element;
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &element);
            CQINSERT(element);
            break;
            case 2:
            CQDELETE();
            break;
            case 3:
            display();
            break;
        }
    } while (choice);
    return 0;
}