class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mymap;
        for(int i =0;i<nums.size();i++){
            mymap[nums[i]]++;
        }
        vector<pair<int,int>> freq;
        for(auto m:mymap){
            freq.push_back(m);
        }
        sort(freq.begin(),freq.end(),cmp);
        vector<int> result;
        for(auto f:freq){
            for(int i =0;i<f.second;i++){
            result.push_back(f.first);
            }
        }
        return result;
    }
};
