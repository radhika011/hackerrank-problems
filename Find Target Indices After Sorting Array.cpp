
/*

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.


*/




class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        unordered_map<int,int> counts;
        int n = nums.size();
        int lessThan = 0;
        for(int i =0;i<n;i++){
            if(nums[i]<target) lessThan++;
            counts[nums[i]]++;
        }
        vector<int> ans;
        for(int i = 0;i<counts[target];i++){
            ans.push_back(lessThan++);
        }
        return ans;
    }
};
