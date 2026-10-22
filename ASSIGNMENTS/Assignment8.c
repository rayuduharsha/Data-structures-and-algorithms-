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

struct Node* findMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node *root, int value)
{
    struct Node *temp;

    if (root == NULL)
        return root;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

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

int main()
{
    struct Node *root = NULL;
    int n, value, deleteValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder before deletion: ");
    inorder(root);

    printf("\nEnter node to delete: ");
    scanf("%d", &deleteValue);

    if (root == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        root = deleteNode(root, deleteValue);

        printf("Inorder after deletion: ");
        inorder(root);
        printf("\n");
    }

    return 0;
}
/* Enter number of nodes: 7
Enter values:
50
30
70
20
40
60
80

Inorder before deletion: 20 30 40 50 60 70 80
Enter node to delete: 20
Inorder after deletion: 30 40 50 60 70 80

Enter number of nodes: 6
Enter values:
50
30
70
60
80
65

Inorder before deletion: 30 50 60 65 70 80
Enter node to delete: 60
Inorder after deletion: 30 50 65 70 80

Enter number of nodes: 7
Enter values:
50
30
70
20
40
60
80

Inorder before deletion: 20 30 40 50 60 70 80
Enter node to delete: 50
Inorder after deletion: 20 30 40 60 70 80 */