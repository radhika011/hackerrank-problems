class Solution {
public:
    int getMaximumGenerated(int n) {
        int nums[n+1];
        nums[0] = 0;
        if(n==0) return nums[0];
        
        nums[1] = 1;
        for(int i =2;i<=n;i++){
            if(i%2==0){
                nums[i] = nums[i/2];
            }
            else{
                nums[i] = nums[(i-1)/2]+nums[(i+1)/2];
            }
        }
        int max = INT_MIN;
        for(int i =0;i<=n;i++){
            if(max<nums[i]) max = nums[i];
        }
        return max;
    } 
};
