
/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.





*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> umap;
        int n = strs.size();
        for(int i =0;i<n;i++){
            string curr = strs[i];
            string sorted = curr;
            sort(sorted.begin(),sorted.end());
            umap[sorted].push_back(curr);
            
        }
        for(auto it = umap.begin();it!=umap.end();it++){
            vector<string> curr = (*it).second;
            ans.push_back(curr);
        }
        return ans;
     }
};
