/*

There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.


Simple degree calculation









*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int nroads = roads.size();
        unordered_map<int,int> degrees;
        for(int i =0;i<nroads;i++){
            degrees[roads[i][0]]++;
            degrees[roads[i][1]]++;
        }
        vector<vector<int>> matrix(n,vector<int>(n,0));
        for(int i =0;i<nroads;i++){
            matrix[roads[i][0]][roads[i][1]] = 1;
            matrix[roads[i][1]][roads[i][0]] = 1;
        }
        int maxRank = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i!=j){
                    int rank = degrees[i]+degrees[j]-matrix[i][j];
                    maxRank = max(maxRank,rank);
                }
            }
        }
        return maxRank;
    }
};
