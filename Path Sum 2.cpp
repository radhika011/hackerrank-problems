class Solution {
public:
    void helper(vector<vector<int>> &ans, TreeNode* localRoot,vector<int> currPath,int currSum,int targetSum){
        if(localRoot==NULL) return;
        currSum+=localRoot->val;
        currPath.push_back(localRoot->val);
        if(localRoot->left==NULL&&localRoot->right==NULL){
            if(currSum==targetSum){
                ans.push_back(currPath);
                return;
            }
        }
        helper(ans,localRoot->left,currPath,currSum,targetSum);
        helper(ans,localRoot->right,currPath,currSum,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int currSum =0;
        vector<int> currPath;
        helper(ans,root,currPath,currSum,targetSum);
        return ans;
    }
};
