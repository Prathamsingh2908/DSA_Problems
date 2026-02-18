#include <iostream>

/**
 * Class: myStack
 * Implementation of a Stack data structure using a fixed-size array (dynamically allocated).
 * A stack follows the LIFO (Last-In-First-Out) principle.
 */
class myStack {
private:
    int* arr;      // Pointer to the array that stores stack elements
    int top;       // Index of the top element (-1 means stack is empty)
    int capacity;  // Maximum size of the stack

public:
    /**
     * Constructor to initialize the stack with a specific size.
     * @param n Maximum capacity of the stack.
     */
    myStack(int n) {
        capacity = n;
        arr = new int[capacity];
        top = -1; // Initialize top to -1 to signify an empty stack
    }

    // Destructor to free the allocated memory
    ~myStack() {
        delete[] arr;
    }

    /**
     * Checks if the stack has no elements.
     * @return true if top is -1, false otherwise.
     */
    bool isEmpty() {
        return top == -1;
    }

    /**
     * Checks if the stack has reached its maximum capacity.
     * @return true if top is at the last index, false otherwise.
     */
    bool isFull() {
        return top == capacity - 1;
    }

    /**
     * Inserts an element at the top of the stack.
     * @param x The integer to be pushed.
     */
    void push(int x) {
        if (isFull()) {
            // In a production environment, you might throw an exception here
            return;
        }
        arr[++top] = x; // Increment top first, then insert
    }

    /**
     * Removes the element from the top of the stack.
     */
    void pop() {
        if (isEmpty()) {
            // In a production environment, you might throw an exception here
            return;
        }
        top--; // Simply decrement top to "remove" the element
    }

    /**
     * Returns the current top element of the stack without removing it.
     * @return The top element, or -1 if the stack is empty.
     */
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }

    /**
     * Returns the current number of elements in the stack.
     */
    int size() {
        return top + 1;
    }
};