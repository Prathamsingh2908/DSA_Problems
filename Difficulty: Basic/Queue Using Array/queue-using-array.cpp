#include <iostream>

/**
 * Class: myQueue
 * Implementation of a Queue data structure using a circular array.
 * A queue follows the FIFO (First-In-First-Out) principle.
 */
class myQueue {
private:
    int* arr;      // Pointer to the array that stores queue elements
    int front;     // Index of the front element
    int rear;      // Index of the last element
    int size;      // Current number of elements in the queue
    int capacity;  // Maximum size of the queue

public:
    /**
     * Constructor to initialize the queue with a specific size.
     * @param n Maximum capacity of the queue.
     */
    myQueue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to free the allocated memory
    ~myQueue() {
        delete[] arr;
    }

    /**
     * Checks if the queue has no elements.
     * @return true if size is 0, false otherwise.
     */
    bool isEmpty() {
        return size == 0;
    }

    /**
     * Checks if the queue has reached its maximum capacity.
     * @return true if size equals capacity, false otherwise.
     */
    bool isFull() {
        return size == capacity;
    }

    /**
     * Adds an element x at the rear of the queue.
     * @param x The integer to be added.
     */
    void enqueue(int x) {
        if (isFull()) {
            return;
        }
        // Circular increment of rear index
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    /**
     * Removes the front element of the queue.
     */
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        // Circular increment of front index
        front = (front + 1) % capacity;
        size--;
    }

    /**
     * Returns the front element of the queue.
     * @return The front element, or -1 if the queue is empty.
     */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    /**
     * Returns the last element of the queue.
     * @return The rear element, or -1 if the queue is empty.
     */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    /**
     * Returns the current number of elements in the queue.
     */
    int getCurrentSize() {
        return size;
    }
};