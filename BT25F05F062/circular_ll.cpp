
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

// Insertion at start
void insertStart() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (last == NULL) {
        last = newnode;
        newnode->next = newnode;
    } else {
        newnode->next = last->next;
        last->next = newnode;
    }

    printf("Node inserted at start.\n");
}

// Insertion at end
void insertEnd() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (last == NULL) {
        last = newnode;
        newnode->next = newnode;
    } else {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }

    printf("Node inserted at end.\n");
}

// Deletion at start
void deleteStart() {
    struct node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (last == temp) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    free(temp);
    printf("Node deleted from start.\n");
}

// Deletion at end
void deleteEnd() {
    struct node *temp, *prev;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (last == temp) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last->next) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = last->next;
        free(last);
        last = prev;
    }

    printf("Node deleted from end.\n");
}

// Display the list
void display() {
    struct node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to start)\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insertion at Start\n");
        printf("2. Insertion at End\n");
        printf("3. Deletion at Start\n");
        printf("4. Deletion at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStart();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteStart();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
