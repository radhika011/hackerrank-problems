
/*

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

*/


//O(n^2) soln.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        vector<int> dp(n,1);
        for(int i =0;i<n;i++){
            int curr = nums[i];
            int maxPossible = 0;
            for(int j = i-1;j>=0;j--){
                if(nums[j]<curr){
                    maxPossible = max(maxPossible,dp[j]);
                }
            }
            dp[i] = 1+maxPossible;
            //cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};
