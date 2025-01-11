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
    printf("%d queued", val);
}

int dequeue(){
    
    int deqval = queue[front];
    if(!isEmpty()){
     if(front == rear){
        front = rear = -1;
    }
    else {
        front++;
        printf("%d Dequeued", deqval);
    }       
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

void bubble(){
    for(int i = front ; i<rear; i++){
        for(int j= front ; j<rear ; j++){
            if(queue[j]>queue[j+1]){
                int temp = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp;
            }
        }
    }
    printf("Sorted array is: ");
    for(int i = front ; i<=rear ;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){

    enqueue(20);
    enqueue(100);
    enqueue(200);
    display();
    dequeue();
    display();
    enqueue(5);
    enqueue(15);
    enqueue(24);
    display();
    bubble();
    enqueue(30);
    display();
    bubble();


}