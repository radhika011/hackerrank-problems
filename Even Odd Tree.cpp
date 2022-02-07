/*

A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.


*/



class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int prev = -1;
            if(level%2!=0) prev = INT_MAX;
            else prev = INT_MIN;
            ///cout<<level<<" "<<n<<endl;
            for(int i = 0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
                if(level%2!=0){
                    if(curr->val%2!=0) return false;
                    if(curr->val>=prev) return false;
                }
                else{
                    if(curr->val%2==0) return false;
                    if(curr->val<=prev) return false;
                }
                prev = curr->val;
            }
            
            level++;
            
        }
        return true;
    }
};
