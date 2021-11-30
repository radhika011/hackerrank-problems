/*

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.




*/


class Solution {
public:
    
   
    int getAbsParent(int v,vector<int>& parent){
        if(parent[v]==-1) return v;
        return parent[v] = getAbsParent(parent[v],parent);
    }
    
    
    void unionize(int x,int y, vector<int>& parent,vector<int>& rank){
        int p1 = getAbsParent(x,parent);
        int p2 = getAbsParent(y,parent);
        if(p1==p2) return;
        if(rank[p1]>rank[p2]){   //attach p2 to p1
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2]){  //attach p1 to p2
            parent[p1] = p2;
        }
        else{
            parent[p1] = p2; 
            rank[p2]+=1;
        }
    }
    
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> emailGroup;
        int n = accounts.size();
         vector<int> parent(n,-1);
            vector<int> rank(n,0);
        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string curr = accounts[i][j];
                if(emailGroup.find(curr)==emailGroup.end()){
                    emailGroup[curr] = i;
                    continue;
                }
                unionize(emailGroup[curr],i,parent,rank);
            }
        }
        unordered_map<int,vector<string>> components;
        for(auto emailIterator: emailGroup){
            string curr = emailIterator.first;
            int currInd = emailIterator.second;
            int p = getAbsParent(currInd,parent);
            components[p].push_back(curr);
        }
        vector<vector<string>> ans;
        for(auto comps:components){
            vector<string> curr;
            curr.push_back(accounts[comps.first][0]);
            for(int i = 0;i<comps.second.size();i++){
                curr.push_back(comps.second[i]);
            }
            sort(curr.begin()+1,curr.end());
            ans.push_back(curr);
            
            
        }
        
        return ans;
        
        
    }
};
