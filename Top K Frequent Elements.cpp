/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order


*/




//Sorting approach - O(N*logN)
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
//Heap - O(N*logK)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> counts;
        for(int i =0;i<n;i++){
            counts[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(auto it = counts.begin();it!=counts.end();it++){
            //cout<<it->first<<" "<<it->second<<endl;
            q.push({it->second,it->first});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
        
    }
};
//Bucket sorting - O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n+1,vector<int>(0,0));
        unordered_map<int,int> counts;
        for(int i =0;i<n;i++){
            counts[nums[i]]++;
        }
        for(auto it = counts.begin();it!=counts.end();it++){
            buckets[it->second].push_back(it->first);
        }
        vector<int> ans;
        int count = 0;
        for(int i = n;i>0;i--){
            if(buckets[i].size()!=0){
                ans.insert(ans.end(),buckets[i].begin(),buckets[i].end());
                count+=buckets[i].size();
            }
            if(count==k) break;
        }
        return ans;
    }
};
