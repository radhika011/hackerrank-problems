class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p;
        int n = queries.size();
        for(int i = 0;i<m;i++){
            p.push_back(i+1);
        }
        vector<int> ans;
        for(int i =0;i<n;i++){
            int curr = queries[i];
            int j = 0;
            for(;j<m;j++){
                if(p[j]==curr) break;
            }
            ans.push_back(j);
            remove(p.begin(),p.end(),curr);
            p.insert(p.begin(),curr);
        }
        return ans;
    }
};
