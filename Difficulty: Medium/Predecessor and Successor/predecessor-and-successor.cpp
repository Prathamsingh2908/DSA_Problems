class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;
        
        while(curr){
            
            if(curr->data < key){
                pre = curr;
                curr = curr->right;
            }
            else if(curr->data > key){
                suc = curr;
                curr = curr->left;
            }
            else{
                
                // predecessor = rightmost of left subtree
                if(curr->left){
                    Node* temp = curr->left;
                    while(temp->right)
                        temp = temp->right;
                    pre = temp;
                }
                
                // successor = leftmost of right subtree
                if(curr->right){
                    Node* temp = curr->right;
                    while(temp->left)
                        temp = temp->left;
                    suc = temp;
                }
                
                break;
            }
        }
        
        return {pre, suc};
    }
};