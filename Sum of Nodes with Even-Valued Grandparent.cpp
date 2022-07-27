/*
Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.







*/







class Solution {
public:
    
    void getSum(TreeNode* localRoot,int& ans){
        if(localRoot==NULL) return;
        if(localRoot->val%2!=0){
            getSum(localRoot->left,ans);
            getSum(localRoot->right,ans);
            return;
        }
        if(localRoot->left!=NULL&&localRoot->left->left!=NULL) ans+= localRoot->left->left->val;
        if(localRoot->left!=NULL&&localRoot->left->right!=NULL) ans+= localRoot->left->right->val;
        if(localRoot->right!=NULL&&localRoot->right->left!=NULL) ans += localRoot->right->left->val;
        if(localRoot->right!=NULL&&localRoot->right->right!=NULL) ans += localRoot->right->right->val;
        getSum(localRoot->left,ans);
        getSum(localRoot->right,ans);    
    }
    
    
    
    
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        getSum(root,ans);
        return ans;
    }
};
