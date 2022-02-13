/*
You are given an array of positive integers beans, where each integer represents the number of magic beans found in a particular magic bag.

Remove any number of beans (possibly none) from each bag such that the number of beans in each remaining non-empty bag (still containing at least one bean) is equal. Once a bean has been removed from a bag, you are not allowed to return it to any of the bags.

Return the minimum number of magic beans that you have to remove.



*/





typedef long long ll;
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        ll ans = LLONG_MAX;
        ll sumUpto = 0;
        vector<ll> ends(n,0);
        sort(beans.begin(),beans.end());
        ends[n-1] = beans[n-1];
        for(int i = n-2;i>=0;i--){
            ends[i]=ends[i+1]+beans[i];
        }
        for(int i = 0;i<n-1;i++){
            ll diffs = 0;
            ll rem = n-(i+1);
            diffs+=(ends[i+1]-(beans[i]*rem));
            ll curr = diffs+sumUpto;
            ans = min(ans,curr);
            sumUpto+=beans[i];
        }
        ans = min(ans,sumUpto);
        return ans;
    }
};
