/*

You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 3.75, which truncates to 3.




*/




typedef long long ll;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        ll sum = 0;
        ll div = 2*k+1;
        if(n<(2*k+1)) return ans;
        if(k==0) return nums;
        cout<<n<<endl;
        for(int i =0;i<=(2*k);i++){
            sum+=nums[i];
        }
        int centre = k;
        int curr = sum/div;
        ans[centre] = curr;
        for(int end = (2*k)+1;end<n;end++){
            sum+=nums[end];
            sum-=nums[end-(2*k)-1];
            int curr = sum/div;
            ans[++centre] = curr; 
        }
        return ans;
    }
};
