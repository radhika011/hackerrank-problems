
/*

Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.



*/




typedef long long ll;
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        ll curr = num-3;
        vector<ll> ans;
        if(curr%3!=0) return ans;
        ll n = curr/3;
        ans.push_back(n);
        ans.push_back(n+1);
        ans.push_back(n+2);
        return ans;
    }
};
