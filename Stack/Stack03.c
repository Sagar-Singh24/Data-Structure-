#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Overflow\n");
        return;
    }
    s->items[++s->top] = c;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

void reverseString(char *input) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    for (int i = 0; i < strlen(input); i++) {
        input[i] = pop(&stack);
    }
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}
