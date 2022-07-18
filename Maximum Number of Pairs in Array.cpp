/*

You are given a 0-indexed integer array nums. In one operation, you may do the following:

Choose two integers in nums that are equal.
Remove both integers from nums, forming a pair.
The operation is done on nums as many times as possible.

Return a 0-indexed integer array answer of size 2 where answer[0] is the number of pairs that are formed and answer[1] is the number of leftover integers in nums after doing the operation as many times as possible.





*/






class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2,0);
        unordered_map<int,int> umap;
        for(int i =0;i<n;i++){
            umap[nums[i]] += 1;
        }
        for(auto it = umap.begin();it!=umap.end();it++){
             int pairs = (it->second)/2;
             int leftovers = (it->second)%2;
             ans[0]+=pairs;
            ans[1]+=leftovers;
            
        }
        
        
        
        
        
        return ans;
    }
};
