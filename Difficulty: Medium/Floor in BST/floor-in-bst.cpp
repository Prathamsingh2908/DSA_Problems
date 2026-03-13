/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findFloor(Node* root, int x) {
        
        int floor = -1;
        
        while(root){
            
            if(root->data == x){
                return root->data;
            }
            
            if(root->data < x){
                floor = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        
        return floor;
    }
};