/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

idk why this q is rated medium

*/




class Solution {
public:
    vector<vector<int>> ans;
    int n;
    vector<int> nums;
    void helper(vector<int> arr,int curr){
        if(curr==n){
            ans.push_back(arr);
            return;
        }
        helper(arr,curr+1);
        arr.push_back(nums[curr]);
        helper(arr,curr+1);
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        this->n = n;
        this->nums = nums;
        helper({},0);
        return ans;
    }
};
