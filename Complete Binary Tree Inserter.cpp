/*

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the CBTInserter class:

CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
TreeNode get_root() Returns the root node of the tree.



*/





class CBTInserter {
public:
    queue<TreeNode*> q;
    TreeNode* root;
    CBTInserter(TreeNode* root) {
       
        this->root = root;
        queue<TreeNode*> dq;
        dq.push(root);
        while(!dq.empty()){
            TreeNode* curr = dq.front();
            dq.pop();
             q.push(curr);
             if(curr->left!=NULL) dq.push(curr->left);
             if(curr->right!=NULL) dq.push(curr->right);
            
        }
    }
    
    int insert(int val) {
        
        TreeNode* curr = q.front();
        if(curr->left==NULL){
            TreeNode* newNode = new TreeNode(val);
            curr->left = newNode;
            q.push(newNode);
            return curr->val;
        }
        else if(curr->right==NULL){
            TreeNode* newNode = new TreeNode(val);
            curr->right = newNode;
            q.push(newNode);
            return curr->val;
        }
        q.pop();
        return insert(val);
        
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
