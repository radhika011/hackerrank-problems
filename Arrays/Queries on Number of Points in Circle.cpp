class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int q = queries.size();
        int p = points.size();
        vector<int> ans;
        for(int i =0;i<q;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            int count = 0;
            for(int j =0;j<p;j++){
                int xj = points[j][0];
                int yj = points[j][1];
                int lhs = pow(xj-x,2)+pow(yj-y,2);
                int rhs = pow(r,2);
                if(lhs<=rhs) count++; 
            }
            ans.push_back(count);
            
        }
        return ans;
    }
};
