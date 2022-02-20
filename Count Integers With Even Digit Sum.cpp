/*
Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.



*/





class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for(int i = 2;i<=num;i++){
            //cout<<"what"<<endl;
            string digit = to_string(i);
            int sum = 0;
            for(int j=0;j<digit.size();j++){
                int curr = digit[j]-'0';
                sum+=curr;
            }
            if(sum%2==0) ans++;
        }
        return ans;
    }
};
