/*
You are given a 0-indexed integer array nums. The array nums is beautiful if:

nums.length is even.
nums[i] != nums[i + 1] for all i % 2 == 0.
Note that an empty array is considered beautiful.

You can delete any number of elements from nums. When you delete an element, all the elements to the right of the deleted element will be shifted one unit to the left to fill the gap created and all the elements to the left of the deleted element will remain unchanged.

Return the minimum number of elements to delete from nums to make it beautiful.



*/





class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i =0;i<n-1;i+=2){
            if(nums[i]==nums[i+1]){
                while(i<n-1&&nums[i]==nums[i+1]){
                    ans+=1;
                    i++;
                }
            }
            //cout<<ans<<endl;
            
        }
        if(n%2!=0&&ans%2==0) ans++;
        else if(n%2==0&&ans%2!=0) ans++;
        return ans;
    }
};
