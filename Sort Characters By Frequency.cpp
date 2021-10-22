class Solution {
public:
    static bool comp(pair<char,int>&v1,pair<char,int>&v2){
        if(v1.second>v2.second) return true;
        return false;
    }
    string frequencySort(string s) {
        map<char,int> rep;
        int n = s.size();
        for(int i =0;i<n;i++){
            char curr = s[i];
            if(rep.find(curr)!=rep.end()){
                rep.at(curr)+=1;
                continue;
            }
            rep.insert({curr,1});
        }
        vector<pair<char,int>> ans;
        for(auto it = rep.begin();it!=rep.end();it++){
            ans.push_back(make_pair((*it).first,(*it).second));
        }
        sort(ans.begin(),ans.end(),comp);
        string s2 = "";
        for(int i =0;i<ans.size();i++){
            for(int j =0;j<ans[i].second;j++){
                s2.push_back(ans[i].first);
            }
        }
        return s2;
    }
};
