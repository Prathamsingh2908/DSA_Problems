/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
public:
    int isSumProperty(Node* root) {
        if (!root) return 1;
        if (!root->left && !root->right) return 1; // leaf node
        
        int leftVal = root->left ? root->left->data : 0;
        int rightVal = root->right ? root->right->data : 0;
        
        if (root->data != leftVal + rightVal) return 0;
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};