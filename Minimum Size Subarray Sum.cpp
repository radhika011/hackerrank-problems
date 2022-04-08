/*

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.




*/






class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int currSum = 0;
        int ans = INT_MAX;
        while(end<n&&start<=end){
            int curr = nums[end];
            currSum+=curr;
            if(currSum>=target){
                ans = min(ans,end-start+1);
                while(currSum>=target){
                    ans = min(ans,end-start+1);
                    currSum-=nums[start];
                    start++;
                    
                }
            }
            end++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
