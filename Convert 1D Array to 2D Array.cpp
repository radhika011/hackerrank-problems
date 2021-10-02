class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> dummy;
        int k = 0;
        int lim = original.size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(k<lim) ans[i][j] = original[k++];
                else return dummy;
            }
        }
        if(k<lim) return dummy;
        return ans;
    }
};
