#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct node* insertNode(struct node* head, int key, int val){
    struct node* curr = head;
    while (curr != NULL) {
        if (curr->val == val)
            break;
        curr = curr->next;
    }

    if (curr == NULL)
        return head;

    struct node* newNode = createNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

bool searchLinkedList(struct node* head, int target)
{
    // Traverse the Linked List
    while (head != NULL) {

        // Check if the current node's
        // data matches the target value
        if (head->val == target) {
            return true; // Value found
        }

        // Move to the next node
        head = head->next;
    }

    return false; // Value not found
}

void printList(struct node* current){
    while(current!= NULL){
        printf("value: %d\n", current->val);
        current = current->next;
    }
}

int main(){

    struct node* head = createNode(0);
    printList(head);
    
    struct node* first = createNode(1);
    head->next = first;

    struct node* second = createNode(2);
    first->next = second;
    
    struct node* third = createNode(3);
    first->next->next = third;

    head = insertNode(head, 3, 4);
    printList(head);

}