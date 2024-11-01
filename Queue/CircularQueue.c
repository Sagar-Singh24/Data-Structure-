#include <stdio.h>
#define SIZE 5

int items[SIZE], front = -1, rear = -1;

int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

int main() {
  int i, num;
  printf("How many numbers you want to insert: ");
  scanf("%d", &num);
  for (i = 0; i < num; i++) {
    enQueue(i);
  }
  return 0;
}