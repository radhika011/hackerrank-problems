//O(n) approach: Two pointers
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            int is = nums[i]*nums[i];
            int js = nums[j]*nums[j];
            if(is>js){
                ans.push_back(is);
                i++;
            }
            if(js>is){
                ans.push_back(js);
                j--;
            }
            if(js==is){
                ans.push_back(is);
                if(i!=j) ans.push_back(js);
                i++;
                j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
