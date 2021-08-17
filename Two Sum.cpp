class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int comp = target-nums[i];
            if(umap.find(comp)!=umap.end()){
                ans.push_back(umap.at(comp));
                ans.push_back(i);
                return ans;
            }
            umap.insert({nums[i],i}); 
        }
        return ans;
    }
};
