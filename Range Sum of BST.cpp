/*
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].




*/





class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int curr = root->val;
        int lsum = 0;
        int rsum =0;
        if(curr<low){
            rsum += rangeSumBST(root->right,low,high);
            return rsum;
        }
        else if(curr>high){
            lsum+=rangeSumBST(root->left,low,high);
            return lsum;
        }
        else{
            rsum += rangeSumBST(root->right,low,high);
            lsum+=rangeSumBST(root->left,low,high);
        }
       // cout<<curr<<" "<<lsum<<" "<<rsum<<endl;
        return curr+lsum+rsum;
        
    }
};
