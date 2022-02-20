/*
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.




*/




class Solution {
public:
    static bool comp(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.first==p2.first) return p1.second>p2.second;
        return p1.first<p2.first;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> vec;
        int n = intervals.size();
        for(int i =0;i<n;i++){
            vec.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(vec.begin(),vec.end(),comp);
        int curr = 0;
        int ans = 0;
        int prevA = INT_MAX;
        int prevB = INT_MAX;
            while(curr<n){
            int currA = vec[curr].first;
            int currB = vec[curr].second;
            curr++;
            //cout<<prevA<<" "<<prevB<<endl;;
            //cout<<currA<<" "<<currB<<endl;;
            if(prevA<=currA&&currB<=prevB) continue;
            prevA = currA;
            prevB = currB;
            ans+=1;
            //cout<<ans<<endl;
        }
        return ans;
    }
};
