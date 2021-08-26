class Solution {
public:
    bool helper(TreeNode* localRoot,int currSum,int targetSum){
        if(localRoot==NULL){
            return false;
        }
        currSum += localRoot->val;
        if(localRoot->left==NULL&&localRoot->right==NULL){
            if(currSum==targetSum){
                return true;
            }
            else{
                return false;
            }
        }
        if(localRoot->right==NULL) return helper(localRoot->left,currSum,targetSum);
        else if(localRoot->left==NULL) return helper(localRoot->right,currSum,targetSum);
        return helper(localRoot->left,currSum,targetSum)||helper(localRoot->right,currSum,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        bool ans = helper(root,currSum,targetSum);
        return ans;
    }
};
