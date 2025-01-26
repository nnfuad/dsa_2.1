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
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;
    return newNode;
}

int main(){

}