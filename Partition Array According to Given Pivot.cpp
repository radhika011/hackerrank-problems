
/*
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
Return nums after the rearrangement.



*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> lessThan;
        int count = 0;
        vector<int> moreThan;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]==pivot) count++;
            else if(nums[i]<pivot) lessThan.push_back(nums[i]);
            else moreThan.push_back(nums[i]);
        }
        for(int i = 0;i<lessThan.size();i++){
            ans.push_back(lessThan[i]);
        }
        for(int i = 0;i<count;i++){
            ans.push_back(pivot);
        }
        for(int i = 0;i<moreThan.size();i++){
            ans.push_back(moreThan[i]);
        }
        return ans;
        
        
        
        
        
    }
};
