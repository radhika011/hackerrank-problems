#include<bits/stdc++.h>
void dfs(vector<vector<char>> &characterMatrix,vector<vector<bool>> visited,int sind,string& word,vector<vector<pair<int,int>>>& fin,vector<pair<int,int>> ind,int i,int j){
	if(sind==word.size()){
    	fin.push_back(ind);
        return;
    }
    int m = characterMatrix.size();
    int n = characterMatrix[0].size();
    if(i>=0&&j>=0&&i<m&&j<n&&visited[i][j]!=true){
    	visited[i][j] = true;
    	if(word[sind]==characterMatrix[i][j]){
        	
           
            ind.push_back({i,j});
        	dfs(characterMatrix,visited,sind+1,word,fin,ind,i-1,j-1);
            if(sind+1==word.size()) {
            return;
            }
            dfs(characterMatrix,visited,sind+1,word,fin,ind,i-1,j);
            dfs(characterMatrix,visited,sind+1,word,fin,ind,i-1,j+1);
            dfs(characterMatrix,visited,sind+1,word,fin,ind,i,j-1);
            dfs(characterMatrix,visited,sind+1,word,fin,ind,i,j+1);
            dfs(characterMatrix,visited,sind+1,word,fin,ind,i+1,j-1);
            dfs(characterMatrix,visited,sind+1,word,fin,ind,i+1,j);
            dfs(characterMatrix,visited,sind+1,word,fin,ind,i+1,j+1);
        }
        //visited[i][j] = false;
    }
	return;
}



void findOccurrences( vector<vector<char>> &characterMatrix, string &word, int m, int n){
    // Write your code here.
    bool flag = false;
    for(int i =0;i<m;i++){
    	for(int j =0;j<n;j++){
        if(characterMatrix[i][j]==word[0]){
        	vector<vector<bool>> visited(m,vector<bool>(n,false));
            vector<pair<int,int>> ind;
            vector<vector<pair<int,int>>> fin;
            dfs(characterMatrix,visited,0,word,fin,ind,i,j);
           for(int k = 0;k<fin.size();k++){
           flag = true;
           for(int r = 0;r<word.size();r++){
           		//cout<<fin[i].size()<<endl;
           		cout<<"'"<<word[r]<<"'("<<fin[k][r].first<<", "<<fin[k][r].second<<")";
                if(r!=word.size()-1) cout<<" ";
           }
           
           cout<<endl;
           }
           
          }
        }
      }  
    if(!flag) cout<<"No match found"<<endl;
    
    }
    
    
