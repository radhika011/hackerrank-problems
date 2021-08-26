class Solution {
public:
    void helper(TreeNode* localRoot,vector<vector<int>> &ans,vector<int> currPath){
        if(localRoot==NULL) return;
        if(localRoot->left==NULL&&localRoot->right==NULL){
            currPath.push_back(localRoot->val);
            ans.push_back(currPath);
            return;
        }
        currPath.push_back(localRoot->val);
        helper(localRoot->left,ans,currPath);
        helper(localRoot->right,ans,currPath);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> currPath;
        helper(root,ans,currPath);
        int sum =0;
        for(int i = 0;i<ans.size();i++){
            int k = ans[i].size()-1;
            int curr = 0;
            for(int j = 0;j<ans[i].size();j++){
                curr += ans[i][j]*pow(2,k);
                k--;
            }
            sum+=curr;
        }
        return sum;
    }
};
