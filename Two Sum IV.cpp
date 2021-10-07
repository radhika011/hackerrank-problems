class Solution {
public:
    void inorder(TreeNode* localRoot, vector<int>& inorderv){
        if(localRoot==NULL) return;
        inorder(localRoot->left,inorderv);
        inorderv.push_back(localRoot->val);
        inorder(localRoot->right,inorderv);
    }
    bool findTarget(TreeNode* root, int target) {
        vector<int> inorderv;
        inorder(root,inorderv);
        int i = 0;
        int j = inorderv.size()-1;
        int flag = false;
        while(i<j){
            int currSum = inorderv[i]+inorderv[j];
            if(currSum>target){
                j--;
            }
            else if(currSum<target){
                i++;
            }
            else{
                flag = true;
                break;
            }
        }
        return flag;
        
        
    }
};
