/*

Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:

Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.



*/







class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        int odd = 0;
        vector<int> temp = nums;
        for(int i = 0;i<n;i+=2){
           
            if((i-1)>=0&&nums[i-1]>=nums[i]){
                even+=(nums[i-1]-(nums[i]-1));
                nums[i-1] = nums[i]-1;
            }
            if((i+1)<n&&nums[i+1]>=nums[i]){
                even+=(nums[i+1]-(nums[i]-1));
                nums[i+1] = nums[i]-1;
            }
        }
        nums= temp;
        for(int i = 1;i<n;i+=2){
           if((i-1)>=0&&nums[i-1]>=nums[i]){
                odd+=(nums[i-1]-(nums[i]-1));
                nums[i-1] = nums[i]-1;
            }
            if((i+1)<n&&nums[i+1]>=nums[i]){
                odd+=(nums[i+1]-(nums[i]-1));
                nums[i+1] = nums[i]-1;
            }
            //cout<<nums[i]<<" "<<even<<endl;
        }
        return min(even,odd);
        
    }
};
