
/*
A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.

Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.
Labelled: Hard (and now you know why)

Bro idgaf if Microsoft doesn't want me, i'm simply NOT writing 120 lines of code for a problem EVER AGAIN. 

*/



class Solution {
public:
    int m,n;
    
    
    int dfs(vector<vector<int>>& isInfected,int i,int j,vector<vector<bool>>& visited,int& perimeter){
        if(i<0||j<0||i>=m||j>=n||isInfected[i][j]==2) return 0;
        if(isInfected[i][j]==1&&visited[i][j]==1) return 0;
       
        if(isInfected[i][j]!=1&&visited[i][j]==1){
            perimeter+=1;
            return 0;
        }
        if(isInfected[i][j]!=1){
            perimeter+=1;
            visited[i][j] = true;
            return 1;
            
        }
        visited[i][j] = true;
        return dfs(isInfected,i+1,j,visited,perimeter)+dfs(isInfected,i-1,j,visited,perimeter)+dfs(isInfected,i,j+1,visited,perimeter)+dfs(isInfected,i,j-1,visited,perimeter);
    }
    void freeAllZeros(vector<vector<bool>>& visited,vector<vector<int>>& isInfected){
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isInfected[i][j]!=1) visited[i][j] = false;
            }
        }
    }
    int numberOfConnected(vector<vector<int>> isInfected,map<pair<int,int>,pair<int,int>>& threats){
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        //cout<<"new"<<endl;
        int counter = 0;
        for(int i = 0;i<isInfected.size();i++){
            for(int j = 0;j<isInfected[0].size();j++){
                if(isInfected[i][j]==1&&!visited[i][j]){
                    int perimeter = 0;
                    int threat = dfs(isInfected,i,j,visited,perimeter);
                   //cout<<i<<j<<threat<<perimeter<<endl;
                    threats[{i,j}] = {threat,perimeter};
                    counter++;
                    freeAllZeros(visited,isInfected);
                }
            }
        }
        return counter;
    }
    
    void quarantineIt(int i,int j,vector<vector<bool>>& visited,vector<vector<int>>& isInfected){
        if(i<0||j<0||i>=m||j>=n||visited[i][j]||isInfected[i][j]!=1||isInfected[i][j]==2) return;
        visited[i][j] = true;
        isInfected[i][j] = 2;
        quarantineIt(i+1,j,visited,isInfected);
         quarantineIt(i-1,j,visited,isInfected);
         quarantineIt(i,j+1,visited,isInfected);
         quarantineIt(i,j-1,visited,isInfected);
        
        
    }
    void spreadIt(int i,int j,vector<vector<bool>>& visited,vector<vector<int>>& isInfected){
         if(i<0||j<0||i>=m||j>=n||visited[i][j]||isInfected[i][j]==-1||isInfected[i][j]==2) return;
        visited[i][j] = true;
        if(isInfected[i][j]!=1){
            isInfected[i][j]=-1;
            return;
        }
        spreadIt(i+1,j,visited,isInfected);
        spreadIt(i-1,j,visited,isInfected);
        spreadIt(i,j+1,visited,isInfected);
        spreadIt(i,j-1,visited,isInfected);
        
        
        
    }
    
    int containVirus(vector<vector<int>>& isInfected) {
        this->m = isInfected.size();
        this->n = isInfected[0].size();
        int no = -1;
        int popn = m*n;
        int ans = 0;
       
        while(true){
            map<pair<int,int>,pair<int,int>> threats;
             int no = numberOfConnected(isInfected,threats);
            if(no==0) return ans;
            int maxThreat = INT_MIN;
            pair<int,int> area;
            int maxPeri = -1;
            for(auto it = threats.begin();it!=threats.end();it++){
                if(maxThreat<(it->second).first){
                    maxThreat = (it->second).first;
                    area = it->first;
                    maxPeri = (it->second).second;
                }
            }
            if(maxThreat==0) return ans;
            ans+=maxPeri;
            vector<vector<bool>> visited(m,vector<bool>(n,false));
            quarantineIt(area.first,area.second,visited,isInfected);
            vector<vector<bool>> visited1(m,vector<bool>(n,false));
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    if(isInfected[i][j]==1) spreadIt(i,j,visited1,isInfected);
                }
            }
            for(int i =0;i<m;i++){
                for(int j = 0;j<n;j++){
                    if(isInfected[i][j]==-1) isInfected[i][j] = 1;
                }
            }
            
        }
        
        return ans;
        
        
    }
};
