/*

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        vector<int> phash(26,0);
        
        vector<int> ans;
        if(n>s.size()) return ans;
        for(int i =0;i<n;i++){
            int curr = p[i]-97;
            //cout<<curr<<endl;
            phash[curr] += 1;
        }
        vector<int> hash(26,0);
        for(int i = 0;i<n;i++){
            int curr = s[i]-97;
            hash[curr] += 1;
        }
        if(phash==hash) ans.push_back(0);
        int start = 1;
        int end = n;
        hash[(int)s[0]-97] -= 1;
      while(end<s.size()){
           int endChar = s[end]-97;
            hash[endChar]+=1;
          
            if(phash==hash){
                ans.push_back(start);
            }
          
          
            int startChar = s[start]-97;
          hash[startChar]-=1;
           start++;
          end++;
        }
        return ans;
    }
};
