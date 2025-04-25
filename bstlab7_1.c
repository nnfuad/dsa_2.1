#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void insertNode(struct Node* current, int data) {
    char choice;
    while (1) {
        printf("Insert %d to the (L)eft or (R)ight of %d? ", data, current->data);
        scanf(" %c", &choice);

        if (choice == 'L' || choice == 'l' || choice == 'Left' || choice == 'left' || choice == 'LEFT') {
            if (current->left == NULL) {
                current->left = createNode(data);
                printf("%d inserted to the left of %d.\n", data, current->data);
                break;
            } else {
                current = current->left;
            }
        } else if (choice == 'R' || choice == 'r' || choice == 'Right' || choice == 'right' || choice == 'RIGHT') {
            if (current->right == NULL) {
                current->right = createNode(data);
                printf("%d inserted to the right of %d.\n", data, current->data);
                break;
            } else {
                current = current->right;
            }
        } else {
            printf("Invalid choice. Please enter 'L' or 'R'.\n");
        }
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    printf("Binary Tree Implementation\n");

    while (1) {
        printf("\n1. Insert Node\n2. Inorder Traversal\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                if (root == NULL) {
                    root = createNode(data);
                    printf("%d inserted as the root node.\n", data);
                } else {
                    insertNode(root, data);
                }
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}