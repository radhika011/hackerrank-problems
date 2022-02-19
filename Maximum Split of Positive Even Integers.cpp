/*

You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
Return a list of integers that represent a valid split containing a maximum number of integers. If no valid split exists for finalSum, return an empty list. You may return the integers in any order.


*/





typedef long long ll;
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<ll> ans;
        if(finalSum%2!=0) return ans;
        ll curr = 2;
        ll rem = finalSum;
        while((rem-curr)>curr){
            ans.push_back(curr);
            rem-=curr;
            curr+=2;
        }
        if(rem!=0) ans.push_back(rem);
        return ans;
        
    }
};
