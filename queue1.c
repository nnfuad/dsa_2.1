#include <stdio.h>
#define MAX 11 // Maximum size of the queue

// Global variables for the queue
int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to enqueue (add an element) into the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0; // Initialize front for the first element
    }
    queue[++rear] = value;
    printf("%d enqueued to the queue\n", value);
}

// Function to dequeue (remove an element) from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! No elements to dequeue\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        // Reset the queue after the last element is dequeued
        front = rear = -1;
    } else {
        front++;
    }
    return value;
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(40);
    enqueue(50);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();
    enqueue(100);
    enqueue(200);
    enqueue(300);
    enqueue(400);
    enqueue(500);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    enqueue(600);
    enqueue(700);
    display();
    return 0;
}
