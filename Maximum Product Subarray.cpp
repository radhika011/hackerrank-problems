//Brute Force Solution: O(n^2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            int curr = 1;
            for(int j = i;j < nums.size();j++){
                curr*=nums[j];
                if(curr>max){
                    max = curr;
                }
            }
        }
        return max;
   
    }
};
//Efficient Solution : 
