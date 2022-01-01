/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.





*/



class Solution {
public:
    void helper(TreeNode* curr,int &gmin,int currHeight){
        if(curr==NULL) return;
        currHeight+=1;
        if(curr->right==NULL&&curr->left==NULL){
            gmin = min(gmin,currHeight);
            return;
        }
        helper(curr->left,gmin,currHeight);
        helper(curr->right,gmin,currHeight);
        
        
    }
    
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int gmin = INT_MAX;
        helper(root,gmin,0);
        return gmin;
    }
};
