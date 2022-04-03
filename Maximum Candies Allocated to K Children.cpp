/*
You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can take at most one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.



*/





typedef long long ll;
class Solution {
public:
    vector<int> candies;
    ll k;
    bool check(int mid){
        ll count = 0;
        if(mid==0) return false;
        for(int i =0;i<candies.size();i++){
            count+=(candies[i]/mid);
        }
        if(count>=k) return true;
        return false;
        
    }
    
    
    
    
    
    
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxCandies = 0;
        this->candies = candies;
        this->k = k;
       
        for(int i =0;i<n;i++){
            maxCandies = max(maxCandies,candies[i]);
        }
        double low = 0;
        double high = maxCandies;
        ll lastSat = 0;
        cout<<low<<" "<<high<<endl;
        while(high>=low){
            ll mid = ceil((high+low)/2);
           // cout<<mid<<endl;
            if(check(mid)==true){
                lastSat = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return lastSat;
        
        
        
    }
};
