class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int> s1;
        unordered_map<char,int> s2;
        int m = word1.size();
        int n = word2.size();
        for(int i =0;i<m;i++){
            s1[word1[i]]++;
        }
        for(int j = 0;j<n;j++){
            s2[word2[j]]++;
        }
        for(int i = 0 ;i<m;i++){
            int second_freq = 0;
            if(s2.find(word1[i])!=s2.end()){
                second_freq = s2[word1[i]];
            }
            int diff = abs(s1[word1[i]]-second_freq);
            if(diff>3) return false;
        }
        for(int i = 0 ;i<n;i++){
            int second_freq = 0;
            if(s1.find(word2[i])!=s1.end()){
                second_freq = s1[word2[i]];
            }
            int diff = abs(s2[word2[i]]-second_freq);
            if(diff>3) return false;
        }
        return true;
        
        
    }
};
