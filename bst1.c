#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Node structure for BST
struct node {
    struct node* left;
    int val;
    struct node* right;
};

//Creating a global variable for ROOT node
struct node* ROOT = NULL;

//Function to create a new node 
struct node* createNode(int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Can't create node. Memory allocation failed.\n");
        exit(1);
    }

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;
    return newNode;
}

void insertNode(struct node* node1){
    // If the tree is empty, set the root to the new node
    if (ROOT == NULL) {
        ROOT = node1;
        printf("Inserted %d as root node.\n", node1->val);
        return;
    }

    struct node* current = ROOT; //To start searching from here for correct location
    struct node* parent = NULL;

    //traverse to the correct location using the current node
    //and the parent node 
     while (current != NULL) {
        parent = current;
        //To traverse in the left subtree
        if (node1->val < current->val) {
            current = current->left;
        } 
        //To traverse in the right subtree
        else if (node1->val > current->val) {
            current = current->right;
        } 
        //BST only allows unique numbers
        else {
            printf("Value %d already exists in the tree.\n", node1->val);
            return;
        }
    }


    if (node1->val < parent->val) {
        parent->left = node1;
        printf("Inserted %d to the left of %d.\n", node1->val, parent->val);
    } else {
        parent->right = node1;
        printf("Inserted %d to the right of %d.\n", node1->val, parent->val);
    }

}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);  // Visit the left subtree
        printf("%d ", root->val);  // Print the value of the current node
        inorder(root->right);  // Visit the right subtree
    }
}

int main(){
    ROOT = createNode(1);
    struct node* newNode1 = createNode(0);
    insertNode(newNode1);
    struct node* newNode2 = createNode(2);
    insertNode(newNode2);
    struct node* newNode3 = createNode(3);
    insertNode(newNode3);
    struct node* newNode4 = createNode(4);
    insertNode(newNode4);

    inorder(ROOT);
    


}