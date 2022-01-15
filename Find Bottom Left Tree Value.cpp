
/*

Given the root of a binary tree, return the leftmost value in the last row of the tree.

*/



class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lhs = -1;
        while(!q.empty()){
            lhs = q.front()->val;
            int n = q.size();
            for(int i =0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            
            
            
        }
        return lhs;
    }
};
