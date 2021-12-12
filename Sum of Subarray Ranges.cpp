
/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.


Linear soln possible - Monotonic stack

*/

typedef long long ll;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0; 
        for(int i =0;i<n;i++){
            ll min_so_far = nums[i];
            ll max_so_far = nums[i];
            for(int j =i+1;j<n;j++){
                if(nums[j]>max_so_far){
                    max_so_far = nums[j];
                }
                else if(nums[j]<min_so_far){
                    min_so_far = nums[j];
                }
                ll currRange = max_so_far-min_so_far;
                sum+=currRange;
            }
        }
        return sum;
    }
};
