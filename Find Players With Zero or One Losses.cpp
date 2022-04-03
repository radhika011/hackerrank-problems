/*

You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.



*/




class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        vector<int> indegree(100000,0);
        vector<int> outdegree(100000,0);
        vector<int> played(100000,0);
        vector<int> ans1;
        vector<int> ans2;
        vector<vector<int>> ans;
        int maxNumber = 0;
        for(int i =0;i<n;i++){
            int from = matches[i][0];
            int to = matches[i][1];
            indegree[to-1]++;
            outdegree[from-1]++;
            maxNumber = max(max(maxNumber,from),to);
            played[from-1]++;
            played[to-1]++;
        }
       
        for(int i =0;i<maxNumber;i++){
            if(indegree[i]==0&&played[i]!=0) ans1.push_back(i+1);
            if(indegree[i]==1&&played[i]!=0) ans2.push_back(i+1);
        }
         //cout<<"help"<<endl;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
