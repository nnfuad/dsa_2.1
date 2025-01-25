#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("%d has been pushed onto the stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("The stack is empty\n");
    } else {
        struct node* temp = top;
        printf("%d has been popped\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    display();
    return 0;
}