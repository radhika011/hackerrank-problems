/*

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.




*/







class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        vector<string> ans;
        for(int i =0;i<n;i++){
            string word = words[i];
            unordered_map<char,char> mapping;
            unordered_map<char,char> mapping2;
            bool flag = true;
            for(int j = 0;j<pattern.size();j++){
                if(mapping.find(word[j])!=mapping.end()||mapping2.find(pattern[j])!=mapping2.end()){
                    if(pattern[j]!=mapping[word[j]]||word[j]!=mapping2[pattern[j]]){
                        //cout<<word<<endl;
                        //cout<<pattern[j]<<" "<<word[j]<<endl;
                        flag = false;
                        break;
                    }
                    continue;
                }
                mapping[word[j]] = pattern[j];
                mapping2[pattern[j]] = word[j];
            }
            if(flag) ans.push_back(word);
            
        }
        return ans;
    }
};
