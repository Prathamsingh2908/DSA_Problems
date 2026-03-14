/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int count = 0;
        int ans = -1;

        while (curr) {

            if (curr->left == NULL) {
                count++;
                if (count == k)
                    ans = curr->val;

                curr = curr->right;
            } 
            else {
                TreeNode* pred = curr->left;

                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                } 
                else {
                    pred->right = NULL;

                    count++;
                    if (count == k)
                        ans = curr->val;

                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};