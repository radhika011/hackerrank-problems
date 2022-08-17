

/*

Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

TC : O(n)



*/









class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int total = 0;
        for(int i =0;i<n;i++){
            prefix[i] = total;
            total+=nums[i];
        }
        total = 0;
        for(int i = n-1;i>=0;i--){
            suffix[i] = total;
            total+=nums[i];
            
        }
        for(int i = 0;i<n;i++){
            if(prefix[i]==suffix[i]) return i;
        }
        return -1;
    }
};
