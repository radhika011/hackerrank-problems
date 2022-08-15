/*

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.






*/







class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char,int> mapper;
        int ans = 0;
        mapper['I'] = 1;
        mapper['V'] =5;
        mapper['X'] = 10;
        mapper['L'] = 50;
        mapper['C'] = 100;
        mapper['D'] = 500;
        mapper['M']  = 1000;
        for(int i =0;i<n;i++){
            char curr = s[i];
            if(curr=='I'){
                if((i+1)<n&&s[i+1]=='V'){
                    ans+=4;
                    i++;
                }
                 else if((i+1)<n&&s[i+1]=='X'){
                    ans+=9;
                     i++;
                }
                else ans+=1;
            }
            else if(curr=='X'){
                if((i+1)<n&&s[i+1]=='L'){
                    ans+=40;
                    i++;
                }
                else if((i+1)<n&&s[i+1]=='C'){
                    ans+=90;
                    i++;
                }
                else ans+=10;
                
            }
            else if(curr=='C'){
                if((i+1)<n&&s[i+1]=='D'){
                    ans+=400;
                    i++;
                }
                else if((i+1)<n&&s[i+1]=='M'){
                    ans+=900;
                    i++;
                }
                else ans+=100;
            }
            else{
                ans+=mapper[curr];
            }
            
        }
        return ans;
    }
};
