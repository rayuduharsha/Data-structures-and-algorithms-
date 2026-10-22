#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct Node *root, int value)
{
    if (root == NULL)
        return 0;

    if (root->data == value)
        return 1;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int main()
{
    struct Node *root = NULL;
    int n, value, searchValue;

    printf("Enter number of values: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n\nEnter value to search: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue))
        printf("%d exists in the BST\n", searchValue);
    else
        printf("%d does not exist in the BST\n", searchValue);

    return 0;
}

/* Enter number of values: 7
Enter values:
50
30
70
20
40
60
80

Inorder: 20 30 40 50 60 70 80
Preorder: 50 30 20 40 70 60 80
Postorder: 20 40 30 60 80 70 50

Enter value to search: 60
60 exists in the BST

Enter value to search: 100
100 does not exist in the BST

Inorder traversal produces sorted values because in a BST:
Left subtree < Root < Right subtree.
Therefore, Inorder (Left → Root → Right) gives values in ascending order. */