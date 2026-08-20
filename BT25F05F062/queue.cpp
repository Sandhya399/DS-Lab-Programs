#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor to initialize the queue with a specific size
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if the queue is full
    bool isFull() {
        // Condition 1: Rear wraps around right behind front
        // Condition 2: Front is at 0 and Rear is at the last index
        return ((rear + 1) % capacity == front);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert an element into the queue (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow: Cannot insert " << value << ". Queue is full.\n";
            return;
        }

        // If inserting the very first element
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            // Circularly increment rear index
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        cout << "Inserted: " << value << "\n";
    }

    // Remove an element from the queue (Dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: Cannot delete. Queue is empty.\n";
            return -1;
        }

        int deletedValue = arr[front];

        // If the queue has only one element left, reset pointers
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Circularly increment front index
            front = (front + 1) % capacity;
        }

        return deletedValue;
    }

    // Display all elements of the circular queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity; // Circular traversal
        }
        cout << "\n";
    }
};

int main() {
    // Create a circular queue capable of holding 5 elements
    CircularQueue q(5);

    // Enqueue 5 elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    q.display();

    // Trying to insert into a full queue (Should trigger overflow)
    q.enqueue(60);

    // Dequeue 2 elements
    cout << "Dequeued: " << q.dequeue() << "\n";
    cout << "Dequeued: " << q.dequeue() << "\n";

    q.display();

    // Enqueue new elements to demonstrate circular reuse of empty space
    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
