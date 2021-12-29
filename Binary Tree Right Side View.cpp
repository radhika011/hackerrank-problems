
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

SIMPLE BFS



*/



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        TreeNode* ptr = root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if(root==NULL) return ans;
        ans.push_back(root->val);
        while(!q.empty()){
            queue<TreeNode*> dq;
            while(!q.empty()){
                TreeNode* curr = q.front();
                q.pop();
                //cout<<curr->val<<endl;
                if(curr->left!=NULL) dq.push(curr->left);
                if(curr->right!=NULL) dq.push(curr->right);
            }
            
            if(!dq.empty()){
                
                ans.push_back(dq.back()->val);
            }
            q= dq;
        }
        return ans;
        
    }
};
