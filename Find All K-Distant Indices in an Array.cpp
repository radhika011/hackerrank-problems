/*
You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order.



*/




class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int curr = nums[i];
            for(int j = 0;j<n;j++){
                if(abs(i-j)>k) continue;
                if(nums[j]==key){
                    ans.push_back(i);
                    break;
                }
            }
        }
        
        
        
        
        return ans;
    }
};
