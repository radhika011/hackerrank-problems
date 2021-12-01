
/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



*/



class Solution {
public:
    int helper(vector<int> nums,int curr){
        if(curr<=0) return 0;
        int option1 = nums[curr-1]+helper(nums,curr-2);
        int option2 = helper(nums,curr-1);
        return max(option1,option2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        for(int i = 1;i<=n;i++){
            int option1 = nums[i-1];
            if(i-2>=0) option1+=dp[i-2];
            int option2 = dp[i-1];
            dp[i] = max(option1,option2);
        }
        return dp[n];
    }
};
