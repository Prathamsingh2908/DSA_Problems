#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Class: maxHeap
 * Description: A standard implementation of a Max-Heap data structure.
 * A Max-Heap is a complete binary tree where the value of the root node 
 * is greater than or equal to the values of its children.
 */
class maxHeap {
private:
    // Vector to store heap elements
    std::vector<int> heap;

    /**
     * Helper: heapifyUp
     * Moves the element at the given index up to its correct position
     * to maintain the Max-Heap property.
     */
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    /**
     * Helper: heapifyDown
     * Moves the element at the given index down to its correct position
     * to maintain the Max-Heap property.
     */
    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            // Check if left child is larger than current largest
            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }

            // Check if right child is larger than current largest
            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }

            // If the largest is not the current index, swap and continue
            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    /**
     * Inserts an element x into the heap.
     * Time Complexity: O(log N)
     */
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    /**
     * Removes the top (maximum) element from the heap.
     * If the heap is empty, it does nothing.
     * Time Complexity: O(log N)
     */
    void pop() {
        if (heap.empty()) return;

        // Replace the root with the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Restore heap property from the root
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    /**
     * Returns the maximum element in the heap.
     * Returns -1 if the heap is empty.
     * Time Complexity: O(1)
     */
    int peek() {
        if (heap.empty()) {
            return -1;
        }
        return heap[0];
    }

    /**
     * Returns the current number of elements in the heap.
     * Time Complexity: O(1)
     */
    int size() {
        return heap.size();
    }
};