#include <stdio.h>
#define MAX_SIZE 100 
int stack[MAX_SIZE];
int top = -1;

void push(int value) {
   if (top == MAX_SIZE - 1) {
       printf("Stack Overflow\n");
       return;
   }
   stack[++top] = value;
}

int pop() {
   if (top == -1) {
       printf("Stack Underflow\n");
       return -1;
   }
   return stack[top--];
}

int factorial(int n) {
   if (n == 0 || n == 1) {
       return 1;
   } else {
       push(n); 
       int result = n * factorial(n - 1); 
       push(result); 
       return pop(); 
   }
}

int main() {
   int num;
   printf("Enter a number: ");
   scanf("%d", &num);

   if (num < 0) {
       printf("Factorial is not defined for negative numbers.\n");
   } else {
       printf("Factorial of %d = %d\n", num, factorial(num));
   }

   return 0;
}