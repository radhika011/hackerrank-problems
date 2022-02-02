/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).





*/




class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(10001,-1);
        vector<int> prefix(n,0);
        int currSum = 0;
        for(int i =0;i<n;i++){
            prefix[i] = currSum+nums[i];
            currSum+=nums[i];
            //cout<<prefix[i]<<" ";
        }
        int start =0;
        int end = 0;
        int ans = INT_MIN;
       while(end<n){
           int curr = nums[end];
           if(hash[curr]!=-1){
               start = max(hash[curr]+1,start);
           }
           hash[curr] = end;
           int currSum = prefix[end];
           if(start>0) currSum=(prefix[end]-prefix[start-1]);
           ans = max(ans,currSum);
           end++;
       }
        
        return ans;
        
    }
};
