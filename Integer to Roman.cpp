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
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.



*/











class Solution {
public:
    
    
    string getNext(int& curr,vector<pair<string,int>>& mapper){
        int i = 0;
        for(;i<mapper.size();i++){
            if(mapper[i].second<=curr) break;
        }
        curr = curr-mapper[i].second;
        return mapper[i].first;
    }
    
    
    string intToRoman(int num) {
        vector<pair<string,int>> mapper;
        string ans = "";
        mapper.push_back({"I",1});
        mapper.push_back({"IV",4});
        mapper.push_back({"V",5});
        mapper.push_back({"IX",9});
        mapper.push_back({"X",10});
        mapper.push_back({"XL",40});
        mapper.push_back({"L",50});
        
        
        
        mapper.push_back({"XC",90});
        mapper.push_back({"C",100});
        mapper.push_back({"CD",400});
        mapper.push_back({"D",500});
        mapper.push_back({"CM",900});
        mapper.push_back({"M",1000});
        reverse(mapper.begin(),mapper.end());
        int curr = num;
        while(curr!=0){
            string newPart = getNext(curr,mapper);
            ans+=newPart;
        }
        return ans;
        
        
    }
};
