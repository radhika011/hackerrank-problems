/*

You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].

You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.

For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).
[3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
[5, 6, 3, 7] is not possible since it contains an element greater than 6.
[1, 2, 3, 4] is not possible since the differences are not correct.
Return the number of possible hidden sequences there are. If there are no possible sequences, return 0.


*/



typedef long long ll;
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        ll minPit = INT_MAX;
        ll dummy = 0;
        ll maxPeak = INT_MIN;
        for(int i = 0;i<n;i++){
            dummy+=differences[i];
            minPit = min(minPit,dummy);
            maxPeak = max(maxPeak,dummy);
        }
        
        ll upLower = lower-minPit;
        ll upUpper = upper-maxPeak;
        if(upLower<lower) upLower = lower;
        if(upUpper>upper) upUpper = upper;
        
        ll ans = upUpper-upLower+1;
        if(ans<0) return 0;
        return ans;
    }
};
