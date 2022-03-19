/*
You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.



*/




class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> counts;
        for(int i = 0;i<n;i++){
            counts[nums[i]]++;
        }
        for(auto it = counts.begin();it!=counts.end();it++){
            if(it->second%2!=0){
                return false;
            }
        }
        return true;
    }
};
