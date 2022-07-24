

/*


Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

*/




typedef long long ll;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> sizes;
        ll currZero = 0;
        bool streak = false;
        for(ll i=0;i<n;i++){
            if(streak&&nums[i]!=0){
                sizes.push_back(currZero);
                currZero = 0;
            }
            else if(nums[i]==0){
                streak = true;
                currZero++;
            }
        }
        if(streak){
            sizes.push_back(currZero);
        }
        ll ans = 0;
        for(int i =0;i<sizes.size();i++){
            //cout<<sizes[i]<<" ";
            ans+=(sizes[i]*(sizes[i]+1))/2;
        }
        //cout<<endl;
        return ans;
    }
};
