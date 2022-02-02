
/*
You are given a string num, which represents a large integer. You are also given a 0-indexed integer array change of length 10 that maps each digit 0-9 to another digit. More formally, digit d maps to digit change[d].

You may choose to mutate a single substring of num. To mutate a substring, replace each digit num[i] with the digit it maps to in change (i.e. replace num[i] with change[num[i]]).

Return a string representing the largest possible integer after mutating (or choosing not to) a single substring of num.

A substring is a contiguous sequence of characters within the string.



*/


class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        string ans = "";
        int i =0;
        for(;i<n;i++){
            int curr = num[i]-'0';
            int changer = change[curr];
            if(changer>curr){
                break;
            }
            ans+=to_string(curr);
        }
        for(;i<n;i++){
             int curr = num[i]-'0';
            int changer = change[curr];
            if(curr>changer){
                break;
            }
            ans+=to_string(changer);
        }
        for(;i<n;i++){
            int curr = num[i]-'0';
            ans+=to_string(curr);
        }
        
        return ans;
    }
};
