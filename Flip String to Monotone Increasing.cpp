


/*
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.






*/


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int sumUpto = 0;
        for(int i = 0;i<n;i++){
            sumUpto+=(s[i]-'0');
        }
        int temp = sumUpto;
        for(int i = 0;i<n;i++){
            sumUpto-=(s[i]-'0');
            prefix[i] = sumUpto;
            //cout<<prefix[i]<<" ";
        }
        sumUpto = temp;
        //cout<<endl;
        for(int i = n-1;i>=0;i--){
            sumUpto-=(s[i]-'0');
            suffix[i] = sumUpto;
            //cout<<suffix[i]<<" ";
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            int curr = n-(i+1)-prefix[i]+suffix[i];
            ans = min(ans,curr);
        }
        
      return ans;  
    }
};
