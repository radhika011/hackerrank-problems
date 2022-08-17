/*


Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

TC: O(n)



*/










class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int neg = 0;
        int totalSum = 0;
        int maximum = INT_MIN;
        for(int i =0;i<n;i++){
            if(nums[i]<0) neg++;
            else pos++;
            totalSum+=nums[i];
            maximum = max(maximum,nums[i]);
            
        }
        if(pos==n) return totalSum;
        if(neg==n) return maximum;
        int lsum = nums[0];
        int gsum = nums[0];
        int lmin = nums[0];
        int gmin = nums[0];
        
        
        
        
        for(int i =1;i<n;i++){
            if(lsum+nums[i]<nums[i]){
                lsum = nums[i];
            }
            else{
                lsum += nums[i];
            }
            
            if(lmin+nums[i]>nums[i]){
                lmin = nums[i];
            }
            else{
                lmin += nums[i];
            }
            gmin = min(gmin,lmin);
            gsum = max(gsum,lsum);
        }
        //cout<<gsum<<endl;
        //cout<<totalSum<<" "<<gmin<<endl;
        return max(gsum,totalSum-gmin);
    
    }
};
