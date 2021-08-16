class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            int total =0;
            for(int j=0;j<nums.size();j++){
                if(j!=i&&nums[j]<nums[i]){
                    total++;
                }
            }
            ans.push_back(total);
        }
        return ans;
    }
};
