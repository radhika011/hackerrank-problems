class Solution {
public:
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i =0;i<m;i++){
            vector<int> curr;
            int k = i;
            int l = 0;
            while(k<m&&l<n){
                //cout<<k<<" "<<l<<endl;
                curr.push_back(mat[k][l]);
                k++;
                l++;
            }
            sort(curr.begin(),curr.end());
            k = i;
            l=0;
            int ind = 0;
            while(k<m&&l<n&&ind<curr.size()){
                ans[k][l] = curr[ind++]; 
                k++;
                l++;
            }
            
        }
        
        
        for(int i =0;i<n;i++){
            vector<int> curr;
            int k = 0;
            int l = i;
            while(k<m&&l<n){
                curr.push_back(mat[k][l]);
                k++;
                l++;
            }
            sort(curr.begin(),curr.end());
            k = 0;
            l=i;
            int ind = 0;
            while(k<m&&l<n&&ind<curr.size()){
                ans[k][l] = curr[ind++]; 
                k++;
                l++;
            }
        }
        
        
        return ans;
        
        
        
    }
};
