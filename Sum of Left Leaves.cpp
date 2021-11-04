class Solution {
public:
    int rec(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL) return rec(root->right);
        int scalc = 0;
        if(root->left->left==NULL&&root->left->right==NULL) scalc = root->left->val;
        return scalc+rec(root->left)+rec(root->right);
    }
    
    
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        return rec(root);
    }
};
