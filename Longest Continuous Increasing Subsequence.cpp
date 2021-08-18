//Kadane's Algo
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int clen = 1;
        int olen = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]){
                clen = 1;
            }
            else{
                clen +=1;
            }
            if(clen>olen){
                olen = clen;
            }
        }
        return olen;
        
    }
};
//Sliding Window
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int anchor = 0;
        int ans = 1;
        for(int i=1;i<nums.size();i++){
           if(nums[i-1]>=nums[i]){
               anchor = i;
           }
            else{
                ans = max(ans,i - anchor+1);
            }
        }
        return ans;
        
    }
};
