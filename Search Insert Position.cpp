class Solution {
public:
    int helper(int start,int end,vector<int> nums,int target){
        int mid = (start+end)/2;
        if(start<end){
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target&&nums[mid+1]>target) return mid+1;
            else if(nums[mid]>target&&nums[mid-1]<target) return mid;
            else if(nums[mid]>target) return helper(start,mid,nums,target);
            else return helper(mid+1,end,nums,target);
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0]) return 0;
        else if(target>nums[nums.size()-1]) return nums.size();
        int ans = helper(0,nums.size(),nums,target);
        return ans;
    }
};
