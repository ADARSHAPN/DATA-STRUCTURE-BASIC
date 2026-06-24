#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create new node
struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Preorder Traversal
void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal
void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    // Creating Binary Tree
    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Traversals
    printf("Preorder Traversal:\n");
    preorder(root);

    printf("\n\nInorder Traversal:\n");
    inorder(root);

    printf("\n\nPostorder Traversal:\n");
    postorder(root);

    return 0;
}
