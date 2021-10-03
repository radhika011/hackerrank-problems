class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> canJump(n,false);
        canJump[0] = true;
        for(int i = 0;i<n-1;i++){
            if(canJump[i]){
            int max = nums[i];
            int k = i;
            for(int j = 0;j<max&&k<n;j++){
                canJump[++k] = true;
            }
            }
            
        }
        return canJump[n-1];
        
    }
};
