#define INF 99999
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMatrix(n+1,vector<int>(n+1,0));
        int m = edges.size();
       
        for(int i =0;i<m;i++){
             adjMatrix[edges[i][0]][edges[i][1]] = edges[i][2]; 
            adjMatrix[edges[i][1]][edges[i][0]] = edges[i][2]; 
            
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(adjMatrix[i][j]==0&&i!=j){
                    adjMatrix[i][j] =INF;
                }
            }
        }
        
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k =0;k<n;k++){
                     adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]); //important
                }
            }
        }
        
        int min = INT_MAX;
        int ans =0;
        for(int i =0;i<n;i++){
            int cityCount = 0;
            for(int j =0;j<n;j++){
                if(adjMatrix[i][j]!=INT_MAX&&adjMatrix[i][j]<=distanceThreshold){
                    cityCount++;
                }
            }
            if(cityCount<=min){
                min = cityCount;
                ans =i;
            }
           
        }
        return ans;
    }
};
