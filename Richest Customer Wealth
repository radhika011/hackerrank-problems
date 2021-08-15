class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth =0;
        int maxWealth = 0;
        for(int i=0;i<accounts.size();i++){
            int currWealth = 0;
            for(int j= 0;j<accounts[0].size();j++){
                currWealth+=accounts[i][j];
            }
            if(currWealth>maxWealth){
                maxWealth = currWealth;
            }
        }
        return maxWealth;
        
        
    }
};
