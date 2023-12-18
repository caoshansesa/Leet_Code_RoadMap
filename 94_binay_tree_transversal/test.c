#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int value;
} Binary_tree;

Binary_tree* create_node(int value) {
    Binary_tree* root = (Binary_tree*)malloc(sizeof(Binary_tree));
    root->left = NULL;
    root->right = NULL;
    root->value = value;
    return root;
}

Binary_tree* insert(Binary_tree* root, int value) {
    if(root == NULL) {
        root = create_node(value);
    } else if (root->value > value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int main() {
    Binary_tree* root = NULL;
    root = insert(root, 3);
    root = insert(root, 8); 
    root = insert(root, 1);
    root = insert(root, 4);

    printf("Value in root node: %d\n", root->value);
    printf("Value in left child node: %d\n", root->left->value);
    printf("Value in right child node: %d\n", root->right->value);
    printf("Binary tree created and values inserted successfully\n");

    return 0;
}