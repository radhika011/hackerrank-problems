/*
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.





*/




class Solution {
public:
    string pattern;
    
    int n;
   
   
    
    
    
    
    string smallestNumber(string pattern) {
        this->n = pattern.size();
        this->pattern = pattern;
        vector<int> parts(n+1,0);
        for(int i =0;i<=n;i++){
            parts[i] = i+1;
        }
        for(int i = 1;i<=n;){
            char curr = pattern[i-1];
            if(curr=='D'){
                int j = i;
                while(pattern[j]!='I'&&j<n){
                    j++;
                }
                //cout<<(i-1)<<" "<<j<<endl;
                reverse(parts.begin()+i-1,parts.begin()+j+1);
                i = j+1;
            }
            else{
                i++;
            }
            
        }
        string ans = "";
        for(int i =0;i<=n;i++){
            ans+=to_string(parts[i]);
        }
        return ans;
    }
};
