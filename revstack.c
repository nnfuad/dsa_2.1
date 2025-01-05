#include <stdio.h>

#include <stdlib.h>

#define MAX 100

struct Stack {
  int top;
  int items[MAX];
};

void createStack(struct Stack * stack) {
  stack -> top = -1;
}

int isEmpty(struct Stack * stack) {
  return stack -> top == -1;
}

int isFull(struct Stack * stack) {
  return stack -> top == MAX - 1;
}

void push(struct Stack * stack, int item) {
  if (isFull(stack)) {
    printf("Stack overflow\n");
    return;
  }
  stack -> items[++stack -> top] = item;
}

int pop(struct Stack * stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    return -1;
  }
  return stack -> items[stack -> top--];
}

void insertAtBottom(struct Stack * stack, int item) {
  if (isEmpty(stack)) {
    push(stack, item);
    return;
  }

  int temp = pop(stack);
  insertAtBottom(stack, item);
  push(stack, temp);
}

void reverseStack(struct Stack * stack) {
  if (!isEmpty(stack)) {
    int temp = pop(stack);
    reverseStack(stack);
    insertAtBottom(stack, temp);
  }
}

void printStack(struct Stack * stack) {
  for (int i = 0; i <= stack -> top; i++) {
    printf("%d ", stack -> items[i]);
  }
  printf("\n");
}

int main() {
  struct Stack myStack;
  createStack( & myStack);

  push( & myStack, 1);
  push( & myStack, 2);
  push( & myStack, 3);
  push( & myStack, 4);

  printf("Original Stack: ");
  printStack( & myStack);
  reverseStack( & myStack);
  printf("Reversed Stack: ");
  printStack( & myStack);

  return 0;
}