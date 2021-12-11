class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       int temp = k;
        vector<pair<int,int>> cache;
        for(int i =0;i<nums.size();i++){
            cache.push_back({nums[i],i});
        }
        sort(cache.begin(),cache.end());
        vector<pair<int,int>> pairs;
        for(int i = nums.size()-1;temp!=0;temp--,i--){
            pairs.push_back({cache[i].second,cache[i].first});
        }
        vector<int> ans;
        sort(pairs.begin(),pairs.end());
        for(int i = 0;i<pairs.size();i++){
            ans.push_back(pairs[i].second);
        }
        return ans;
    }
};
