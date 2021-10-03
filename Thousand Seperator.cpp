class Solution {
public:
    string thousandSeparator(int n) {
        int temp = n;
        string ans;
        int count = 3;
        if(n==0) return "0";
        while(temp!=0){
            if(count==0){
                ans.push_back('.');
                count = 3;
            }
            int rem = temp%10;
            ans.append(to_string(rem));
            count--;
            temp = temp/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
