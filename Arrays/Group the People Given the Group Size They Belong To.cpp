class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        int k =0;
        vector<vector<int>> vec(n+1);
        for(int i =0;i<n;i++){
            int group = groupSizes[i];
            vec[group].push_back(i);
            if(vec[group].size()==group){
                ans.push_back(vec[group]);
                vec[group].clear();
            }
        }
        return ans;
    }
};
