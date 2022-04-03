/*

You are given a character array keys containing unique characters and a string array values containing strings of length 2. You are also given another string array dictionary that contains all permitted original strings after decryption. You should implement a data structure that can encrypt or decrypt a 0-indexed string.

A string is encrypted with the following process:

For each character c in the string, we find the index i satisfying keys[i] == c in keys.
Replace c with values[i] in the string.
A string is decrypted with the following process:

For each substring s of length 2 occurring at an even index in the string, we find an i such that values[i] == s. If there are multiple valid i, we choose any one of them. This means a string could have multiple possible strings it can decrypt to.
Replace s with keys[i] in the string.
Implement the Encrypter class:

Encrypter(char[] keys, String[] values, String[] dictionary) Initializes the Encrypter class with keys, values, and dictionary.
String encrypt(String word1) Encrypts word1 with the encryption process described above and returns the encrypted string.
int decrypt(String word2) Returns the number of possible strings word2 could decrypt to that also appear in dictionary.
 
 PLEASE TRY TO LEARN TRIE (PUN INTENDED) FFS


*/



class Encrypter {
public:
    unordered_map<char,int> key;
    unordered_map<string,vector<char>> value;
    unordered_map<string,int> fin;
    vector<string> values;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0;i<keys.size();i++){
            key[keys[i]] = i;
           // cout<<key[keys[i]]<<endl;
        }
        this->values= values;
        for(int i =0;i<values.size();i++){
            this->value[values[i]].push_back(keys[i]);
        }
        
        
        
        for(int i =0;i<dictionary.size();i++){
            string s = encrypt(dictionary[i]);
            fin[s]++;
        }
        
    }
    
    string encrypt(string word1) {
        string ans ="";
        for(int i =0;i<word1.size();i++){
            char curr = word1[i];
            ans+=values[key[curr]];
            
        }
        
        return  ans;
    }
    
    int decrypt(string word2) {
       if(fin.find(word2)==fin.end()) return 0;
        return fin[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
