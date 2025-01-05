#include <stdio.h>
int const MAX = 100;
int queue[MAX];
int front = -1, rear = -1;

int isEmpty(){
    if(front == -1) return 1;
    else return 0;
}

int isFull(){
    if(rear == MAX-1) return 1;
    else return 0;
}

void enqueue(int val){
    if(isEmpty()){
        front = 0;
    }
    if(isFull()) printf("Queue Full. Nothing to enqueue\n");
    rear++;
    queue[rear] = val;
}

int dequeue(){
    
    int deqval = queue[front];
    if(!isEmpty()){
     if(front == rear){
        front = rear = -1;
    }
    else front++;       
    }

    else {
        printf("Queue Empty, Nothing to dequeue...\n");
    }
    return deqval;
}

void display() {
    if (isEmpty()) {
        printf("Empty Queue\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){

    enqueue(20);
    enqueue(100);
    display();
    dequeue();
    display();


}