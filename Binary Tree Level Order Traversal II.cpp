/*

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).



*/




class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        while(!q.empty()){
            queue<TreeNode*> dq;
            vector<int> curr;
            while(!q.empty()){
                TreeNode* popped = q.front();
                q.pop();
                curr.push_back(popped->val);
                if(popped->left!=NULL) dq.push(popped->left);
                if(popped->right!=NULL) dq.push(popped->right);
            }
            q = dq;
            ans.push_back(curr);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
