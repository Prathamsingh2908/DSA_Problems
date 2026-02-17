#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    // Helper struct to store element value and its position in the matrix
    struct Node {
        int val;
        int row;
        int col;

        // Custom comparator for min-heap
        bool operator>(const Node& other) const {
            return val > other.val;
        }
    };

public:
    /**
     * Merges K sorted arrays into a single sorted vector.
     * Logic:
     * 1. Use a Min-Heap to keep track of the smallest current element among all arrays.
     * 2. Initialize heap with the first element of each array.
     * 3. Repeatedly extract the minimum and add the next element from that same array.
     */
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int k = mat.size();
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        // Step 1: Initialize heap with the first element of each of the K arrays
        for (int i = 0; i < k; i++) {
            if (!mat[i].empty()) {
                pq.push({mat[i][0], i, 0});
            }
        }

        vector<int> result;

        // Step 2: Extract min and push the next element from the same row
        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            result.push_back(current.val);

            // If there's a next element in the same array, add it to the heap
            if (current.col + 1 < mat[current.row].size()) {
                pq.push({
                    mat[current.row][current.col + 1], 
                    current.row, 
                    current.col + 1
                });
            }
        }

        return result;
    }
};