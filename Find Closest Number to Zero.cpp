
/*
Given an integer array nums of size n, return the number with the value closest to 0 in nums. If there are multiple answers, return the number with the largest value.



*/




class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int minDiff = INT_MAX;
        int val = 0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            int currDiff = abs(nums[i]);
            if(currDiff<=minDiff){
                minDiff = currDiff;
                val = nums[i];
            }
        }
        return val;
    }
};
