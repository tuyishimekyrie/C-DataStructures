#include <stdio.h>
#include <stdlib.h>

struct dataNode
{
    int data;
    struct dataNode *left;
    struct dataNode *right;
};

struct dataNode *createdataNode(int value)
{
    struct dataNode *newdataNode = (struct dataNode *)malloc(sizeof(struct dataNode));
    newdataNode->data = value;
    newdataNode->left = NULL;
    newdataNode->right = NULL;
    return newdataNode;
}

void preorderTrav(struct dataNode *root)
{
    if (root == NULL){
        return;
    }else{

    // printf("%d",root.data);
    printf("%d ", root->data);

    preorderTrav(root->left);

    preorderTrav(root->right);
    }
}

int main()
{

    struct dataNode *root = createdataNode(1);
    root->left = createdataNode(2);
    root->right = createdataNode(3);
    root->left->left = createdataNode(4);
    root->left->right = createdataNode(5);
    root->right->left = createdataNode(6);
    root->right->right = createdataNode(7);

    printf("Pre-order traversal of the binary tree: ");
    preorderTrav(root);
    printf("\n");

    return 0;
}