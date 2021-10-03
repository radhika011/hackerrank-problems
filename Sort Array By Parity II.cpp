class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2!=0){
                odd.push_back(nums[i]);
                continue;
            }
            even.push_back(nums[i]);
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        for(int k=0;k<nums.size();k++){
            if(k%2==0){
                ans.push_back(even[j++]);
                continue;
            }
            ans.push_back(odd[i++]);
        }
        return ans;
    }
};
