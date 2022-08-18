/*


Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



*/








class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        
        unordered_map<int,int> first_occ;
        int curr_sum = 0;
        for(int i =0;i<n;i++){
            int curr = nums[i];
            if(curr==0){
                curr_sum-=1;
            }
            else curr_sum+=1;
            if(curr_sum==0){
                ans = max(ans,i+1);
                continue;
            }
            if(first_occ.find(curr_sum)!=first_occ.end()){
                ans = max(ans,i-first_occ[curr_sum]);
            }
            else{
                first_occ[curr_sum] = i;
            }
        }
        
        
        
        return ans;
    }
};
