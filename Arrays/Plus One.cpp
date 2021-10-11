class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int carry = 0;
        int start = digits[n-1]+1;
        carry = start/10;
        int rem = start%10;
        ans.push_back(rem);
        for(int i = n-2;i>=0;i--){
            int curr = carry+digits[i];
            carry = curr/10;
            rem = curr%10;
            ans.push_back(rem);
        }
        if(carry!=0) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
