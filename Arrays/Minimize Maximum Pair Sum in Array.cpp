class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int start = 0;
        int end = nums.size()-1;
        int max = INT_MIN;
        while(start<end){
            int curr = nums[start++]+nums[end--];
            if(curr>max) max = curr;
        }
        return max;
    }
};
