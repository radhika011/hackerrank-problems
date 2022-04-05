/*
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.





*/






class TrieNode{
  public:
    vector<TrieNode*> children;
    priority_queue<string,vector<string>,greater<string>> sug;
    TrieNode(){
        for(int i =0;i<26;i++){
            children.push_back(NULL);
        }
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insertInto(string s){
        TrieNode* curr = root;
        for(int i =0;i<s.size();i++){
            int index = s[i]-'a';
             curr->sug.push(s);
            if(curr->children[index]==NULL){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->sug.push(s);
    }
   
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        int n = products.size();
        Trie* nt = new Trie();
        for(int i =0;i<n;i++){
            nt->insertInto(products[i]);
        }
        TrieNode* curr = nt->root;
        int i =0;
        for(;i<searchWord.size();i++){
            char ch = searchWord[i];
            curr = curr->children[ch-'a'];
            if(curr==NULL) break;
            vector<string> currVec;
            int done = 1;
            while(done<=3&&curr->sug.size()!=0){
                string popped = curr->sug.top();
                currVec.push_back(popped);
                curr->sug.pop();
                done++;
            }
            ans.push_back(currVec);
        }
        while(i<searchWord.size()){
            vector<string> curr;
            ans.push_back(curr);
            i++;
        }
        
        return ans;
    }
};
