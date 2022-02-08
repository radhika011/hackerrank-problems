
/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.


*/



class Solution {
public:
    int addDigits(int num) {
        string digits = to_string(num);
        while(digits.size()!=1){
            int currSum = 0;
            string temp = "";
            for(int i = 0;i<digits.size();i++){
                int curr = digits[i]-'0';
                currSum+=curr;
            }
            digits = to_string(currSum);
        }
        return stoi(digits);
    }
};
//Pattern
class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        if(num%9==0) return 9;
        return num%9;
    }
};
