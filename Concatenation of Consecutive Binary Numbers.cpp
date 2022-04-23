/*


Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

*/







typedef long long ll;
class Solution {
public:
    int mod = pow(10,9)+7;
    
    string convert(int i){
        string ans = "";
        int rem = i;
        while(rem!=0){
            int curr = rem%2;
            rem/=2;
            ans+=(curr+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int concatenatedBinary(int n) {
        string fin = "";
        for(int i =1;i<=n;i++){
            string str = convert(i);
            fin+=str;
        }
        ll ans = 0;
        ll mul = 1;
        reverse(fin.begin(),fin.end());
        for(int i = 0;i<fin.size();i++){
            int curr = fin[i]-'0';
            ans+=(mul*curr);
            mul = (mul*2)%mod;
        }
        return ans%mod;
    }
};
