
/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).




*/



class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL) return ans;
        while(!q.empty()){
            queue<TreeNode*> dq;
            int maxVal = INT_MIN;
            while(!q.empty()){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL) dq.push(curr->left);
                if(curr->right!=NULL) dq.push(curr->right);
                if(curr->val>maxVal){
                    maxVal = curr->val;
                }
            }
            q = dq;
            ans.push_back(maxVal);
        }
        return ans;
    }
};
