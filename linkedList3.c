#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct node* current){
    while(current!= NULL){
        printf("value: %d\n", current->val);
        current = current->next;
    }
}

int main(){
    // struct node* head = (struct node*)malloc(sizeof(struct node));
    // if (head == NULL) {
    //     printf("Memory allocation failed.\n");
    //     return 1;
    // }
    struct node* head = createNode(0);
    printf("\n");
    printList(head);

    struct node* first = createNode(1);
    
    head->next = first;
    struct node* second = createNode(2);
    first->next = second;
    printf("\n");
    printList(head);
    struct node* third = createNode(3);
    first->next->next = third;
    printf("\n");
    printList(head);

}