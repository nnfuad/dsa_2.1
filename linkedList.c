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

    head->val = 10;
    head->next = NULL;

    printf("Value at head: %d\n", head->val);
    printf("Address of head node: %p\n", (void*)head);
    printf("Address at head's next pointer: %p",head->next);

    free(head);
    return 0;
}