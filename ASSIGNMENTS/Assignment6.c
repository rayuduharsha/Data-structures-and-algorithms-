#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void insertPage(char page[])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        current = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Page inserted: %s\n", page);
}

void moveForward()
{
    if (current == NULL)
    {
        printf("No pages available\n");
    }
    else if (current->next == NULL)
    {
        printf("Already at the last page\n");
    }
    else
    {
        current = current->next;
        printf("Moved forward to: %s\n", current->page);
    }
}

void moveBackward()
{
    if (current == NULL)
    {
        printf("No pages available\n");
    }
    else if (current->prev == NULL)
    {
        printf("Already at the first page\n");
    }
    else
    {
        current = current->prev;
        printf("Moved backward to: %s\n", current->page);
    }
}

void deletePage(char page[])
{
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Page not found: %s\n", page);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp)
    {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    printf("Page deleted: %s\n", page);
    free(temp);
}

void displayForward()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("No pages available\n");
        return;
    }

    printf("First to Last: ");

    while (temp != NULL)
    {
        printf("%s", temp->page);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

void displayBackward()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("No pages available\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Last to First: ");

    while (temp != NULL)
    {
        printf("%s", temp->page);

        if (temp->prev != NULL)
            printf(" <-> ");

        temp = temp->prev;
    }

    printf("\n");
}

int main()
{
    int choice;
    char page[50];

    while (1)
    {
        printf("\n1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter page name: ");
                scanf("%s", page);
                insertPage(page);
                break;

            case 2:
                moveForward();
                break;

            case 3:
                moveBackward();
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);
                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/* 1. Insert Page
2. Move Forward
3. Move Backward
4. Delete Page
5. Display First to Last
6. Display Last to First
7. Exit
Enter choice: 1
Enter page name: Google
Page inserted: Google

Enter choice: 1
Enter page name: YouTube
Page inserted: YouTube

Enter choice: 1
Enter page name: Wikipedia
Page inserted: Wikipedia

Enter choice: 5
First to Last: Google <-> YouTube <-> Wikipedia

Enter choice: 6
Last to First: Wikipedia <-> YouTube <-> Google

Enter choice: 2
Moved forward to: YouTube

Enter choice: 2
Moved forward to: Wikipedia

Enter choice: 2
Already at the last page

Enter choice: 3
Moved backward to: YouTube

Enter choice: 3
Moved backward to: Google

Enter choice: 3
Already at the first page

Enter choice: 4
Enter page to delete: YouTube
Page deleted: YouTube

Enter choice: 5
First to Last: Google <-> Wikipedia

Enter choice: 6
Last to First: Wikipedia <-> Google

Enter choice: 4
Enter page to delete: Facebook
Page not found: Facebook

Enter choice: 7 */