class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> myMap;
        for(int i =0;i<nums.size();i++){
            myMap[nums[i]]++;
        }
        vector<pair<int,int>> freq;
        map<int,int>::iterator itr;
        for(itr = myMap.begin();itr!=myMap.end();itr++){
            freq.push_back(make_pair(itr->first,itr->second));
        }
        sort(freq.begin(),freq.end(),cmp);
        vector<int> ans;
        for(int i =0;i<k;i++){
            ans.push_back(freq[i].first);
        }
        return ans;
        
    }
};
