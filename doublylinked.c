#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    struct Node* prev;
    int value;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayForward(struct Node* head) {
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

// INDEXING STARTS FROM 
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position < 1) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void searchNode(struct Node** head, int key) {
    struct  Node* temp = *head;
    int pos = 1;

    // Find the node to be deleted
    while (temp != NULL && temp->value != key) {
        temp = temp->next;
        pos++;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    else printf("Value %d found at position %d\n", key, pos);

}


int main()
{
    struct Node* head = createNode(0);
    struct Node* tail = createNode(0);
    struct Node* node1 = createNode(1);
    struct Node* node2 = createNode(2);
    
    //manual stitching
    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    node2->next = tail;
    tail->prev = node2; 
    
    insertAtPosition(&head, 2, 2);
    insertAtPosition(&head, 98, 1);

    displayForward(head);
    displayBackward(head);

    searchNode(&head,98);
}