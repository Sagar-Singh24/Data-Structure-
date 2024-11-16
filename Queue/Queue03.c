#include <stdio.h>
#define MAX 10
int f = -1; 
int r = -1;
int QUEUE[MAX];
int isFull() 
{
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
        return 1;
    else
        return 0;
}
int isEmpty() 
{
    if (f==-1)
        return 1;
    else
        return 0;
}
void CQINSERT(int item) 
{
    if (isFull()) 
    {
        printf("Queue Overflow\n");
        return;
    }
    if (f == -1)
        f = 0;
    r = (r + 1) % MAX;
    QUEUE[r] = item;
    printf("Inserted %d\n", item);
}
void CQDELETE() 
{
    int item;
    if (isEmpty()) 
    {
        printf("Queue Underflow\n");
        return;
    }
    item = QUEUE[f];
    printf("Deleted %d\n", item);
    if (f == r)
        f = r = -1;
    else
        f = (f + 1) % MAX;
}
int main() 
{
    CQINSERT(1);
    CQINSERT(2);
    CQINSERT(3);
    CQDELETE();
    CQDELETE();
    CQDELETE();
    CQDELETE();

    return 0;
}
