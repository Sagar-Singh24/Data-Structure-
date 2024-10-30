#include <stdio.h>
#define MAX_SIZE 100
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};
void initialize(struct Stack *s)
{
    s->top = -1;
}
int Empty(struct Stack *s)
{
    return s->top == -1;
}
int Full(struct Stack *s)
{
    return s->top == MAX_SIZE - 1;
}
void push(struct Stack *s, int element)
{
    if (Full(s))
    {
        printf("Overflow!\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        s->arr[i + 1] = s->arr[i];
    }
    s->arr[0] = element;
    s->top++;
}
void printStack(struct Stack *s)
{
    if (Empty(s))
    {
        printf("Empty\n");
        return;
    }
    printf("Elements: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);

    return 0;
}