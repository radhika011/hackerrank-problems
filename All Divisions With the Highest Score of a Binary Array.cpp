/*

You are given a 0-indexed binary array nums of length n. nums can be divided at index i (where 0 <= i <= n) into two arrays (possibly empty) numsleft and numsright:

numsleft has all the elements of nums between index 0 and i - 1 (inclusive), while numsright has all the elements of nums between index i and n - 1 (inclusive).
If i == 0, numsleft is empty, while numsright has all the elements of nums.
If i == n, numsleft has all the elements of nums, while numsright is empty.
The division score of an index i is the sum of the number of 0's in numsleft and the number of 1's in numsright.

Return all distinct indices that have the highest possible division score. You may return the answer in any order.

*/


class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        int ones = 0;
        for(int i =0;i<n;i++){
            if(nums[i]==1){
                ones++;
            }
        }
        dp[0] = ones;
        int maximum = dp[0];
        for(int i =1;i<=n;i++){
            if(nums[i-1]==0){
                dp[i] = dp[i-1]+1;
                
            }
            else{
                ones--;
                dp[i] = dp[i-1]-1;
            }
            maximum = max(maximum,dp[i]);
        }
        vector<int> ans;
        for(int i =0;i<=n;i++){
            if(dp[i]==maximum){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
