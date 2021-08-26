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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> currPath;
        helper(root,ans,currPath);
        string s = "";
        vector<string> answer;
        for(int i = 0;i<ans.size();i++){
            s = "";
            for(int j = 0;j<ans[i].size();j++){
                s+=to_string(ans[i][j]);
                if(j<ans[i].size()-1) s+="->";
            }
            answer.push_back(s);
        }
        return answer;
    }
};
