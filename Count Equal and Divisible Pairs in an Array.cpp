/*
Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.



*/





class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i]!=nums[j]) continue;
                if((i*j)%k==0) ans++;
            }
        }
        return ans;
    }
};
