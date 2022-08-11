/*

You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).







*/



class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int sum = 0;
        for(int i =0;i<n;i++){
            int curr = nums[i];
            prefix[i] = sum;
            sum+=nums[i];
        }
       
        sum = 0;
        for(int i =n-1;i>=0;i--){
            suffix[i] = sum;
            sum+=nums[i];
        }
        
        for(int i =0;i<n;i++){
            int curr = nums[i];
            int rightSum = suffix[i] - ((n-i)-1)*curr;
            int leftSum = (i*curr) - prefix[i];
            ans.push_back((rightSum+leftSum));
        }
        
        
        return ans;
    }
};
