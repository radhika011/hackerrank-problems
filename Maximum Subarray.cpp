//Brute Force Approach: O(n^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max =INT_MIN;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j =i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>max){
                    max = sum;
                }
            }
            
        }
        return max;
        
    }
};
//Efficient Approach (Kadane's Algo): O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum = nums[0];
        int osum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(csum+nums[i]>nums[i]){
                csum+=nums[i];
            }
            else{
                csum = nums[i];
            }
            if(csum>osum){
                osum = csum;
            }
        }
        
        return osum;
    }
};
