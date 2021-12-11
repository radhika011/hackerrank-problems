/*
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

BFS




*/





typedef long long ll;
class Solution {
public:
    
   
    
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int,vector<int>> graph;
        for(int i = 0;i<n;i++){
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r = bombs[i][2];
            for(int j = 0;j<n;j++){
               // if(i==j) continue;
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                ll res = pow((x2-x1),2)+pow((y2-y1),2);
                 //cout<<x2<<" "<<y2<<" "<<res<<endl;
                if(res<=pow(r,2)){
                    //cout<<res<<" "<<i<<" "<<j<<endl;
                    graph[i].push_back(j);
                    
                }
            }
        }
        int maxSize = INT_MIN;
        for(int i =0;i<n;i++){
            queue<int> q;
            int count = 0;
            q.push(i);
            vector<bool> visited(n,false); 
            visited[i] = true;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                count++;
                for(int i = 0;i<graph[curr].size();i++){
                    if(!visited[graph[curr][i]]) q.push(graph[curr][i]);
                    visited[graph[curr][i]] = true;
                }
            }
            if(count>maxSize){
                maxSize = count;
            }
            
            
            
        }
        
        return maxSize;
    }
};
