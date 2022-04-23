/*
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.



*/




class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        sort(nums.begin(),nums.end());
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==k){
                ans+=1;
                i++;
                j--;
                continue;
            }
            if(sum<k){
                i++;
                continue;
            }
            j--;
        }
        return ans;
    }
};
