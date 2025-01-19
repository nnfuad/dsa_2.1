#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    head->val = 0;
    head->next = NULL;

    printf("Value at head: %d\n", head->val);
    printf("Address of head node: %p\n", (void*)head);
    printf("Address at head's next pointer: %p",head->next);

    struct node* first = (struct node*)malloc(sizeof(struct node));
    if (first == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    first->val = 10;
    first->next = NULL;

    printf("\n\nValue at first: %d\n", first->val);
    printf("Address of first node: %p\n", (void*)first);
    printf("Address at first's next pointer: %p",first->next);

    //Stitch head to first
    head->next = first;
    printf("\nAddress at head's next pointer: %p",head->next);

    struct node* current = head;
    printf("Linked List Elements:\n");
    while (current != NULL) {
        printf("Value: %d\n", current->val);
        current = current->next;
    }


    free(head);
    free(first);
    return 0;
}