
/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


*/



class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<TreeNode*> q;
        q.push_back(root);
        int level = 0;
        while(!q.empty()){
            level++;
            reverse(q.begin(),q.end());
            vector<TreeNode*> curr;
            vector<int> part;
            for(int i =0;i<q.size();i++){
                part.push_back(q[i]->val);
                 if(level%2!=0){
                if(q[i]->left!=NULL) curr.push_back(q[i]->left);
                if(q[i]->right!=NULL) curr.push_back(q[i]->right);
                 }
                else{
                     if(q[i]->right!=NULL) curr.push_back(q[i]->right);
                    if(q[i]->left!=NULL) curr.push_back(q[i]->left);
               
                }               
            }
            q = curr;
            ans.push_back(part);
        }
        return ans;
    }
};
