/*

Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.



*/






typedef long long ll;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        ll ans = 0;
        ll start = 1;
        for(int ind = columnTitle.size()-1;ind>=0;ind--){
            int curr = (int)columnTitle[ind]-64;
            //cout<<curr<<endl;
            ans+=(start*curr);
            start*=26;
        }
        return ans;
    }
};
