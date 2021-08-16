class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int primarySum = 0;
        for(int i=0;i<mat.size();i++){
            primarySum+=mat[i][i];
        }
        int k = mat.size()-1;
        int secondarySum =0;
        for(int j=0;j<mat.size();j++){
            secondarySum+=mat[j][k--];
        }
        int size = mat.size();
        if(size%2==0){
            return primarySum+secondarySum;
        }
        return primarySum+secondarySum-mat[size/2][size/2];
        
    }
};
