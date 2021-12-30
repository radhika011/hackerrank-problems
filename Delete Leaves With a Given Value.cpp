/*
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).



*/




class Solution {
public:
    
    void helper(int target,TreeNode* parent,TreeNode* curr,char ch){
        if(curr==NULL) return;
        
        helper(target,curr,curr->left,'L');
        helper(target,curr,curr->right,'R');
        
        if(curr->val==target&&curr->left==NULL&&curr->right==NULL){
            if(ch=='L') parent->left = NULL;
            else parent->right = NULL;
            return;
        }
        
    }
    
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        helper(target,root,root->left,'L');
        helper(target,root,root->right,'R');
        if(root->val==target&&root->left==NULL&&root->right==NULL){
            return NULL;
        }
        return root;
    }
};
