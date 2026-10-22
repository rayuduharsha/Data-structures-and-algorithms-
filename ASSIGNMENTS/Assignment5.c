#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}

void insertBeginning(int roll)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = head;
    head = newNode;

    printf("After insertion at beginning: ");
    display();
}

void insertEnd(int roll)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("After insertion at end: ");
    display();
}

void search(int roll)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("%d found in the list\n", roll);
            return;
        }

        temp = temp->next;
    }

    printf("%d not found in the list\n", roll);
}

void deleteRoll(int roll)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("%d not found in the list\n", roll);
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("After deletion: ");
    display();
}

int main()
{
    int n, roll, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &roll);
        insertEnd(roll);
    }

    while (1)
    {
        printf("\n1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;

            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteRoll(roll);
                break;

            case 5:
                printf("Current list: ");
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/* Enter number of students: 3
Enter roll numbers:
101
102
103
After insertion at end: 101 102 103

1. Insert Beginning
2. Insert End
3. Search
4. Delete
5. Display
6. Exit
Enter choice: 1
Enter roll number: 100
After insertion at beginning: 100 101 102 103

1. Insert Beginning
2. Insert End
3. Search
4. Delete
5. Display
6. Exit
Enter choice: 2
Enter roll number: 104
After insertion at end: 100 101 102 103 104

1. Insert Beginning
2. Insert End
3. Search
4. Delete
5. Display
6. Exit
Enter choice: 3
Enter roll number to search: 102
102 found in the list

1. Insert Beginning
2. Insert End
3. Search
4. Delete
5. Display
6. Exit
Enter choice: 4
Enter roll number to delete: 102
After deletion: 100 101 103 104

1. Insert Beginning
2. Insert End
3. Search
4. Delete
5. Display
6. Exit
Enter choice: 3
Enter roll number to search: 500
500 not found in the list

1. Insert Beginning
2. Insert End
3. Search
4. Delete
5. Display
6. Exit
Enter choice: 5
Current list: 100 101 103 104

1. Insert Beginning
2. Insert End
3. Search
4. Delete
5. Display
6. Exit
Enter choice: 6  */
