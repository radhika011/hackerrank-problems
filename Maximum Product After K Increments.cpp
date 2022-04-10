/*
You are given an array of non-negative integers nums and an integer k. In one operation, you may choose any element from nums and increment it by 1.

Return the maximum product of nums after at most k operations. Since the answer may be very large, return it modulo 109 + 7.




*/






typedef long long ll;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        int mod = pow(10,9)+7;
        priority_queue<ll,vector<ll>,greater<ll>> q;
        for(int i =0;i<n;i++){
            q.push(nums[i]);
        }
        while(k!=0){
            ll curr = q.top();
            q.pop();
            curr+=1;
            //cout<<curr<<endl;
            q.push(curr);
            k--;
        }
        ll ans = 1;
        while(!q.empty()){
            ll curr = q.top()%mod;
            
            ans = (ans*curr)%mod;
            q.pop();
        }
        return ans%mod;
    }
};
