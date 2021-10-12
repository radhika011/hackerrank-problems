//Normal Approach
class Solution {
public:
    int helper1(int i,int j,vector<int> curr){
        int max = i;
        for(int k =i;k<=j;k++){
            if(curr[k]>curr[max]) max = k;
        }
        return max;
    }
    TreeNode* helper2(int i, int j, vector<int> nums){
        //cout<<"Hello"<<endl;
        if(j<i||j>=nums.size()||i<0) return NULL;
        int maxInd = helper1(i,j,nums);
        TreeNode *localRoot = new TreeNode(nums[maxInd]);
        localRoot->left = helper2(i,maxInd-1,nums);
        localRoot->right = helper2(maxInd+1,j,nums);
        return localRoot;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper2(0,nums.size()-1,nums);
    }
};
//Monotonic Stack Approach
