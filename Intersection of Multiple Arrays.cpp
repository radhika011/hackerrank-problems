/*


Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.


*/





class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int,int> umap;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<nums[i].size();j++){
                umap[nums[i][j]]++;
            }
        }
        vector<int> ans;
        for(auto it = umap.begin();it!=umap.end();it++){
            if(it->second>=n){
                ans.push_back(it->first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
