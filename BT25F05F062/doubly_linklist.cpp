#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// 1. Insertion at Beginning
void insertBeginning()
{
    int value;
    struct Node *newNode;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("Node inserted at beginning.\n");
}

// 2. Insertion at Ending
void insertEnding()
{
    int value;
    struct Node *newNode, *temp;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    printf("Node inserted at ending.\n");
}

// 3. Deletion at Beginning
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    printf("Node deleted from beginning.\n");
}

// 4. Deletion at Ending
void deleteEnding()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    // If there is only one node
    if (temp->next == NULL)
    {
        head = NULL;
        free(temp);
        printf("Node deleted from ending.\n");
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    free(temp);

    printf("Node deleted from ending.\n");
}

// 5. Forward Traversal
void forwardTraversal()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward Traversal: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// 6. Backward Traversal
void backwardTraversal()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    // Go to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Backward Traversal: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Ending\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at Ending\n");
        printf("5. Forward Traversal\n");
        printf("6. Backward Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnding();
            break;

        case 3:
            deleteBeginning();
            break;

        case 4:
            deleteEnding();
            break;

        case 5:
            forwardTraversal();
            break;

        case 6:
            backwardTraversal();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}