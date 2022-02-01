
/*
You are given a strictly increasing integer array rungs that represents the height of rungs on a ladder. You are currently on the floor at height 0, and you want to reach the last rung.

You are also given an integer dist. You can only climb to the next highest rung if the distance between where you are currently at (the floor or on a rung) and the next rung is at most dist. You are able to insert rungs at any positive integer height if a rung is not already there.

Return the minimum number of rungs that must be added to the ladder in order for you to climb to the last rung.


*/

typedef long long ll;
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        int ans = 0;
        rungs.insert(rungs.begin(), 0);      
        for(int i =0;i<n;i++){
            int currDiff = rungs[i+1]-rungs[i];
            int req = currDiff/dist;
            if(currDiff==dist) continue;
            if(currDiff%dist==0){
                ans+=(req-1);
                continue;
            }
            ans+=req;
        }
        return ans;
    }
};
