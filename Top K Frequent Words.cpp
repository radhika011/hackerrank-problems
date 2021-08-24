class Solution {
public:
    static bool cmp(pair<string,int> &a,pair<string,int> &b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> myMap;
        for(int i =0;i<words.size();i++){
            myMap[words[i]]++;
        }
        map<string,int>:: iterator itr;
        vector<pair<string,int>> freq;
        for(itr = myMap.begin();itr!=myMap.end();itr++){
            freq.push_back(make_pair(itr->first,itr->second));
        }
        sort(freq.begin(),freq.end(),cmp);
        vector<string> ans;
        for(int i = 0;i<k;i++){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};
