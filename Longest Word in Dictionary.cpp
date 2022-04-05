/*

Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.


*/





class TrieNode{
    public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode(){
        for(int i =0;i<26;i++){
            children.push_back(NULL);
        }
        isEnd = false;
    }
    
};

class Trie{
    public:
    TrieNode* root;
    int maxLen;
    string maxString;
    Trie(){
        root = new TrieNode();
        root->isEnd = true;
        maxLen = 0;
        maxString = "";
    }
    void insert(string s){
        bool isValid = true;
        TrieNode* curr = root;
        for(int i =0;i<s.size();i++){
            int index = s[i]-'a';
            if(curr->isEnd==false) isValid = false; 
            if(curr->children[index]==NULL){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
           
        }
        curr->isEnd = true;
        if(isValid){
           // cout<<"here"<<endl;
            if(maxLen<s.size()){
                maxLen = s.size();
                maxString = s;
            }
        } 
    }
    
    
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        Trie* nt = new Trie();
        sort(words.begin(),words.end());
        for(int i =0;i<n;i++){
            nt->insert(words[i]);
        }
        return nt->maxString;
    }
};
