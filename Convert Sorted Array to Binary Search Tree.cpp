/*

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.




*/





class Solution {
public:
    
    vector<int> nums;
   
    TreeNode* rec(int first, int last){
        if(first>last){
            return NULL;
        }
        int mid = (first+last)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = rec(first,mid-1);
        newNode->right = rec(mid+1,last);
        return newNode;
    }
    
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        return rec(0,n-1);
    }
};
