class Solution {
public:
    void rec(TreeNode* root,int currSum,int &totalSum){
        if(root==NULL) return;
        currSum*=10;
        currSum+=root->val;
        if(root->left==NULL&&root->right==NULL){
            totalSum+=currSum;
            return;
        }
        rec(root->left,currSum,totalSum);
        rec(root->right,currSum,totalSum);
    }
    
    int sumNumbers(TreeNode* root) {
        int currSum = 0;
        int totalSum = 0;
        rec(root,currSum,totalSum);
        return totalSum;
    }
};
