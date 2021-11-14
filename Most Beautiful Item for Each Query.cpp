/*

You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the answer to the jth query.




*/
class Solution {
public:
    static bool cmp(vector<int> &a1,vector<int> &a2){
        if(a1[0]==a2[0]) return a1[1]>a2[1];
        return a1[0]<a2[0];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries1) {
        unordered_map<int,int> ans;
        sort(items.begin(),items.end(),cmp);
        vector<int> queries = queries1;
        sort(queries.begin(),queries.end());
        int itemInd = 0;
        int currQuery = 0;
        int maxTillNow = 0;
        while(currQuery<queries.size()&&itemInd<items.size()){
           
            while(items[itemInd][0]<=queries[currQuery]){
                if(items[itemInd][1]>maxTillNow) maxTillNow = items[itemInd][1];
                itemInd++;
                 if(itemInd>=items.size()) break;
                
            }
            ans.insert({queries[currQuery],maxTillNow});
            currQuery++;
        }
        while(currQuery!=queries.size()){
            ans.insert({queries[currQuery],maxTillNow});
            currQuery++;
        }
        vector<int> ans1;
        for(int i = 0;i<queries1.size();i++){
            ans1.push_back(ans[queries1[i]]);
        }
        return ans1;
    }
};
