/*
You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.




*/



class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        unordered_map<int,int> counts;
        for(int i =0;i<n;i++){
            counts[(int)s[i]]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto it= counts.begin();it!=counts.end();it++){
            q.push({it->first,it->second});
        }
        string ans = "";
        while(q.size()!=0){
            int currChar = q.top().first;
            int freq = q.top().second;
            q.pop();
            if(q.size()==0){
               for(int i = 0;i<min(freq,repeatLimit);i++){
                   ans+=(char)currChar;
               }
               break;
            }
            else{
                int rem = min(freq,repeatLimit);
                for(int i = 0;i<rem;i++){
                    ans+=(char)currChar;
                }
                if(rem==freq) continue;
                 int currChar2 = q.top().first;
                 int freq2 = q.top().second;
                 q.pop();
                ans+=(char)currChar2;
                freq2--;
                if(freq2!=0) q.push({currChar2,freq2});
                q.push({currChar,freq-repeatLimit});
            }
            
            
        }
        return ans;
    }
};
