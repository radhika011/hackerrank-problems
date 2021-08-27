class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;
        while(row<matrix.size()){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row++;
            else break;
        }
        if(row==matrix.size()) return false;
        for(int i = matrix[0].size()-1;i>=0;i--){
            if(matrix[row][i]==target) return true;
            else if(matrix[row][i]<target) return false;
            
        }
        return false;
    }
};
