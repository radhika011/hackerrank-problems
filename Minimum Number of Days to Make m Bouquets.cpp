/*

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.



*/






class Solution {
public:
    
    
    bool check(vector<int>& bloomDay,int days,int& m,int &k){
        int n = bloomDay.size();
        int currSize = 0;
        int count = m;
        for(int i = 0;i<n;i++){
            if(bloomDay[i]<=days){
                currSize++;
                if(currSize==k){
                    count--;
                    if(count==0) return true;
                    currSize = 0;
                }
            }
            else{
                currSize = 0;
            }
            //cout<<currSize<<" ";
        }
        //cout<<endl;
        return false;
    }
    
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int minLen = m*k;
        if(n<minLen) return -1;
        int low = 1;
        int high = 1;
        int ans = INT_MAX;
       // cout<<check(bloomDay,12,m,k)<<endl;
        for(int i = 0;i<n;i++){
            high = max(high,bloomDay[i]);
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(check(bloomDay,mid,m,k)){
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
