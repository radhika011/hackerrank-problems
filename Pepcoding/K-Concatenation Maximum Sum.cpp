/*

Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 109 + 7.




*/








typedef long long ll;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
       int n = arr.size();
        int pos = 0;
        int neg = 0;
        ll totalSum = 0;
        int mod = pow(10,9)+7;
         vector<ll> prefix(n,0);
        vector<ll> suffix(n,0);
        ll pmax = 0;
        ll smax = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]<0) neg++;
            else pos++;
            totalSum+=arr[i];
            prefix[i] = totalSum;
            pmax = max(pmax,prefix[i]);
        }
        int ssum = 0;
        for(int i = n-1;i>=0;i--){
            ssum += arr[i];
            suffix[i] = ssum;
            smax = max(smax,suffix[i]);
        }
        if(neg==n) return 0;
        if(pos==n){
            return (totalSum*k)%mod;
        }
        ll lsum = 0;
        ll gsum = 0;
       
        if(totalSum<0){
       
        for(int i = 0;i<2;i++){
            for(int j =0;j<n;j++){
                if(lsum+arr[j]<arr[j]){
                    lsum = arr[j];
                }
                else{
                    lsum+=arr[j];
                }
                gsum = max(gsum,lsum);
            }
             if(k==1) return gsum;
        }
        }
        else{
            return (pmax+smax+(k-2)*(totalSum))%mod;
        }
        return gsum;
    }
};
