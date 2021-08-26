class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        for(int i =0;i<edges.size();i++){
            int n = edges[i][1];
            visited[n] = true;
        }
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(visited[i]==false) ans.push_back(i);
        }
        return ans;
    }
};
