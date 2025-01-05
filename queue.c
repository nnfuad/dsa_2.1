#include <stdio.h>
int MAX=100;
int queue[MAX];
int front = -1, rear = -1

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
    if(isFull()) printf("Queue Full...\n");
    rear++;
    queue[rear] = val;
}

void dequeue(){
    
    if(!isEmpty()){
        int deqval = queue[front];
            
    }
}

int main(){



}