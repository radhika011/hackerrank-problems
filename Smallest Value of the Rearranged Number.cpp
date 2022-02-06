
/*

You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.

Return the rearranged number with minimal value.

Note that the sign of the number does not change after rearranging the digits.


*/


typedef long long ll;
class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> digits;
        ll temp = num;
        string counter = to_string(num);
        int n = counter.size();
        for(int i = 0;i<n;i++){
            if(counter[i]=='-') continue;
            digits.push_back(counter[i]-'0');
        }
        if(num<0) n--;
        string ans = "";
        if(num>=0){
            sort(digits.begin(),digits.end());
            int zeros = 0;
            string curr = "";
            for(int i = 0;i<digits.size();i++){
                if(digits[i]==0) zeros++;
                else curr+=to_string(digits[i]);
            }
            if(curr.size()>0) ans+=curr[0];
            for(int i  =0;i<zeros;i++){
                ans+=to_string(0);
            }
            if(curr.size()>1) ans+=curr.substr(1,digits.size()-1);            
        }
        else{
            string curr = "";
            sort(digits.begin(),digits.end(),greater<int>());
            for(int i = 0;i<n;i++){
                curr+=to_string(digits[i]);
            }
            ans = "-"+curr;
            
        }
        ll done = stoll(ans);
       
        
        return done;
    }
};
