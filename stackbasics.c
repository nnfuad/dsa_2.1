#include <stdio.h>

int MAX = 8;

int stack[8];
int top = -1;

int isFull() { return top == MAX - 1; }

int isEmpty() { return top == -1; }

void push(int data) {
  if (!isFull()) {
    stack[++top] = data;
  } else {
    printf("Stack is full...\n");
  }
}

int pop() {
  if (!isEmpty()) {
    return stack[top--];
  } else {
    printf("Stack is empty...\n");
    return -1;  // Return an error code.
  }
}

void print() {
  if (top > -1) {
    for (int i = 0; i <= top; i++) {
      printf("Element %d is %d\n", i + 1, stack[i]);
    }
  } else {
    printf("Empty stack\n");
  }
}

int main() {
  push(15);
  push(10);
  push(5);

  print();

  int p = pop();
  printf("Popped value: %d\n", p);
  push(23);
  print();

  return 0;
}