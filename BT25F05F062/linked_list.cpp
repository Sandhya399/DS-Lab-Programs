#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode()
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning()
{
    struct Node *newNode;

    newNode = createNode();

    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Insert at ending
void insertEnding()
{
    struct Node *newNode, *temp;

    newNode = createNode();

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at ending.\n");
}

// Insert at a given position
void insertPosition()
{
    struct Node *newNode, *temp;
    int position, i;

    printf("Enter position: ");
    scanf("%d", &position);

    if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1)
    {
        insertBeginning();
        return;
    }

    newNode = createNode();

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

// Delete from beginning
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

    printf("%d deleted from beginning.\n", temp->data);

    free(temp);
}

// Delete from ending
void deleteEnding()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // If only one node
    if (head->next == NULL)
    {
        printf("%d deleted from ending.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("%d deleted from ending.\n", temp->data);

    free(temp);
}

// Delete from a given position
void deletePosition()
{
    struct Node *temp, *prev;
    int position, i;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &position);

    if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;

    printf("%d deleted from position %d.\n", temp->data, position);

    free(temp);
}

// Display the linked list
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n----- LINKED LIST -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at Ending\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Position\n");
        printf("6. Delete from Ending\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertPosition();
                break;

            case 3:
                insertEnding();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deletePosition();
                break;

            case 6:
                deleteEnding();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
