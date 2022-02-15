/*

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.




*/






class Solution {
public:
    TreeNode* root;
    
    int helper(TreeNode* curr,int currMax){
        if(curr==NULL) return 0;
        int counts = 0;
        if(curr->val>=currMax){
            currMax = curr->val;
            counts = 1;
        }
        int left = helper(curr->left,currMax);
        int right = helper(curr->right,currMax);
        //cout<<curr->val<<" "<<left<<" "<<right<<" "<<counts<<endl;
        return left+right+counts;
    }
    
    
    int goodNodes(TreeNode* root) {
        this->root = root;
        return helper(root,INT_MIN);
    }
};
