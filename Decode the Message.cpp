/*

You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
Align the substitution table with the regular English alphabet.
Each letter in message is then substituted using the table.
Spaces ' ' are transformed to themselves.
For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
Return the decoded message.






*/





class Solution {
public:
    string decodeMessage(string key, string message) {
        int start = 97;
        unordered_map<char,int> mapping;
        for(int i =0;i<key.size();i++){
            if(key[i]==' ') continue;
            if(mapping.find(key[i])!=mapping.end()) continue;
            mapping[key[i]] = start;
            start++;
        }
        string ans;
        for(int i =0;i<message.size();i++){
            if(message[i]==' '){
                ans.push_back(' ');
                continue;
            }
            ans.push_back(mapping[message[i]]);
        }
        return ans;
    }
};
