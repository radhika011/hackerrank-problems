/*
Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.





*/






class TrieNode{
    public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode(){
        for(int i = 0;i<27;i++){
            children.push_back(NULL);
        }
        isEnd = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    bool insert(string s){
        TrieNode* curr = root;
        bool isSub = false;
        for(int i =1;i<s.size();i++){
            char ch = s[i];
            int index = -1;
            if(ch=='/'){
                index = 26;
            }
            else index = ch-'a';
            if(curr->children[index]==NULL){
                curr->children[index] = new TrieNode();
            }
            
            curr = curr->children[index];
            if(curr->isEnd==true&&s[i+1]=='/'){
                isSub = true;
                return isSub;
            }
        }
        curr->isEnd = true;
        return isSub;
    }
};



class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());
        vector<string> ans;
        Trie* newTrie = new Trie();
        for(int i=0;i<folder.size();i++){
            if(!newTrie->insert(folder[i])) ans.push_back(folder[i]);
        }
        
        return ans;
    }
};
