/*

You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:

Sort the values at odd indices of nums in non-increasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
Sort the values at even indices of nums in non-decreasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
Return the array formed after rearranging the values of nums.




*/




class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even;
        vector<int> odd;
        for(int i =1;i<n;i+=2){
            odd.push_back(nums[i]);
        }
        sort(odd.begin(),odd.end(),greater<int>());
        for(int i =0;i<n;i+=2){
            even.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        int j = 0;
             int k = 0;
        for(int i =0;i<n;i++){
            if(i%2==0) nums[i] = even[j++];
            else nums[i] = odd[k++];
        }
        return nums;
    }
};
