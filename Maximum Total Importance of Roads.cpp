/*


You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.

You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

Return the maximum total importance of all roads possible after assigning the values optimally.



*/








typedef long long ll;
class Solution {
public:
    
    
    static bool sorter(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.second==p2.second) return p1.first<p2.first;
        return p1.second<p2.second;
    }
    
    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int e = roads.size();
        unordered_map<int,int> degrees;
        for(int i = 0;i<n;i++){
            degrees[i] = 0;
        }
        for(int i =0;i<e;i++){
            int v1 = roads[i][0];
            int v2 = roads[i][1];
            degrees[v1]++;
            degrees[v2]++;
        }
        vector<pair<int,int>> importances;
        for(auto it = degrees.begin();it!=degrees.end();it++){
            importances.push_back({it->first,it->second});
        }
        sort(importances.begin(),importances.end(),sorter);
        unordered_map<int,int> cimp;
        for(int i = 0;i<importances.size();i++){
            cimp[importances[i].first] = i+1;
        }
        ll ans = 0;
        for(int i = 0;i<e;i++){
            int v1 = roads[i][0];
            int v2 = roads[i][1];
            ans+=cimp[v1];
            ans+=cimp[v2];
        }
        return ans;
    }
};
