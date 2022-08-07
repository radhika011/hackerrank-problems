
/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.




*/





class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> op1(n,1);
        vector<int> ans(n,1);
        int prod = nums[0];
        for(int i =1;i<n;i++){
            op1[i] = prod;
            prod*=nums[i];
        }
        prod = nums[n-1];
        for(int i =n-2;i>=0;i--){
            ans[i] = prod*op1[i];
            prod*=nums[i];
        }
        ans[n-1] = op1[n-1];
        return ans;
        
    }
};
