class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int m = points.size();
        //int n = points[0].size();
        vector<int> vec;
        for(int i =0;i<m;i++){
            vec.push_back(points[i][0]);
        }
        sort(vec.begin(),vec.end());
        int diff = INT_MIN;
        for(int i = 0;i<m-1;i++){
            if((vec[i+1]-vec[i])>diff){
                diff = vec[i+1]-vec[i];
            }
        }
        return diff;
    }
};
