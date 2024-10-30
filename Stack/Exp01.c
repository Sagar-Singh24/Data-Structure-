#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 

int stack[MAX_SIZE];
int top = -1;  

void push(int data) {
   if (top == MAX_SIZE - 1) {
       printf("Stack overflow\n");
       return;
   }
   stack[++top] = data;  
}

int pop() {
   if (top == -1) {
       printf("Stack underflow\n");
       return -1;  
   }
   return stack[top--]; 
}

int peek() {
   if (top == -1) {
       printf("Stack is empty\n");
       return -1;  
   }
   return stack[top];
}
 
void display() {
   if (top == -1) {
       printf("Stack is empty\n");
       return;
   }
   printf("Stack elements: ");
   for (int i = top; i >= 0; i--) {
       printf("%d ", stack[i]);
   }
   printf("\n");
}

int main() {
   push(6);
   push(7);
   push(8);
   push(5);
   push(3);
   pop();
   push(10);
   pop();
   pop();

   printf("Final stack: ");
   display();  

   return 0;
}