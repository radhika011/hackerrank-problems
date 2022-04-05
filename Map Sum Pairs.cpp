/*

Design a map that allows you to do the following:

Maps a string key to a given value.
Returns the sum of the values that have a key with a prefix equal to a given string.
Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.


*/




class TrieNode{
    public:
    vector<TrieNode*> children;
    int sum;
    TrieNode(){
        for(int i =0;i<26;i++){
            children.push_back(NULL);
        }
        sum = 0;
    }
};
class Trie{
    public:
     unordered_map<string,int> map;
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string s,int val){
        int oldVal = 0;
        if(map.find(s)!=map.end()){
            oldVal = map[s];
        }
        TrieNode* curr = root;
       // int ans = 0;
        for(int i =0;i<s.size();i++){
            int index = s[i]-'a';
            if(curr->children[index]==NULL){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->sum+=val;
            curr->sum-=oldVal;
            
        }
        map[s] = val;
        //return curr->sum;
        
    }
    int search(string prefix){
        TrieNode* curr = root;
        for(int i =0;i<prefix.size();i++){
            int index = prefix[i]-'a';
            curr = curr->children[index];
            if(curr==NULL) return 0;
        }
        return curr->sum;
    }
};




class MapSum {
public:
    Trie* nt;
   
    MapSum() {
        nt = new Trie();
    }
    
    void insert(string key, int val) {
        
        nt->insert(key,val);
    }
    
    int sum(string prefix) {
        return nt->search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
