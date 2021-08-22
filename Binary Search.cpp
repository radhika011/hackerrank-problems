class Solution {
public:
    int binSearch(int start,int end,vector<int> nums,int target){
        if(start<end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                return binSearch(mid+1,end,nums,target);
            }
            return binSearch(start,mid,nums,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int ans = binSearch(0,nums.size(),nums,target);
        return ans;
    }
};
