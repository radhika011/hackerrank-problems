/*

You have n flower seeds. Every seed must be planted first before it can begin to grow, then bloom. Planting a seed takes time and so does the growth of a seed. You are given two 0-indexed integer arrays plantTime and growTime, of length n each:

plantTime[i] is the number of full days it takes you to plant the ith seed. Every day, you can work on planting exactly one seed. You do not have to work on planting the same seed on consecutive days, but the planting of a seed is not complete until you have worked plantTime[i] days on planting it in total.
growTime[i] is the number of full days it takes the ith seed to grow after being completely planted. After the last day of its growth, the flower blooms and stays bloomed forever.
From the beginning of day 0, you can plant the seeds in any order.

Return the earliest possible day where all seeds are blooming.





*/






typedef long long ll;
class Solution {
public:
    
    
    
    static bool sorter(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.second==p2.second){
            return p1.first>p2.first;
        }
        return p1.second>p2.second;
    }
    
    bool check(vector<pair<int,int>>& pairs,int days){
        int n = pairs.size();
        int curr = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            curr += pairs[i].first;
            ans = max(ans,curr+pairs[i].second);
        }
        if(ans<=days) return true;
        return false;
        
        
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> pairs;
        for(int i = 0;i<n;i++){
            pairs.push_back({plantTime[i],growTime[i]});
        }
        sort(pairs.begin(),pairs.end(),sorter);
        int low = 1;
        int high = 1;
        for(int i =0;i<n;i++){
            high +=plantTime[i]+growTime[i];
        }
        int ans = INT_MAX;
        while(low<=high){
            int mid = (high-low)/2+(low);
            if(check(pairs,mid)){
                high = mid-1;
                ans = min(ans,mid);
            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};
