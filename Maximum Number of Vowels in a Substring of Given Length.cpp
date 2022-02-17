/*

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.



*/





class Solution {
public:
    vector<char> vowels = {'a','e','i','o','u'};
    
    int check(vector<int> counts){
        int sum = 0;
        for(int i = 0;i<vowels.size();i++){
            sum+=counts[(int)vowels[i]];
        }
        return sum;
        
    }
    
    
    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> counts(128,0);
        int start = 0;
        int ans = 0;
        int end = k-1;
        for(int i = 0;i<k-1;i++){
            counts[(int)s[i]]++;
        }
        while(end<n){
            counts[(int)s[end]]++;
            int curr = check(counts);
            ans = max(ans,curr);
            //cout<<curr<<" "<<s.substr(start,k)<<endl;
            counts[(int)s[start]]--;
            start++;
            end++;
        }
        return ans;
        
    }
};
