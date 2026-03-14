class Solution {
public:
    int findCeil(Node* root, int x) {
        int ceil = -1;
        
        while (root != NULL) {
            if (root->data == x) {
                return x;  // Found exact match
            }
            else if (root->data > x) {
                ceil = root->data;  // Current could be ceil
                root = root->left;  // Try to find smaller value >= x
            }
            else {
                root = root->right;  // Go right if current < x
            }
        }
        
        return ceil;
    }
};