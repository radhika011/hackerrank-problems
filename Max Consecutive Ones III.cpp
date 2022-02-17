/*

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.


*/




class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int rem = k;
        int j = 0;
        int ans = INT_MIN;
        for(;j<n;j++){
            
            if(nums[j]==0) rem--;
             while(rem<0){
                if(nums[i]==0) rem++;
                i++;
            }
             ans = max(ans,j-i+1);
            
           
            
        }
        return ans;
    }
};
