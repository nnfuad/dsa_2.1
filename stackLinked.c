#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} Node;

struct Stack {
    struct Node* top; 
} Stack;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    }
    return stack->top->data;
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    printf("Popped: %d\n", pop(&stack));
    display(&stack);

    printf("Top element: %d\n", peek(&stack));
    display(&stack);

    return 0;
}