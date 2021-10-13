class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int m = logs.size();
        set<pair<int,int>> uset;
         
        for(int i =0;i<m;i++){
            
            uset.insert({logs[i][0],logs[i][1]});
        }
        set<pair<int,int>>::iterator it = uset.begin();
        //vector<int> ans(k,0);
        map<int,int> umap;
        while(it!=uset.end()){
            
            int user = (*it).first;
            int min = (*it).second;
            //cout<<user<<min<<endl;
            if(umap.find(user)!=umap.end()){
               umap[user]++;
            }
            umap.insert({user,1});
            it++;
        }
         
        vector<int> ans(k,0);
        auto it1 = umap.begin();
        while(it1!=umap.end()){
            ans[(*it1).second-1]+=1;
            it1++;
        }
        return ans;
        
    }
};
