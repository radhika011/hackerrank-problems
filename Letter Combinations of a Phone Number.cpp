/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

*/
class Solution {
public:
    vector<string> ans;
    unordered_map<int,vector<char>> umap;
    Solution(){
        ans.clear();
        umap.insert({2,{'a','b','c'}});
        umap.insert({3,{'d','e','f'}});
        umap.insert({4,{'g','h','i'}});
        umap.insert({5,{'j','k','l'}});
        umap.insert({6,{'m','n','o'}});
        umap.insert({7,{'p','q','r','s'}});
        umap.insert({8,{'t','u','v'}});
        umap.insert({9,{'w','x','y','z'}});
        
    }
    
    void helper(int curr,string& digits,string currString){
        if(curr==digits.size()){
            ans.push_back(currString);
            return;
        }
        int currDigit = digits[curr]-'0';
        vector<char> possible = umap[currDigit];
        for(int i = 0;i<possible.size();i++){
            string temp = currString+possible[i];
            
            helper(curr+1,digits,temp);
        }
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0) return ans;
        helper(0,digits,"");
        return ans;
    }
};
