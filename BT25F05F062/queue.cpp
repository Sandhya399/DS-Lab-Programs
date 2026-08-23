#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert an element into the circular queue
void enqueue()
{
    int value;

    // Check for Queue Overflow
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow! Circular Queue is full.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &value);

    // If queue is empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("%d inserted into the queue.\n", value);
}

// Delete an element from the circular queue
void dequeue()
{
    int value;

    // Check for Queue Underflow
    if (front == -1)
    {
        printf("Queue Underflow! Circular Queue is empty.\n");
        return;
    }

    value = queue[front];

    // If only one element is present
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("%d deleted from the queue.\n", value);
}

// Display all elements of the circular queue
void display()
{
    int i;

    // Check if queue is empty
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n----- CIRCULAR QUEUE -----\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}