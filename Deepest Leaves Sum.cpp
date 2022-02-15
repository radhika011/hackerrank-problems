
/*
Given the root of a binary tree, return the sum of values of its deepest leaves.



*/




class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int currSum = 0;
        while(!q.empty()){
            int n = q.size();
            currSum = 0;
            for(int i = 0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
                currSum+=curr->val;
            }
        }
        return currSum;
    }
};
