/*

You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.




*/








typedef long long ll;
class Solution {
public:
    
    
    int find(ll spell,vector<int>& potions,int& m,ll& success,int&n){
        int low = 0;
        int high = m-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (high+low)/2;
            if((spell*potions[mid])>=success){
                high = mid-1;
                ans = min(ans,mid);
            }
            else{
                low= mid+1;
            }
            //cout<<mid<<endl;
        }
        if(ans==INT_MAX) return 0;
        return n-ans;
    }
    
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        for(int i = 0;i<n;i++){
          
            ll spell = spells[i];
            int pairs = find(spell,potions,m,success,m);
            ans.push_back(pairs);
        }
        return ans;
    }
};
