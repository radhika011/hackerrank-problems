/*
You are given a 0-indexed integer array nums. An index i is part of a hill in nums if the closest non-equal neighbors of i are smaller than nums[i]. Similarly, an index i is part of a valley in nums if the closest non-equal neighbors of i are larger than nums[i]. Adjacent indices i and j are part of the same hill or valley if nums[i] == nums[j].

Note that for an index to be part of a hill or valley, it must have a non-equal neighbor on both the left and right of the index.

Return the number of hills and valleys in nums.



*/




class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int curr = nums[i];
            //cout<<nums[i]<<endl;
            int j = i-1;
            for(;j>=0&&nums[j]==nums[i];j--);
            if(j==-1) continue;
            int k = i+1;
            for(;k<n&&nums[k]==nums[i];k++);
            if(k==n) continue;
            //cout<<nums[j]<<" "<<nums[k]<<endl;
            if(nums[j]<nums[i]&&nums[k]<nums[i]) ans++;
            if(nums[j]>nums[i]&&nums[k]>nums[i]) ans++;
            i = k-1;
        }
        return ans;
    }
};
