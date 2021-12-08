/*
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if there the node does not have a right child.


*/




class Solution {
public:
    
    int rec(TreeNode* localRoot,int& sumOfDiffs){
        if(localRoot==NULL) return 0;
        int lsum = rec(localRoot->left,sumOfDiffs);
        int rsum = rec(localRoot->right,sumOfDiffs);
        int currDiff = abs(lsum-rsum);
        sumOfDiffs+=currDiff;
        return localRoot->val+lsum+rsum;
    }
    
    
    int findTilt(TreeNode* root) {
        int ans = 0;
        rec(root,ans);
        return ans;
    }
};
