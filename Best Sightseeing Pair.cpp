
/*
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.



*/



class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> dp(n,0);
        dp[0] = values[0];
        for(int i =1;i<n;i++){
            int curr = values[i]+i;
            dp[i] = max(dp[i-1],curr);
        }
        int maximum = INT_MIN;
        for(int i = 1;i<n;i++){
            int curr = dp[i-1]+(values[i]-i);
            maximum = max(maximum,curr);
        }
        return maximum;
    }
};
